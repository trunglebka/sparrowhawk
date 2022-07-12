# Copyright (c) 2021, NVIDIA CORPORATION.  All rights reserved.
# Copyright 2015 and onwards Google, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Dockerfile for C++ (inverse) text normalization backend Sparrowhawk https://github.com/google/sparrowhawk

# set base image (host OS)
FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive 

# set the working directory in the container
WORKDIR /workspace

# install dependencies
RUN apt-get update -y && \
    apt-get install -y --reinstall build-essential git make wget autoconf cmake file

# gg re2
RUN git clone https://github.com/google/re2
RUN cd re2 && make -j && make install

# install openfst
ENV OPEN_FST_VER="1.8.2"
RUN wget "https://www.openfst.org/twiki/pub/FST/FstDownload/openfst-${OPEN_FST_VER}.tar.gz" && \
    tar -xzvf "openfst-${OPEN_FST_VER}.tar.gz" && \
    cd "openfst-${OPEN_FST_VER}" && \
    ./configure --enable-grm  --enable-fsts --enable-far --enable-static && \
    make -j && make install && \
    cd .. && rm -r "openfst-${OPEN_FST_VER}"
ENV LD_LIBRARY_PATH="/usr/lib64:/usr/local/lib:/usr/local/lib64:$LD_LIBRARY_PATH"

#install thrax
ENV THRAX_VER="1.3.8"
RUN wget "https://www.openfst.org/twiki/pub/GRM/ThraxDownload/thrax-${THRAX_VER}.tar.gz" && \
    tar -xzvf "thrax-${THRAX_VER}.tar.gz" && \
    cd "thrax-${THRAX_VER}" && \
    ./configure --enable-static && \
    make -j 16 && make install && \
    cd .. && rm -r "thrax-${THRAX_VER}"

# protobuf
ENV protobuf_ver=3.14.0
RUN wget https://github.com/protocolbuffers/protobuf/releases/download/v${protobuf_ver}/protobuf-all-${protobuf_ver}.tar.gz
RUN tar xzvf protobuf-all-${protobuf_ver}.tar.gz
RUN cd protobuf-${protobuf_ver} && ./configure && make -j && make install && ldconfig

#redis
RUN git clone https://github.com/redis/hiredis.git && \
    cd hiredis && \
    make && make install
RUN git clone https://github.com/sewenew/redis-plus-plus.git && \
    cd redis-plus-plus && \
    mkdir build && \
    cd build && \
    cmake -DREDIS_PLUS_PLUS_CXX_STANDARD=17 .. && \
    make && \
    make install

# sparrowhawk
ENV THRAX_INCLUDE_DIR='/opt/conda/include'
ENV LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib64"
RUN pwd
RUN git clone https://github.com/trunglebka/sparrowhawk.git /opt/sparrowhawk || pwd

RUN cd /opt/sparrowhawk && \
    bash autoreconf && \
    ./configure --enable-shared=no --enable-static=yes && \
    make -j && make install && ldconfig
RUN git clone https://github.com/kward/shunit2.git
RUN echo "DONE"
WORKDIR /opt/sparrowhawk/documentation/grammars