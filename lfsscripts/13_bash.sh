#!/bin/sh

cd ../${bash["dir"]}
T ./configure --prefix=$TOOLS --without-bash-malloc
T make
T make install

ln -sv bash /tools/bin/sh
