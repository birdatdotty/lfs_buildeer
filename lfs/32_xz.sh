#!/bin/sh

cd ../${xz["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
