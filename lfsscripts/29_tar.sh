#!/bin/sh

cd ../${tar["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
