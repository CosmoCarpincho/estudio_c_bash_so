#!/bin/bash

# forma 1
which dmidecode
echo $?
if [ $? -ne 0 ]; then
	echo "No esta instalado el dmicode"
else
	echo "Esta instalado"
fi
# forma 2 o usar command -v
if which dmidecode >/dev/null; then
	echo "Esta"
else
	echo "No esta"
fi

# en mi maquina virtual no funciona asi que dejo los comandos para probar en el docker de la facu
# $ sudo dmidecode -t 17
# dmidecode 3.4
# Getting SMBIOS data from sysfs.
# SMBIOS 2.5 present.

sudo dmidecode -t 16 | grep "Maximun Capacity"
sudo dmidecode -t 17 | grep "Maximum Module Size"

# buscar en el manual que numero usar
