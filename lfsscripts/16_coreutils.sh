#!/bin/sh

cd ../${coreutils["dir"]}
./configure --prefix=$TOOLS --enable-install-program=hostname

T make
T make RUN_EXPENSIVE_TESTS=yes check
T make install
