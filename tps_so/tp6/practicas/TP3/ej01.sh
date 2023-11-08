#!/bin/bash

# 1- Guardar las variables de entorno HOSTNAME, HOME, LOGNAME Y PATH en un archivo de nombre var-set ordenado por nombre de variable.

echo -e "HOSTNAME: $HOSTNAME\nHOME: $HOME\nLOGNAME: $LOGNAME\nPATH: $PATH" | sort  > var-set
