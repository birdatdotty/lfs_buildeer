#!/bin/sh

cd ../${sed["dir"]}
./configure --prefix=$TOOLS

T make
#T make check
T make install
