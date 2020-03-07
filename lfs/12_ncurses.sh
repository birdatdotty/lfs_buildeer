#!/bin/sh

cd ../${ncurses["dir"]}

sed -i s/mawk// configure

T ./configure --prefix=$TOOLS \
              --with-shared   \
              --without-debug \
              --without-ada   \
              --enable-widec  \
              --enable-overwrite

T make
T make install

ln -s libncursesw.so $TOOLS/lib/libncurses.so
