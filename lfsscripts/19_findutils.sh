#!/bin/sh

cd ../${findutils["dir"]}
./configure --prefix=$TOOLS

T make
T make check
T make install
