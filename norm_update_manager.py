import os
import re
import shutil
from typing import Dict, Generator, List, Set, Tuple
import tempfile
import pynini
import norm_rule_finetuning
from norm_rule_finetuning import load_whitelist_file
import norm_config
from pydantic import BaseModel


def create_updated_case_sensitive_whitelist(
    words_to_update: Dict[str, str],
    whitelist_file: str,
    out_file: str,
) -> "pynini.FstLike":
    word_dict = words_to_update

    fw = open(out_file, "w", encoding="UTF-8")
    wrote_words = set()
    for word_ori, word_repl in load_whitelist_file(whitelist_file):
        word_ori_check = word_ori
        if word_ori_check in word_dict:
            word_repl = word_dict[word_ori_check]
            wrote_words.add(word_ori_check)
        fw.write(f"{word_ori_check}\t{word_repl}\n")
    for w_ori, w_repl in word_dict.items():
        if w_ori not in wrote_words:
            fw.write(f"{w_ori}\t{w_repl}\n")
    fw.close()


def create_updated_case_insensitive_whitelist(
    words_to_update: Dict[str, str],
    whitelist_file: str,
    out_file: str,
) -> "pynini.FstLike":
    # make "word" in case insensitive dict lower
    word_dict = {}
    for w_ori, w_repl in words_to_update.items():
        word_dict[w_ori.lower()] = w_repl
    fw = open(out_file, "w", encoding="UTF-8")
    wrote_words = set()
    for word_ori, word_repl in load_whitelist_file(whitelist_file):
        word_ori_check = word_ori.lower()
        if word_ori_check in word_dict:
            word_repl = word_dict[word_ori_check]
            wrote_words.add(word_ori_check)
        fw.write(f"{word_ori_check}\t{word_repl}\n")
    for w_ori, w_repl in word_dict.items():
        if w_ori not in wrote_words:
            fw.write(f"{w_ori}\t{w_repl}\n")
    fw.close()


def create_words_removed_whitelist(
    words_tobe_removed: Set[str],
    whitelist_file: str,
    case_sensitive: bool,
    out_file: str,
):
    if case_sensitive:
        word_set = words_tobe_removed
    else:
        # make "word" in case insensitive dict lower
        word_set = set()
        for w in words_tobe_removed:
            word_set.add(w.lower())
    fw = open(out_file, "w", encoding="UTF-8")
    for word_ori, word_repl in load_whitelist_file(whitelist_file):
        word_check = word_ori if case_sensitive else word_ori.lower()
        if word_check not in word_set:
            fw.write(f"{word_ori}\t{word_repl}\n")
    fw.close()


def handle_update_command(words_to_update: Dict[str, str], case_sensitive: bool):
    tmp_whitelist_filename = f"tts-norm-whitelist-{'case_sensitive' if case_sensitive else 'case_insensitive'}.tmp"
    tmp_whitelist_file = os.path.join(tempfile.tempdir, tmp_whitelist_filename)
    case_sensitive_whitelist_file = None
    case_insensitive_whitelist_file = None

    if case_sensitive:
        case_sensitive_whitelist_file = norm_config.CASE_SENSITIVE_WHITELIST_FILE
        create_updated_case_sensitive_whitelist(
            words_to_update,
            case_sensitive_whitelist_file,
            out_file=tmp_whitelist_file,
        )
    else:
        case_insensitive_whitelist_file = norm_config.CASE_INSENSITIVE_WHITELIST_FILE
        create_updated_case_insensitive_whitelist(
            words_to_update,
            case_insensitive_whitelist_file,
            out_file=tmp_whitelist_file,
        )

    ori_far_file = norm_config.NORM_MODEL_ORIGIN
    ori_far_filename = os.path.split(ori_far_file)[-1]
    tmp_far_file = os.path.join(tempfile.tempdir, f"tts-norm-{ori_far_filename}.tmp")
    norm_rule_finetuning.apply_whitelist_files(
        ori_far_file,
        case_sensitive_whitelist_file=case_sensitive_whitelist_file,
        case_insensitive_whitelist_file=case_insensitive_whitelist_file,
        out_far_file=tmp_far_file,
    )


def handle_remove_command(words_tobe_removed: Set[str], case_sensitive: bool):
    tmp_whitelist_filename = f"tts-norm-whitelist-{'case_sensitive' if case_sensitive else 'case_insensitive'}.tmp"
    tmp_whitelist_file = os.path.join(tempfile.tempdir, tmp_whitelist_filename)
    case_sensitive_whitelist_file = None
    case_insensitive_whitelist_file = None

    if case_sensitive:
        case_sensitive_whitelist_file = norm_config.CASE_SENSITIVE_WHITELIST_FILE
        whitelist_file = case_sensitive_whitelist_file
    else:
        case_insensitive_whitelist_file = norm_config.CASE_INSENSITIVE_WHITELIST_FILE
        whitelist_file = case_insensitive_whitelist_file

    create_words_removed_whitelist(
        words_tobe_removed, whitelist_file, case_sensitive, tmp_whitelist_file
    )
    ori_far_file = norm_config.NORM_MODEL_ORIGIN
    ori_far_filename = os.path.split(ori_far_file)[-1]
    tmp_far_file = os.path.join(tempfile.tempdir, f"tts-norm-{ori_far_filename}.tmp")
    norm_rule_finetuning.apply_whitelist_files(
        ori_far_file,
        case_sensitive_whitelist_file=case_sensitive_whitelist_file,
        case_insensitive_whitelist_file=case_insensitive_whitelist_file,
        out_far_file=tmp_far_file,
    )


def apply_updated_norm_model(new_norm_model_file: str) -> None:
    shutil.move(new_norm_model_file, norm_config.NORM_MODEL_RUNNING)


def apply_whitelist(new_whitelist_file: str, case_sensitive: bool) -> None:
    if case_sensitive:
        ori_whitelist_file = norm_config.CASE_SENSITIVE_WHITELIST_FILE
    else:
        ori_whitelist_file = norm_config.CASE_INSENSITIVE_WHITELIST_FILE
    shutil.move(new_whitelist_file, ori_whitelist_file)
