!#/bin/bash

if [ ! -d practicas ]; then
	echo "No existe el directorio practicas"
	exit 2
fi

if [ -f backup_practicas.tar.gz ]; then
	rm backup_practicas.tar.gz
fi

# para solo hacer backup de TP1 a TP3
tar -czf backup_practicas.tar.gz -C practicas TP1 TP2 TP3

#crontab -e

# 0 0 * * 1-5 /script
