#!/bin/sh

cd ../${bzip2["dir"]}
T make -f Makefile-libbz2_so
T make clean

T make

T make PREFIX=/tools install
cp -v bzip2-shared /tools/bin/bzip2
cp -av libbz2.so* /tools/lib
ln -sv libbz2.so.1.0 /tools/lib/libbz2.so
