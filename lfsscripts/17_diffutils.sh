#!/bin/sh

cd ../${diffutils["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
