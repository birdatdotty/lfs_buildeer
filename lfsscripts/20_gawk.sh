#!/bin/sh

#cd ../${gettext["dir"]}
echo $PWD
../${gawk["dir"]}/configure --prefix=$TOOLS
make
#make check
make install
