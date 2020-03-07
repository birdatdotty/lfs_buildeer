#!/bin/sh

echo "PWD: $PWD"
echo "texinfo_dir:" ${texinfo["dir"]}
cd ../${texinfo["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
