#!/bin/bash
#
# Prueba de si entra en until al menos una vez

opcion=s
n=0

until [ "$opcion" = "s" ]; do
	((n++))
done

echo "Entro $n"
