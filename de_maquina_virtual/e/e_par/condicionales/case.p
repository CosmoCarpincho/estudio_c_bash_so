case <expresion> in
        <patron 1>)
                comandos
                ;;
        <patron 2>)
                comandos
                ;;
        *)
                comandos
                ;;
esac


ej:

case $1 in
        amarillo)
                echo "optimismo,claridad, calor"
                ;;
        naranja)
                echo " amigable, social, seguridad"
                ;;
        rojo)
                echo "atrevido, exitacion, joven"
                ;;
        *)
                echo " Ese color no existe"
                ;;
esac
        

