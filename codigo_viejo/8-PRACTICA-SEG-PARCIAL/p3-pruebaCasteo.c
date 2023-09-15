//https://www.youtube.com/watch?v=UQ5INK_pXCI
// para transformar de string a numeros se puede usar atoi pero es insegura .
//Lo mejor es usar strtol  que convierte string a long int o cualquiera de la familia strtoxxx
// 3 parametros, primero el string, un puntero que apunta al ultimo lugar que se quedo &endPtr , la base numerica)

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char string[10] = "4n223name";
    int num = atoi(string);

    int a = 0;



    return 0;
}