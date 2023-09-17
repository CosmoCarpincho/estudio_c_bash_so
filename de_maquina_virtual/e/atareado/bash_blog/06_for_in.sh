#!/bin/bash
#
# EL for in funciona con una lista de palabras. Por ejemplo
# 0 1 2 3 4 5  ;;; es una lista de caracteres que representan los numeros
# con el extensor de textos se pueden crear {}
# ej: {0..5} crea 0 1 2 4 5 6
# ej: {pepe,patricio,angelo,cosmo} crea pepe patricio angelo cosmo
#
# con seq tambien
# seq 0 5
#
# con comandos como ls
# con comodines como *
# etc
# Cualquier cosa que cree una lista de palabras separadas por espacio.
# Es como un foreach de C#


for nombre in {pepe,patricio,angelo,cosmo}
do
	echo "Hola $nombre"
done

for numeros_pares in $(seq 0 2 10) # seq first increment last
do
	echo "Numeros pares $numeros_pares"
done

for numeros in {50..55}
do
	echo "Numeros $numeros"
done

for num in {80..70..3}; do #{primero..ultimo..pasos}
	echo "De 80 a 70 de a 3 numeros $num"
done

