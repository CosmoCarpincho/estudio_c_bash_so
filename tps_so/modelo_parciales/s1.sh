#!/bin/bash

gcc mod3.c -o mod3.out

./mod3.out >archivo_resultante.txt

tar -czf comprimido_$(date +%y-%m-%d-%H-%M-%S).tar.gz ./archivo_resultante.txt
#cron
# 59 23 * 8 1,4
#
#
# min 59
# hs 23
# -- dias mes
# agosto 8
# lunes y jueves 1,4
