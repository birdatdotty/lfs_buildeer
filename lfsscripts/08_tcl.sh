#!/bin/sh

cd ../${tcl["dir"]}/unix
./configure --prefix=$TOOLS

T make
TZ=UTC make test
T make install
chmod -v u+w $TOOLS/lib/libtcl8.6.so

make install-private-headers
ln -sv tclsh8.6 $TOOLS/bin/tclsh
