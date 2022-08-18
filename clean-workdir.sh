#!/usr/bin/env bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "$SCRIPT_DIR" || exit 1

make distclean
rm src/include/sparrowhawk/*.pb.cc
rm src/lib/*.pb.cc