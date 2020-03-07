pragma Singleton // Указываем, что этот QML Тип является синглетоном
import QtQuick 2.0

import Pkgs 1.0

Pkgs {
    Pkg {
      href: "http://ftp.gnu.org/gnu/binutils/binutils-2.25.tar.bz2"
      name: "binutils"
      file: "binutils-2.25.tar.bz2"
      version: "2.25"
      suffix: ".tar.bz2"
      dir: "binutils-2.25"
      color: "green"
    }
    Pkg {
      href: "https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.5.3.tar.xz"
      name: "linux"
      file: "linux-5.5.3.tar.xz"
      version: "5.5.3"
      suffix: ".tar.xz"
      dir: "linux-5.5.3"
    }
    Pkg {
      deps: ["mpfr", "mpc","gmp"]
      href: "https://mirror.tochlab.net/pub/gnu/gcc/gcc-9.2.0/gcc-9.2.0.tar.xz"
      name: "gcc"
      file: "gcc-9.2.0.tar.xz"
      version: "9.2.0"
      suffix: ".tar.xz"
      dir: "gcc-9.2.0"
    }
    Pkg {
      href: "http://ftp.gnu.org/gnu/glibc/glibc-2.31.tar.xz"
      info: ["gcc"]
      name: "glibc"
      file: "glibc-2.31.tar.xz"
      version: "2.31"
      suffix: ".tar.xz"
      dir: "glibc-2.31"
    }
    Pkg {
      href: "ftp://gcc.gnu.org/pub/gcc/infrastructure/mpfr-3.1.4.tar.bz2"
      name: "mpfr"
      file: "mpfr-3.1.4.tar.bz2"
      version: "3.1.4"
      suffix: ".tar.bz2"
      dir: "mpfr-3.1.4"
    }
    Pkg {
      href: "ftp://gcc.gnu.org/pub/gcc/infrastructure/gmp-6.1.0.tar.bz2"
      name: "gmp"
      file: "gmp-6.1.0.tar.bz2"
      version: "6.1.0"
      suffix: ".tar.bz2"
      dir: "gmp-6.1.0"
    }
    Pkg {
      href: "ftp://gcc.gnu.org/pub/gcc/infrastructure/mpc-1.0.3.tar.gz"
      name: "mpc"
      file: "mpc-1.0.3.tar.gz"
      version: "1.0.3"
      suffix: ".tar.gz"
      dir: "mpc-1.0.3"
    }
    Pkg {
      href: "ftp://gcc.gnu.org/pub/gcc/infrastructure/isl-0.18.tar.bz2"
      name: "isl"
      file: "isl-0.18.tar.bz2"
      version: "0.18"
      suffix: ".tar.bz2"
      dir: "isl-0.18"
    }
    Pkg {
        href: "ftp://gcc.gnu.org/pub/gcc/infrastructure/cloog-0.18.1.tar.gz"
        name: "cloog"
        file: "cloog-0.18.1.tar.gz"
        version: "0.18.1"
        suffix: ".tar.gz"
        dir: "cloog-0.18.1"
    }
    Pkg {
        href: "https://ftp.gnu.org/gnu/wget/wget-1.20.tar.gz"
        name: "wget"
        file: "wget-1.20.tar.gz"
        version: "1.20"
        suffix: ".tar.gz"
        dir: "wget-1.20"
    }
    Pkg {
        href: "https://osdn.net/frs/g_redir.php?m=kent&f=tcl%2FTcl%2F8.6.8%2Ftcl8.6.8-src.tar.gz"
        name: "tcl"
        file: "tcl8.6.10-src.tar.gz"
        version: "8.6.10"
        suffix: ".tar.gz"
        dir: "tcl8.6.10"
    }
    Pkg {
        href: "https://prdownloads.sourceforge.net/expect/expect5.45.4.tar.gz"
        name: "expect"
        file: "expect5.45.4.tar.gz"
        version: "5.45.4"
        suffix: ".tar.gz"
        dir: "expect5.45.4"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/dejagnu/dejagnu-1.6.2.tar.gz"
        name: "dejagnu"
        file: "dejagnu-1.6.2.tar.gz"
        version: "1.6.2"
        suffix: ".tar.gz"
        dir: "dejagnu-1.6.2"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/m4/m4-1.4.18.tar.xz"
        name: "m4"
        file: "m4-1.4.18.tar.xz"
        version: "1.4.18"
        suffix: ".tar.xz"
        dir: "m4-1.4.18"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/ncurses/ncurses-6.2.tar.gz"
        name: "ncurses"
        file: "ncurses-6.2.tar.gz"
        version: "6.2"
        suffix: ".tar.gz"
        dir: "ncurses-6.2"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/bash/bash-5.0.tar.gz"
        name: "bash"
        file: "bash-5.0.tar.gz"
        version: "5.0"
        suffix: ".tar.gz"
        dir: "bash-5.0"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/bison/bison-3.5.2.tar.xz"
        name: "bison"
        file: "bison-3.5.2.tar.xz"
        version: "3.5.2"
        suffix: ".tar.xz"
        dir: "bison-3.5.2"
    }
    Pkg {
        href: "https://www.sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz"
        name: "bzip2"
        file: "bzip2-1.0.8.tar.gz"
        version: "1.0.8"
        suffix: ".tar.gz"
        dir: "bzip2-1.0.8"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/coreutils/coreutils-8.31.tar.xz"
        name: "coreutils"
        file: "coreutils-8.31.tar.xz"
        version: "8.31"
        suffix: ".tar.xz"
        dir: "coreutils-8.31"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/diffutils/diffutils-3.7.tar.xz"
        name: "diffutils"
        file: "diffutils-3.7.tar.xz"
        version: "3.7"
        suffix: ".tar.xz"
        dir: "diffutils-3.7"
    }
    Pkg {
        href: "ftp://ftp.astron.com/pub/file/file-5.38.tar.gz"
        name: "file"
        file: "file-5.38.tar.gz"
        version: "5.38"
        suffix: ".tar.gz"
        dir: "file-5.38"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/findutils/findutils-4.7.0.tar.xz"
        name: "findutils"
        file: "findutils-4.7.0.tar.xz"
        version: "4.7.0"
        suffix: ".tar.xz"
        dir: "findutils-4.7.0"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/gawk/gawk-5.0.0.tar.xz"
        name: "gawk"
        file: "gawk-5.0.0.tar.xz"
        version: "5.0.0"
        suffix: ".tar.xz"
        dir: "gawk-5.0.0"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/gettext/gettext-0.20.1.tar.xz"
        name: "gettext"
        file: "gettext-0.20.1.tar.xz"
        version: "0.20.1"
        suffix: ".tar.xz"
        dir: "gettext-0.20.1"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/grep/grep-3.4.tar.xz"
        name: "grep"
        file: "grep-3.4.tar.xz"
        version: "3.4"
        suffix: ".tar.xz"
        dir: "grep-3.4"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/gzip/gzip-1.10.tar.xz"
        name: "gzip"
        file: "gzip-1.10.tar.xz"
        version: "1.10"
        suffix: ".tar.xz"
        dir: "gzip-1.10"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/make/make-4.3.tar.gz"
        name: "make"
        file: "make-4.3.tar.gz"
        version: "4.3"
        suffix: ".tar.gz"
        dir: "make-4.3"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/patch/patch-2.7.6.tar.xz"
        name: "path"
        file: "patch-2.7.6.tar.xz"
        version: "2.7.6"
        suffix: ".tar.xz"
        dir: "patch-2.7.6"
    }
    Pkg {
        href: "https://www.cpan.org/src/5.0/perl-5.30.1.tar.xz"
        name: "perl"
        file: "perl-5.30.1.tar.xz"
        version: "5.30.1"
        suffix: ".tar.xz"
        dir: "perl-5.30.1"
    }
    Pkg {
        href: "https://www.python.org/ftp/python/3.8.1/Python-3.8.1.tar.xz"
        name: "python"
        file: "Python-3.8.1.tar.xz"
        version: "3.8.1"
        suffix: ".tar.xz"
        dir: "Python-3.8.1"
    }

    Pkg {
        href: "http://ftp.gnu.org/gnu/sed/sed-4.8.tar.xz"
        name: "sed"
        file: "sed-4.8.tar.xz"
        version: "4.8"
        suffix: ".tar.xz"
        dir: "sed-4.8"
    }
    Pkg {
        href: "https://tukaani.org/xz/xz-5.2.4.tar.xz"
        name: "tar"
        file: "xz-5.2.4.tar.xz"
        version: "5.2.4"
        suffix: ".tar.xz"
        dir: "xz-5.2.4"
    }
    Pkg {
        href: "http://ftp.gnu.org/gnu/texinfo/texinfo-6.7.tar.xz"
        name: "texinfo"
        file: "texinfo-6.7.tar.xz"
        version: "6.7"
        suffix: ".tar.xz"
        dir: "texinfo-6.7"
    }
    Pkg {
        href: "https://www.kernel.org/pub/linux/utils/util-linux/v2.35/util-linux-2.35.1.tar.xz"
        name: "utilLinux"
        file: "util-linux-2.35.1.tar.xz"
        version: "2.35.1"
        suffix: ".tar.xz"
        dir: "util-linux-2.35.1"
    }
    Pkg {
        href: "https://mirror.yandex.ru/gentoo-distfiles/distfiles/xz-5.2.4.tar.gz"
        name: "xz"
        file: "xz-5.2.4.tar.gz"
        version: "5.2.4"
        suffix: ".tar.gz"
        dir: "xz-5.2.4"
    }
}
