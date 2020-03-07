#!/bin/sh
cd ../${pkg["dir"]}
sh Configure -des -Dprefix=$TOOLS -Dlibs=-lm -Uloclibpth -Ulocincpth

make
cp -v perl cpan/podlators/scripts/pod2man $TOOLS/bin
mkdir -pv $TOOLS/lib/perl5/5.30.1
cp -Rv lib/* $TOOLS/lib/perl5/5.30.1
