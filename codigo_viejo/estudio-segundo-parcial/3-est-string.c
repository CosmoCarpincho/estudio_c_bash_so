// Como trabajar con string

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //No existen los string, solo los arreglos de caracteres
    char texto0[6] = {'H','e','l','l','o','\0'};
    char texto1[10] = {'H','e','l','l','o','\0'};
    char texto2[] = "Hello";

    //print >> ocupa lugar los \000 que estan en texto1??
    printf("Saludo > %s", texto1 );
    // Parece que printf los ignora
    printf("Saludo > %s\n", texto2 );


    switch (texto0)
    {
    case "Hello": 
        /* code */
        break;
    
    default:
        break;
    }
    return 0;
}
