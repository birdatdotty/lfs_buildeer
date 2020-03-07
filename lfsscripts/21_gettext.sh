#!/bin/sh

cd ../${gettext["dir"]}

./configure --disable-shared
make
cp -v gettext-tools/src/{msgfmt,msgmerge,xgettext} $TOOLS/bin
