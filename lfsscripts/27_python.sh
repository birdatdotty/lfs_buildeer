#/bin/sh
cd ../${pkg["dir"]}
sed -i '/def add_multiarch_paths/a \        return' setup.py
./configure --prefix=/tools --without-ensurepip
T make
T make install
