#!/bin/bash
#

free | awk 'NR==2 {print "Memoria:\n" "Total:"$2, "\nUsado: "$3}'
vmstat | awk 'NR==3 {print "Nro procesos en un estado dormido continuo: ",$1,"\nNro de procesos en un estado dormido continuo: "$2,"\n"}'
