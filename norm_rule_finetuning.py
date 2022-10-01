import os
import re
import sys
from typing import Dict, Generator, List, Tuple, Union
from unicodedata import category
import uuid
import pynini
from pynini.lib import pynutil
from pynini.export import export
import tempfile
import logging


RE_MULTI_TABS = re.compile("\t+")


special_chars = list(""";?(&_-:.)=+^{\*#<!,@>'/}`%|~""")
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


def load_whitelist_file(whitelist_file: str) -> Generator[Tuple[str, str], None, None]:
    with open(whitelist_file, "r", encoding="UTf-8") as fr:
        for line in fr:
            parts = re.split(RE_MULTI_TABS, line.strip())
            word_ori = parts[0]
            if len(parts) == 1:
                word_repl = word_ori
            else:
                word_repl = parts[1]
            yield word_ori, word_repl


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


def generate_cased_variants_whitelist(
    white_list_file: str, out_file: str, delimiter="\t"
):
    fw = open(out_file, "w", encoding="UTF-8")
    for word, repl in load_whitelist_file(white_list_file):
        cased_word_variants = generate_word_popular_cased_variant(word)
        for c_word in cased_word_variants:
            fw.write(f"{c_word}{delimiter}{repl}\n")
    fw.close()


def generate_word_popular_cased_variant(word: str) -> List[str]:
    return list(set([word, word.lower(), word.capitalize(), word.upper()]))


def apply_whitelist_files(
    original_far_file: str,
    case_sensitive_whitelist_file: str,
    case_insensitive_whitelist_file: str,
    out_far_file: str,
) -> None:
    tmp_cased_variant_file = os.path.join(
        tempfile.gettempdir(), f"tts-norm-whitelist-case-generated-{uuid.uuid4()}.tsv"
    )
    processing_graph = load_far(original_far_file)
    is_modified = False
    if case_sensitive_whitelist_file and os.path.exists(case_sensitive_whitelist_file):
        processing_graph = apply_whitelist_into_norm_graph(
            processing_graph, case_sensitive_whitelist_file
        )
        is_modified = True
    if case_insensitive_whitelist_file and os.path.exists(
        case_insensitive_whitelist_file
    ):
        generate_cased_variants_whitelist(
            case_insensitive_whitelist_file, tmp_cased_variant_file
        )
        processing_graph = apply_whitelist_into_norm_graph(
            processing_graph, tmp_cased_variant_file
        ).optimize()
        os.remove(tmp_cased_variant_file)
        is_modified = True
    if is_modified:
        save_far(processing_graph, out_far=out_far_file)
    else:
        logging.info("Nothing to do")


if __name__ == "__main__":
    # result_graph = apply_whitelist_into_norm_graph(
    #     "resources/en_grm/classify/tokenize_and_classify.far",
    #     "resources/case_sensitive_whitelist.tsv",
    # )
    # save_far(result_graph, "./output/tokenize_and_classify.far")

    apply_whitelist_files(
        "resources/en_grm/classify/tokenize_and_classify.far",
        "resources/case_sensitive_whitelist.tsv",
        "resources/case_insensitive_whitelist.tsv",
        "./output/tokenize_and_classify.far",
    )
