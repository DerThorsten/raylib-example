#!/bin/bash

set -e

mkdir -p build
pushd build
cmake .. \
    -DCMAKE_BUILD_TYPE=Release 
make -j4
popd

mkdir -p build_emscripten
pushd build_emscripten
unset LDFLAGS
unset LDFLAGS_U
emcmake cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DPLATFORM=Web

emmake make -j4
popd


cd build/raylib-game-template
./raylib-game-template