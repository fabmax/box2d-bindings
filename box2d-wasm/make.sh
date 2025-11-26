#!/bin/bash

cd /box2d-native/build-wasm

emmake make -j8

cp box2d-wasm.mjs /src/dist/
cp box2d-wasm.wasm /src/dist/
