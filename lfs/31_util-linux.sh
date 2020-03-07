#!/bin/sh

cd ../${utilLinux["dir"]}
./configure --prefix=$TOOLS \
            --without-python               \
            --disable-makeinstall-chown    \
            --without-systemdsystemunitdir \
            --without-ncurses              \
            PKG_CONFIG=""

T make
T make check
T make install
