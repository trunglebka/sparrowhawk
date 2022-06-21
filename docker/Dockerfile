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
FROM continuumio/miniconda3

# set the working directory in the container
WORKDIR /workspace

# install dependencies
RUN conda update -n base -c defaults conda -y
RUN conda install conda-build -y
RUN apt-get update && \
    apt-get install -y --reinstall build-essential && \
    apt-get upgrade -y && \
    apt-get install -y git make wget autoconf
# gg re2
RUN git clone https://github.com/google/re2
RUN cd re2 && make && make install
# install thrax, openfst and export include/lib
RUN conda install -c conda-forge thrax=1.3.8 -y
# protobuf
ENV protobuf_ver=3.14.0
# RUN apt-get update && apt-get install -y libprotobuf-dev protobuf-compiler
RUN wget https://github.com/protocolbuffers/protobuf/releases/download/v${protobuf_ver}/protobuf-all-${protobuf_ver}.tar.gz
RUN tar xzvf protobuf-all-${protobuf_ver}.tar.gz
RUN cd protobuf-${protobuf_ver} && ./configure && make -j && make install && ldconfig

#redis
RUN apt-get upgrade -y && \
    apt-get install -y cmake
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
ENV THRAX_LIB_DIR='/opt/conda/lib'
ENV LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${THRAX_LIB_DIR}:/usr/local/lib64"
RUN git clone https://github.com/trunglebka/sparrowhawk.git /opt/sparrowhawk
RUN cd /opt/sparrowhawk && \
    bash autoreconf && \
    ./configure CPPFLAGS="-I${THRAX_INCLUDE_DIR} -I/usr/local/include" LDFLAGS="-L${THRAX_LIB_DIR} -L/usr/local/lib  -L/usr/local/lib64" && \
    make && make install && ldconfig
RUN git clone https://github.com/kward/shunit2.git
RUN echo "DONE"
WORKDIR /opt/sparrowhawk/documentation/grammars