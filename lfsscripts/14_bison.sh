#!/bin/sh

cd ../${bison["dir"]}
./configure --prefix=$TOOLS

T make
T make install
