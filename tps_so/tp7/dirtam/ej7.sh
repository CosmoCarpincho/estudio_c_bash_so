#!/bin/bash
# el fdisk -l muestra los discos que no estan montados.
# El df muestra solo los que estan montados.
#
# No olvidar el sudo del fdisk
discos=$(sudo fdisk -l | grep Disco | awk '{print $2}' | awk -F ":" '{print $1}')

# info=$(fdisk -l | grep Disco | awk '{printf $2}' | cut -d ":" -f 1')

for disco in $discos; do
	echo "Disco: $disco"
	particiones=$(sudo fdisk -l "$disco" | grep -G "^\/" | awk '{print $1}')
	cant=$(echo $particiones | wc -w)

	for particion in $particiones; do
		echo -n "Particion: $particion "
		tam_part=$(sudo fdisk -l "$particion" | grep "Disco" | awk '{print $3, $4}')
		echo "Tamanio: $tam_part"

	done
	echo " "
done
