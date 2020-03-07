#!/bin/sh

cd ../${grep["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
