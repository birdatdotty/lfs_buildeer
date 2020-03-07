#!/bin/sh

cd ../${perl["dir"]}
sh Configure -des -Dprefix=$TOOLS -Dlibs=-lm -Uloclibpth -Ulocincpth -Dcc="gcc"

T make
cp -v perl cpan/podlators/scripts/pod2man $TOOLS/bin
mkdir -pv $TOOLS/lib/perl5/${perl["version"]}
cp -Rv lib/* $TOOLS/lib/perl5/${perl["version"]}
