#!/bin/sh
cd ../${binutils["dir"]}
mkdir -v build
cd       build
T ../configure --prefix=$TOOLS            \
               --with-sysroot=$LFS        \
               --with-lib-path=$TOOLS/lib \
               --target=$LFS_TGT          \
               --disable-nls              \
               --disable-werror

T make

case $(uname -m) in
  x86_64) mkdir -v $TOOLS/lib && ln -sv lib $TOOLS/lib64 ;;
esac

T make install
