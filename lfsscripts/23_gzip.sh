#!/bin/sh

cd ../${gzip["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
