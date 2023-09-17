#!/bin/bash
#
#7. Hacer un scripts que recorra el directorio tp1 copiado anteriormente y busque todos los archivos con extensión .txt y le asigna permiso de escritura a otros 


find $HOME/practicas/tp2/nuevo/tp1/ -type f -name "*.txt" -exec sudo chmod +002 {} +
