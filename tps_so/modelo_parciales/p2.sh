#!/bin/bash
#o
#
#

for file in $(find . -type f -name '*.txt'); do
	echo $file | sed 's/sh//' >>holabro.prueba
done
