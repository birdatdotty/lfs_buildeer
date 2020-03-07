#!/bin/sh
#TOOLS=/tools
#LFS=/mnt/lfs
#LFS_TGT=x86_64-lfs-linux-gnu
#PATH=$TOOLS/bin:/bin:/usr/bin

#set +h
#umask 022
#LC_ALL=POSIX
#export LFS LC_ALL LFS_TGT PATH

if [ ! -r /usr/include/rpc/types.h ]; then
      echo su -c 'mkdir -p /usr/include/rpc'
      echo su -c 'cp -v sunrpc/rpc/*.h /usr/include/rpc'
      echo "sudo cp -v .../" ${glibc["dir"]} "/sunrpc/rpc/*.h /usr/include/rpc"

      exit 1
fi

cd ../${glibc["dir"]}

mkdir -v build
cd       build

T ../configure                                           \
      --prefix=$TOOLS                                    \
      --host=$LFS_TGT                                    \
      --build=$(../${glibc["dir"]}/scripts/config.guess) \
      --enable-kernel=3.2                                \
      --with-headers=$TOOLS/include

T make
T make install

## https://unix.stackexchange.com/questions/154083/how-to-provide-crt1-o-and-crti-o-for-lfs
##ln -s $TOOLS/lib/crt*.o $TOOLS/lib/gcc/${LFS_TGT}/${gcc["version"]}/
#
## https://preshing.com/20141119/how-to-build-a-gcc-cross-compiler/
#T make install-bootstrap-headers=yes install-headers
#T make -j4 csu/subdir_lib
#T install csu/crt1.o csu/crti.o csu/crtn.o $TOOLS/$TOOLS_TGT/lib
#T $LFS_TGT-gcc -nostdlib -nostartfiles -shared -x c /dev/null -o $TOOLS/$TOOLS_TGT/lib/libc.so
