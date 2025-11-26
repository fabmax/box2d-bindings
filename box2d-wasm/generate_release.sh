#!/bin/bash


mkdir -p /box2d-native/build-wasm
cd /box2d-native/build-wasm
rm -rf *

emcmake cmake .. -DCMAKE_BUILD_TYPE=Release
