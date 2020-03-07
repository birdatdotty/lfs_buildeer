#!/bin/sh

cd ../${python["dir"]}
./configure --prefix=$TOOLS

T make
#T make install
