#!/bin/sh

cd ../${dejagnu["dir"]}
./configure --prefix=$TOOLS

T make install
