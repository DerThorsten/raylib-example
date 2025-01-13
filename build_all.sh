#!/bin/bash

set -e

mkdir -p build
pushd build
cmake .. 
make -j4
popd

mkdir -p build_emscripten
pushd build_emscripten
emcmake cmake .. -DPLATFORM=Web
emmake make -j4
popd
