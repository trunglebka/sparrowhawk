#!/usr/bin/env bash
export PATH="/usr/bin:$PATH"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "$SCRIPT_DIR" || exit 1
PROTOC="/usr/bin/protoc" ./configure --enable-shared=no \
    --enable-static=yes \
    CPPFLAGS="-DFST_NO_DYNAMIC_LINKING -I/opt/FST/thrax/include -I/opt/FST/openfst/include" \
    shell_LDFLAGS="-all-static" \
    LDFLAGS="-L/opt/FST/thrax/lib -L/opt/FST/openfst/lib" \
    --prefix=/media/WORKSPACE/workspace/github/sparrowhawk/dist
