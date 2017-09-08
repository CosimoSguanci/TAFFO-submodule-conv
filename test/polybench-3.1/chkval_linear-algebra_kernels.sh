#!/bin/bash

if [ "x$FORMAT" = "x" ]; then
        FORMAT='\033[33m%10s\033[39m%10s%10s\033[%sm%11s%11s\033[39m%11s%13s\n'
fi
source common_chkval.sh
check "2mm"
check "3mm"
check "atax"
check "bicg"
check "cholesky"
check "doitgen"
check "gemm"
check "gemver"
check "gesummv"
check "mvt"
check "symm"
check "syr2k"
check "syrk"
check "trisolv"
check "trmm"

