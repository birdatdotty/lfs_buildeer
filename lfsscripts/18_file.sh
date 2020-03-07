#!/bin/sh

cd ../${file["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
