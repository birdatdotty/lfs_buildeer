import QtQuick 2.0

import ModelApi 1.0;

ListModel {
    ListElement {
      href: "http://ftp.gnu.org/gnu/binutils/binutils-2.25.tar.bz2"
      name: "binutils"
      file: "binutils-2.25.tar.bz2"
      version: "2.25"
      suffix: ".tar.bz2"
      dir: "binutils-2.25"
      color: "green"
    }
    ListElement {
      href: "https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.5.3.tar.xz"
      name: "linux"
      file: "linux-5.5.3.tar.xz"
      version: "5.5.3"
      suffix: ".tar.xz"
      dir: "linux-5.5.3"
      color: "green"
    }
    ListElement {
      href: "https://mirror.tochlab.net/pub/gnu/gcc/gcc-9.2.0/gcc-9.2.0.tar.xz"
      name: "gcc"
      file: "gcc-9.2.0.tar.xz"
      version: "9.2.0"
      suffix: ".tar.xz"
      dir: "gcc-9.2.0"
      color: "green"
    }

}
