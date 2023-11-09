#!/bin/bash

if [ -f informe_de_RAM ]; then
	rm informe_de_RAM
fi
free -h | head -n 1 | awk '{print "     "$1,$2,$3}' >>informe_de_RAM
free -h | head -n 2 | tail -n 1 | awk '{print $1,$2,$3,$4}' >>informe_de_RAM
