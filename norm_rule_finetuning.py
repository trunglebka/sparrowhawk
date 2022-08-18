import sys
from typing import Dict, Union
from unicodedata import category
import pynini
from pynini.lib import pynutil
from pynini.export import export

special_chars = list(";?(&_-:.)=+^{\*#<!,@>'\"/}`%|~")
for i in range(sys.maxunicode):
    if category(chr(i)).startswith("P") and chr(i) not in "[]":  # pynini not accept []
        special_chars.append(chr(i))
special_chars_graph = (
    pynutil.insert('name: "')
    + pynini.closure(pynini.union(*special_chars), 1)
    + pynutil.insert('"')
).optimize()

whitespace_graph = pynini.union(" ", "\n", "\t", "\u00A0", "\r").optimize()
del_extspace_graph = pynini.cross(pynini.closure(whitespace_graph, 1), " ")
del_space = pynutil.delete(pynini.closure(whitespace_graph))
GRAPH_NAME = "TOKENIZE_AND_CLASSIFY"


def load_far(far_file: str, rule=GRAPH_NAME) -> "pynini.FstLike":
    norm_graph = pynini.Far(far_file, mode="r")[rule]
    return norm_graph


def save_far(graph: "pynini.FstLike", out_far: str):
    exporter = export.Exporter(out_far)
    exporter[GRAPH_NAME] = graph.optimize()
    exporter.close()
    print(f"Created {out_far}")


def load_compile_whitelist(whitelist_file: str, delimiter="\t") -> "pynini.FstLike":
    whitelist_graph = pynini.string_file(whitelist_file)
    whitelist_graph = (
        pynutil.insert('name: "') + whitelist_graph + pynutil.insert('"')
    ).optimize()
    # maybe need convert_space here
    return whitelist_graph


def apply_whitelist_into_norm_graph(
    norm_graph: Union[str, "pynini.FstLike"],
    whitelist_graph: Union[str, "pynini.FstLike"],
) -> "pynini.FstLike":
    if isinstance(norm_graph, str):
        norm_graph = load_far(norm_graph)
    if isinstance(whitelist_graph, str):
        whitelist_graph = load_compile_whitelist(whitelist_graph)
    w_special_chars = (
        pynutil.insert("tokens { ")
        + pynutil.add_weight(special_chars_graph, weight=2.1)
        + pynutil.insert(" }")
    )
    w_special_chars = pynini.closure(
        pynini.compose(pynini.closure(whitespace_graph, 1), del_extspace_graph)
        | (pynutil.insert(" ") + w_special_chars),
        1,
    )
    w_whitelist_graph = pynutil.add_weight(whitelist_graph, 1.01)
    tagged_w_whitelist_graph = (
        pynutil.insert("tokens { ") + w_whitelist_graph + pynutil.insert(" }")
    )
    whitelist_and_special_chars = (
        pynini.closure(w_special_chars + pynutil.insert(" "))
        + tagged_w_whitelist_graph
        + pynini.closure(pynutil.insert(" ") + w_special_chars)
    )

    tmp_graph = whitelist_and_special_chars + pynini.closure(
        (
            pynini.compose(pynini.closure(whitespace_graph, 1), del_extspace_graph)
            | (pynutil.insert(" ") + w_special_chars + pynutil.insert(" "))
        )
        + whitelist_and_special_chars
    )

    tmp_graph = del_space + tmp_graph + del_space
    tmp_graph |= w_special_chars
    norm_graph |= tmp_graph
    return norm_graph.optimize()


if __name__ == "__main__":
    result_graph = apply_whitelist_into_norm_graph(
        "resources/en_grm/classify/tokenize_and_classify.far",
        "resources/cased_whitelist.tsv",
    )
    save_far(result_graph, "./output/tokenize_and_classify.far")
