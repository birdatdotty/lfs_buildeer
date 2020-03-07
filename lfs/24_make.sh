#!/bin/sh

cd ../${make["dir"]}
./configure --prefix=$TOOLS

T /usr/bin/make
T /usr/bin/make check
T /usr/bin/make install
