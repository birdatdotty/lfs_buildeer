#!/bin/sh

cd ../${m4["dir"]}
sed -i 's/IO_ftrylockfile/IO_EOF_SEEN/' lib/*.c
echo "#define _IO_IN_BACKUP 0x100" >> lib/stdio-impl.h
T ./configure --prefix=$TOOLS

T make
T make check
T make install
