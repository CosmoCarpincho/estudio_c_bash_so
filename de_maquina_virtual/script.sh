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

cat $HOME/practicas/tp1/usuarios | awk -F ":" '/admi/ {print "Usuario:",$1,"uid:",$3,"gid:",$4,"shell:",$7}' # > perfil.txt

# otra forma
cat $HOME/practicas/tp1/usuarios | grep "admi" | cut -d ":" -f 1,3,4,7 | sed -e "s/^/Usuarios=>/" -e "s/:/ uid=>/" -e "s/:/ gid=>/" -e "s/:/ shell=>/" # > perfil.txt

# 7- Cambiar la fecha de acceso de perfil.txt a 2018-03-06

touch -d "2018-03-06 00:00:00" $HOME/practicas/tp1/perfil.txt

# 8- Muestre las primeras 2 lineas del archivo usuarios

head -n 2 $HOME/practicas/tp1/usuarios

# 9- Muestre las ultimas 4 lineas del archivo grupos

tail -n 5 $HOME/practicas/tp1/grupos

# 10- Mostrar el contenido del archvo /etc/fstab y redireccionar su contenido al archivo filesystem.txt

