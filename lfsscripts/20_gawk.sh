#!/bin/sh

cd ../${gawk["dir"]}
./configure --prefix=$TOOLS
make
#make check
make install
