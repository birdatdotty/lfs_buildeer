#!/bin/sh

cd ../${expect["dir"]}
cp -v configure{,.orig}
sed 's:/usr/local/bin:/bin:' configure.orig > configure

T ./configure --prefix=$TOOLS       \
            --with-tcl=$TOOLS/lib \
            --with-tclinclude=$TOOLS/include


T make
T make test
T make SCRIPTS="" install
