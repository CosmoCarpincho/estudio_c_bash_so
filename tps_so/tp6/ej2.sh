#!/bin/bash

# el puerto http siempre es el 80. Uno hacer que apache abra otro puerto modificando
# /etc/apache2/ports.conf
#
# Entonces para mi lo que hay que hacer sabiendo que buscamos los puertos de apache
# usar el ss o netstat que muestra los procesos que estan escuchando y filtrar por apache
# para ver que puertos tiene abiertos

sudo ss -tulpn | grep "apache" | awk 'BEGIN {print "-- HTTP por Apache --"}{printf "Puerto: %s\n", $5}'
