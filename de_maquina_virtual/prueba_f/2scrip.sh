#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Debe proporcionar un directorio como argumento"
  exit 1
fi

directorio="$1"
bk_directorio="bk"
archivos_modificados=0

if [ ! -d "$directorio" ]; then
  echo "El directorio '$directorio' no existe"
  exit 1
fi

if [ ! -d "$bk_directorio" ]; then
  echo "Creando el directorio '$bk_directorio'..."
  mkdir "$bk_directorio"
fi

for archivo in "$directorio"/*; do
  if [ "$(date -r "$archivo" +%Y)" -eq 2023 ]; then
    cp "$archivo" "$bk_directorio"
    archivos_modificados=$((archivos_modificados+1))
  fi
done

echo "Cantidad de archivos copiados: $archivos_modificados"
