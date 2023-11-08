# 1- En su home crear un directorio de practicas

mkdir $HOME/practicas

# 2- Dentro de practias crear un directorio tp1

mkdir $HOME/practicas/tp1

# Ingreso a la carpeta tp1

cd $HOME/practicas/tp1

# 3- Dentro de tp1 crear el archivo perfil.txt

touch $HOME/practicas/tp1/perfil.txt

# 4- Usando comandos del Shell, crear un usuario nombre "admi", para luego darle accesos privilegiados

sudo adduser admi

sudo usermod -aG sudo admi

# 5- En tp1 realizar una copia de los arvhivos /etc/passwd y /etc/group y guardarlos como ususarios y grupos

cp /etc/passwd $HOME/practicas/tp1/usuarios
cp /etc/group $HOME/practicas/tp1/grupos

# 6- En el archivo usuarios creado en el puto anterior, identificar el uid, gid, y shell y guardarlos en el archivo perfiltxt creado en el punto 3

cat $HOME/practicas/tp1/usuarios | awk -F ":" '/^admi/ {print "Usuario:",$1,"uid:",$3,"gid:",$4,"shell:",$7}' # > perfil.txt

# otra forma
cat $HOME/practicas/tp1/usuarios | grep "^admi" | cut -d ":" -f 1,3,4,7 | sed -e "s/^/Usuarios=>/" -e "s/:/ uid=>/" -e "s/:/ gid=>/" -e "s/:/ shell=>/" > $HOME/practicas/tp1/perfil.txt

# 7- Cambiar la fecha de acceso de perfil.txt a 2018-03-06

touch -d "2018-03-06 00:00:00" $HOME/practicas/tp1/perfil.txt

# 8- Muestre las primeras 2 lineas del archivo usuarios

head -n 2 $HOME/practicas/tp1/usuarios

# 9- Muestre las ultimas 4 lineas del archivo grupos

tail -n 5 $HOME/practicas/tp1/grupos

# 10- Mostrar el contenido del archvo /etc/fstab y redireccionar su contenido al archivo filesystem.txt

cat /etc/fstab > $HOME/practicas/tp1/filesystem.txt

# 11- Indicar cantidad de lineas, caracteres y palabras que contiene el archivo filesystems.txt, redireccionar las salidas al archivo cantidad

wc -lwc filesystem.txt | awk '{print "Lineas:",$1,"Caracteres:",$3,"Palabras:",$2}' > $HOME/practicas/tp1/cantidad

# 12- Redireccionar history a $HOME/practicas/tp1/cmd.txt

history > $HOME/practicas/tp1/cmd.txt

# 13- Renombrar el archivo cmd.txt como hist.txt

mv $HOME/practicas/tp1/cmd.txt $HOME/practicas/tp1/hist.txt

# 14- Usando el comando grep buscar en el archivo usuarios el registro correspondiente al usuario creado anteriormente y mandar al archivo newusuario

grep '^admi' usuarios > $HOME/practicas/tp1/newusuario

# 15- Copiar el directorio tp1 como tp1-temp

cp -r $HOME/practicas/tp1 $HOME/practicas/tp1-temp

# 16- Copiar el documento desarrollado en la PARTE A dentro de la carpeta practicas/tp1, con el nombre Practica1ParteA.txt

# cp $HOME/documento $HOME/practicas/tp1/Practica1ParteA.txt

# 17- Comprimir y empaquetar el directorio tp1 y dejar dicho archivo en el directorio de practicas

tar -cvzf tp1.tar.gz tp1/
# c create v verbose z de gz f de file, del nombre al archivo que se va a crear. 
# tar <argumentos> -f <nombrearchivo> [cosas a comprimir]

# Descomprimir gz o tar (se usa lo mismo para los dos)
# -x --extract --get para extraer archivos de un comprimido
# -v 
# -f
# -C para elegir el directorio a descomprimir

mkdir $HOME/practicas/descomprimir
tar -xvf $HOME/practicas/tp1.tar.gz -C $HOME/practicas/descomprimir/

# 18- Borrar el directorio tp1-temp
#
# rm -r $HOME/practicas/tp1-temp
