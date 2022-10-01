import sys
import os
from pathlib import Path


def get_script_dir():
    return os.getcwd()


RESOURCES_DIR = os.path.join(get_script_dir, "resources")
NORM_MODEL_DIR = os.path.join(RESOURCES_DIR, "norm-models")
NORM_MODEL_ORIGIN = os.path.join(NORM_MODEL_DIR, "tokenize_and_classify-origin.far")
NORM_MODEL_RUNNING = os.path.join(NORM_MODEL_DIR, "tokenize_and_classify-running.far")
NORM_WHITELIST_DIR = os.path.join(RESOURCES_DIR, "norm-whitelist")
CASE_SENSITIVE_WHITELIST_FILE = os.path.join(
    NORM_WHITELIST_DIR, "case_sensitive_whitelist.tsv"
)
CASE_INSENSITIVE_WHITELIST_FILE = os.path.join(
    NORM_WHITELIST_DIR, "case_insensitive_whitelist.tsv"
)
