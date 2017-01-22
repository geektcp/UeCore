#!/bin/bash
export TBB22_INSTALL_DIR="/usr/local/src/mangos-classic/dep/tbb" #
tbb_bin="${TBB22_INSTALL_DIR}/build/libs_release" #
if [ -z "$CPATH" ]; then #
    export CPATH="${TBB22_INSTALL_DIR}/include" #
else #
    export CPATH="${TBB22_INSTALL_DIR}/include:$CPATH" #
fi #
if [ -z "$LIBRARY_PATH" ]; then #
    export LIBRARY_PATH="${tbb_bin}" #
else #
    export LIBRARY_PATH="${tbb_bin}:$LIBRARY_PATH" #
fi #
if [ -z "$LD_LIBRARY_PATH" ]; then #
    export LD_LIBRARY_PATH="${tbb_bin}" #
else #
    export LD_LIBRARY_PATH="${tbb_bin}:$LD_LIBRARY_PATH" #
fi #
 #
