#!/bin/sh
T cd ../${linux["dir"]}

T make mrproper
T make headers
T cp -rv usr/include/* $TOOLS/include
