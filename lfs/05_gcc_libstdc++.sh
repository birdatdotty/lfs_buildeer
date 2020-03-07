#!/bin/sh



cd ../${gcc["dir"]}

T mv -v ../${mpfr["dir"]} mpfr
T mv -v ../${gmp["dir"]} gmp
T mv -v ../${mpc["dir"]} mpc

cat gcc/limitx.h gcc/glimits.h gcc/limity.h > \
  `dirname $($LFS_TGT-gcc -print-libgcc-file-name)`/include-fixed/limits.h

for file in gcc/config/{linux,i386/linux{,64}}.h
do
  cp -uv $file{,.orig}
  sed -e "s@/lib\(64\)\?\(32\)\?/ld@$TOOLS&@g" \
      -e "s@/usr@$TOOLS@g" $file.orig > $file
echo "
#undef STANDARD_STARTFILE_PREFIX_1
#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_1 \"$TOOLS/lib/\"
#define STANDARD_STARTFILE_PREFIX_2 \"\"" >> $file

  touch $file.orig
done

sed -i '/k prot/agcc_cv_libc_provides_ssp=yes' gcc/configure
sed -i 's/BUILD_INFO=info/BUILD_INFO=/' gcc/configure

case $(uname -m) in
  x86_64)
    sed -e '/m64=/s/lib64/lib/' \
        -i.orig gcc/config/i386/t-linux64
 ;;
esac

T /bin/rm -rf build
T mkdir build
cd build

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
