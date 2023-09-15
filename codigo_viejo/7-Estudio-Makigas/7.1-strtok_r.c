    /*
    strtok_r() ANSI compliant
    Es seguro para subprocesos. El tercer parametro es un puntero que realiza un seguimiento del resto de la cadena para que no tenga que usar esas variables locales estaticas
    Los limitadores que esten vacios son tratados como un solo delimitador 
    */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *original;
    char *token, *theRest;

    original = strdup("Cats,Dogs,Mice,,,Dwarves,Elves:High,Elves:Wood");
    theRest = original;
    
    while ((token = strtok_r(theRest, ",:", &theRest)))
    {
        printf("Token: %s\n", token);
    }
    
    free(original);
    return 0;
}