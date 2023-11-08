#!/bin/bash

cant_usuarios=$(sudo uptime | awk '{print $4}')
up_time=$(sudo uptime | awk '{print $3}')
promedio_carga=$(sudo uptime | awk '{print $8,$9,$10}')
echo "Cantidad de usuarios: $cant_usuarios"
echo "Tiempo de encendido del equipo: $up_time"
echo "Promedio de carga $promedio_carga"

# crontab
