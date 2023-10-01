#!/bin/sh -e

root=$(pwd)

#
# compiles
#
cmake --build . --target halley3d --config Debug -j 4
