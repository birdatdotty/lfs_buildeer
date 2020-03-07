pragma Singleton // Указываем, что этот QML Тип является синглетоном
import InstallList 1.0
import Util 1.0

Install {
    scriptsDir: "/home/lfsscripts"
    pkgs: Pkgs2
    wget: ["wget", "-c"]
    wget_out: "-O"
    tar: ["tar", "-xf"]
    sourcesDir: "/home/sources"
    buildDir: "/home/build"
    buildRoot: "/tools"
    lfs: "/mnt/lfs"
    tgt: "x86_64-lfs-linux-gnu"

    bash: [
        "#!/bin/sh",
        "TOOLS=" + buildRoot,
        "LFS=" + lfs,
        "LFS_TGT=" + tgt,
        "PATH=$TOOLS/bin:/bin:/usr/bin",

        "set +h", // не созранять хэш команд
        "set -e", // выход из скрипта при ошибке
        "umask 022",
        "LC_ALL=POSIX",
        "export LFS LC_ALL LFS_TGT PATH",
        "function T { $@ || exit 1; }"
    ]

    /*
      steps:
      1. download
      2. extract pkgs
      3. gen scrip file
      4. run script
      5. clearing
    */

    Step {
        name: "Binutils-2.34 - Pass 1"
        pkg: "binutils"
        script: "01_binutils.sh"
        sbu: "1 SBU"
    }
    Step {
        name: "GCC-9.2.0 - Pass 1"
        pkg: "gcc"
        script: "02_gcc.sh"
        sbu: "10 SBU"
//        steps: [1,2,3,4]
    }
    Step {
        name: "Linux-5.5.3 API Headers"
        pkg: "linux"
        script: "03_linux_header.sh"
        sbu: "0.1 SBU"
    }
    Step {
        name: "Glibc-2.31"
        pkg: "glibc"
        script: "04_glibc.sh"
        sbu: "4.5 SBU"
//        steps: [1,2,3,4]
    }
    Step {
        name: "Libstdc++ from GCC-9.2.0"
        pkg: "gcc"
        script: "05_gcc_libstdc++.sh"
        sbu: "0.5 SBU"
//        steps: [3,4]
    }
    Step {
        name: "Binutils-2.34 - Pass 2"
        pkg: "binutils"
        script: "06_binutils_s2.sh"
        sbu: "1.1 SBU"
    }
    Step {
        name: "GCC-9.2.0 - Pass 2"
        pkg: "gcc"
        script: "07_gcc_s2.sh"
        sbu: "13 SBU"
    }
//    Step {
//        name: "wget"
//        pkg: "wget"
//        script: "TEST.sh"
//        steps: [1,2,3,4]
//    }
    Step {
        name: "Tcl-8.6.10"
        pkg: "tcl"
        script: "08_tcl.sh"
        sbu: "0.9 SBU"
//        steps: [2,3,4,5]
    }
    Step {
        name: "Expect-5.45.4"
        pkg: "expect"
        script: "09_expect.sh"
        sbu: "0.1 SBU"
//        steps: [2,3,4,5]
    }
    Step {
        name: "DejaGNU-1.6.2"
        pkg: "dejagnu"
        script: "10_dejagnu.sh"
        sbu: "0.9 SBU"
//        steps: [2,3,4,5]
    }
    Step {
        name: "M4-1.4.18"
        pkg: "m4"
        script: "11_m4.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Ncurses-6.2"
        pkg: "ncurses"
        script: "12_ncurses.sh"
        sbu: "0.6 SBU"
    }
    Step {
        name: "Bash-5.0"
        pkg: "bash"
        script: "13_bash.sh"
        sbu: "0.4 SBU"
    }
    Step {
        name: "Bison-3.5.2"
        pkg: "bison"
        script: "14_bison.sh"
        sbu: "0.3 SBU"
    }
    Step {
        name: "Bzip2-1.0.8"
        pkg: "bzip2"
        script: "15_bzip2.sh"
        sbu: "0.1 SBU"
    }
    Step {
        name: "Coreutils-8.31"
        pkg: "coreutils"
        script: "16_coreutils.sh"
        sbu: "0.7 SBU"
    }
    Step {
        name: "Diffutils-3.7"
        pkg: "diffutils"
        script: "17_diffutils.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "File-5.38"
        pkg: "file"
        script: "18_file.sh"
        sbu: "0.1 SBU"
    }
    Step {
        name: "Findutils-4.7.0"
        pkg: "findutils"
        script: "19_findutils.sh"
        sbu: "0.3 SBU"
    }
    Step {
        // ERROR
        name: "Gawk-5.0.0"
        pkg: "gawk"
        script: "20_gawk.sh"
        sbu: "0.2 SBU"
//        status: Step.FAILED
    }
    Step {
        name: "Gettext-0.20.1"
        pkg: "gettext"
        script: "21_gettext.sh"
        sbu: "1.6 SBU"
    }
    Step {
        name: "Grep-3.4"
        pkg: "grep"
        script: "22_grep.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Gzip-1.10"
        pkg: "gzip"
        script: "23_gzip.sh"
        sbu: "0.1 SBU"
    }
    Step {
        name: "Make-4.3"
        pkg: "make"
        script: "24_make.sh"
        sbu: "0.1 SBU"
    }
    Step {
        name: "Patch-2.7.6"
        pkg: "path"
        script: "25_patch.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Perl-5.30.1"
        pkg: "perl"
        script: "26_perl.sh"
        sbu: "1.5 SBU"
    }
    Step {
        name: "Python-3.8.1"
        pkg: "python"
        script: "27_python.sh"
        sbu: "1.3 SBU"
    }

    Step {
        name: "Sed-4.8"
        pkg: "sed"
        script: "28_sed.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Tar-1.32"
        pkg: "tar"
        script: "29_tar.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Texinfo-6.7"
        pkg: "texinfo"
        script: "30_texinfo.sh"
        sbu: "0.2 SBU"
    }
    Step {
        name: "Util-linux-2.35.1"
        pkg: "utilLinux"
        script: "31_util-linux.sh"
        sbu: "0.9 SBU"
    }
    Step {
        name: "Xz-5.2.4"
        pkg: "xz"
        script: "32_xz.sh"
        sbu: "0.2 SBU"
    }
}
