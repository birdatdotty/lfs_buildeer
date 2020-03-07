#!/bin/sh
#TOOLS=/tools
#LFS=/mnt/lfs
#LFS_TGT=x86_64-lfs-linux-gnu
#PATH=$TOOLS/bin:/bin:/usr/bin

#set +h
#umask 022
#LC_ALL=POSIX
#export LFS LC_ALL LFS_TGT PATH

cd ../${gcc["dir"]}

T /bin/rm -rf build
T mkdir build; cd $_
T ../libstdc++-v3/configure       \
  --host=$LFS_TGT                 \
  --prefix=$TOOLS                 \
  --disable-multilib              \
  --disable-nls                   \
  --disable-libstdcxx-threads     \
  --disable-libstdcxx-pch         \
  --with-gxx-include-dir=$TOOLS/$LFS_TGT/include/c++/${gcc["version"]}

T make
T make install
