   /*
    stresep()
    ANSI compliant ademas Incluido en la nueva libreria pero puede hacer que su codigo sea menos protable OJO. Sirve para subprocesos
    Permite usar multiples delimitadores
    Los delimitadores vacios los devuelve como vacios
    Es destructivo. Modifica el arreglo original. Usar strdup
    No se pueden pasar cadenas constantes
    */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *original;
    char *token;

    original = strdup("Cats,Dogs,Mice,,,Dwarves,Elves:High,Elves:Wood");

    while ((token = strsep(&original, ",")) != NULL )
    {
        printf("Token: %s\n",token);
    }
    
    
    return 0;
}