#!/bin/sh -e

root=$(pwd)

mkdir -p build

#
# generate CMake project
#
cd build
rm -f CMakeCache.txt

cmake -G "Xcode" \
  -DHALLEY_PATH="${root}/halley" \
  -DBUILD_HALLEY_TOOLS=1 \
  -DBUILD_HALLEY_TESTS=0 \
  -DBUILD_MACOSX_BUNDLE=1 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_STANDARD=17 \
  -DCMAKE_CXX_STANDARD_REQUIRED=ON \
  -DCMAKE_INCLUDE_PATH="${root}/lib/osx/include" \
  -DCMAKE_LIBRARY_PATH="${root}/lib/osx" \
  -DBoost_INCLUDE_DIR="${root}/halley/deps/Boost/include/boost-1_81" \
  -DBoost_USE_STATIC_LIBS=1 \
  -DUSE_METAL=1 \
   ..
