#!/bin/bash
#

# cant_proc_esperando_cpu=$(ps -eo stat | grep -c "R")

# procesos esperando cpy  - ID stat
# echo "Procesos esperando CPU: (PIP STAT)"
# ps -eo stat | grep "R"
# echo "Cantodad : $cant_proc_esperando_cpu"

# cant_proc_domidos=$(ps -eo stat | grep -c "S")
# echo "Cantidad de procesos dormidos son: $cant_proc_domidos"

# USANDO vmstat
# r : numero de procesos en ejecución
# b: número de procesos bloqueados
# swpd :
#

#!/bin/bash

# Obtener estadísticas de vmstat
vmstat
echo ""
vmstat_output=$(vmstat | tail -1)

# a) Procesos esperando por CPU
waiting_for_cpu=$(echo "$vmstat_output" | awk '{print $1}')

# b) Número de procesos en estado dormido
sleeping_processes=$(echo "$vmstat_output" | awk '{print $2}')

# c) Si los procesos están usando memoria swap
swap_processes=$(echo "$vmstat_output" | awk '{print $3}')

# d) Cantidad de memoria intercambiada desde el disco
swap_out=$(echo "$vmstat_output" | awk '{print $7}')

# e) Cantidad de memoria intercambiada hacia el disco
swap_in=$(echo "$vmstat_output" | awk '{print $8}')

# Mostrar los resultados
echo "a) Procesos esperando por CPU: $waiting_for_cpu"
echo "b) Número de procesos en estado dormido: $sleeping_processes"
echo "c) Procesos usando memoria swap: $swap_processes"
echo "d) Cantidad de memoria intercambiada desde el disco: $swap_out"
echo "e) Cantidad de memoria intercambiada hacia el disco: $swap_in"
