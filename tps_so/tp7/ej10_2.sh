#!/bin/bash

particion=$(df -B KB / | awk 'NR==2 {print $1}')
cant_bloques=$(df -B KB / | awk 'NR==2 {print $2}')
bloques_usados=$(df -B KB / | awk 'NR==2 {print $3}')
bloques_disp=$(df -B KB / | awk 'NR==2 {print $4}')

echo "Partición principal: $particion"
echo "Cantidad de bloques (KB): $cant_bloques"
echo "Bloques usados (KB): $bloques_usados "
echo "Bloques disponibles (KB): $bloques_disp"
