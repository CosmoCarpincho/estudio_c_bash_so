# 3. Realizar un script que evalue 2 archivos ordinarios, e indique entre ambos cual posee mas cantidad de lineas
# Aclaracion: no se pasa por parametro

arch1='/etc/group'
arch2='/etc/passwd'


cant1=$(wc -l $arch1 | cut -d " " -f 1)
cant2=$(wc -l $arch2 | cut -d " " -f 1)

if [ $cant1 -gt $cant2 ]
then
	echo "El archivo" $arch1 '(' $cant1 ' lineas )' "es mayor que" $arch2 '(' $cant2 ' lineas )'

elif [ $cant1 -lt $cant2 ]
then
	echo "El archivo" $arch2 '(' $cant2 ' lineas)' "es mayor que" $arch1 '(' $cant1 ' lineas )'
else
	echo "Los archivos tienen las mismas lineas ->" $cant1
fi

