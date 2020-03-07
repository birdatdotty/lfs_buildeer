#!/bin/sh
#TOOLS=/tools
#LFS=/mnt/lfs
#LFS_TGT=x86_64-lfs-linux-gnu
#PATH=$TOOLS/bin:/bin:/usr/bin

#set +h
#umask 022
#LC_ALL=POSIX
#export LFS LC_ALL LFS_TGT PATH

echo `pwd`
cd ../${binutils["dir"]}

/bin/rm -rf build
mkdir build && cd build

CC=$LFS_TGT-gcc               \
AR=$LFS_TGT-ar                  \
RANLIB=$LFS_TGT-ranlib          \
../configure \
    --prefix=$TOOLS             \
    --disable-nls               \
    --disable-werror            \
    --with-lib-path=$TOOLS/lib  \
    --with-sysroot

T make
T make install

T make -C ld clean
T make -C ld LIB_PATH=/usr/lib:/lib
T cp -v ld/ld-new $TOOLS/bin
