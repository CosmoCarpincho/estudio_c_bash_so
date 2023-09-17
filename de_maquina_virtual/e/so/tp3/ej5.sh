#!/bin/bash
#
#5- Usando una estructura repetitiva recorrer un directorio cualquiera pasado por parámetro y
#determinar que archivos fueron modificados (Comnado stat) en un mes determinado.
#Dicho mes también pasarlo por parámetro.

# comando directorio mes

DIRECTORIO=$1
MES=$2

if [[ ! -d $DIRECTORIO ]];then
	echo "El primer parametro no es un directorio"
	exit 1
fi	

if [[ -z $MES ]];then
	echo "El segundo parametro no puede ser vacio. Indique mes"
	exit 1
fi	

MESMINUSCULA=$(echo $MES | tr '[:upper:]' '[:lower:]') 
echo "mes minuscila" $MESMINUSCULA

case $MESMINUSCULA in
	enero)
		MESNUMERO='01'
		;;
	febrero)
		MESNUMERO='02'
		;;
	marzo)
		MESNUMERO='03'
		;;
	abril)
		MESNUMERO='04'
		;;
	mayo)
		MESNUMERO='05'
		;;
	junio)
		MESNUMERO='06'
		;;
	julio)
		MESNUMERO='07'
		;;
	agosto)
		MESNUMERO='08'
		;;
	septiembre)
		MESNUMERO='09'
		;;	
	octubre)
		MESNUMERO='10'
		;;
	noviembre)
		MESNUMERO='11'
		;;
	diciembre)
		MESNUMERO='12'
		;;
	*)
		echo "No es un mes"
		;;
esac	

echo "DIRECTORIO" $DIRECTORIO
echo "MES" $MES
echo "MESMINUSCULA" $MESMINUSCULA
echo "MESNUMERO" $MESNUMERO

for archivo in $DIRECTORIO/* ; do
	
echo "->" $archivo
#	if [[ -d $archivo ]]; then
#		echo $archivo "Es un directorio"
#		continue
#	fi
#
#	MESARCH=$(stat -c %y archivo | awk -F '-' {print $2})

done






#stat -c %y $1
