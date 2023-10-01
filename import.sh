#!/bin/sh -e

root=$(pwd)

echo "#define VERSION_BUILD 0" > src/build_version.h
echo "#define COMMIT_SHA \"\"" >> src/build_version.h
echo "#define BRANCH_NAME \"\"" >> src/build_version.h

cd ${root}/halley/bin
./halley-cmd import ${root} ${root}/halley/
#./halley-cmd write_version ${root}/bin/



# "${root}/halley/bin/halley-cmd" import "/halley" "/halley"
# "${root}/halley/bin/halley-cmd" import "${root}" "${root}"