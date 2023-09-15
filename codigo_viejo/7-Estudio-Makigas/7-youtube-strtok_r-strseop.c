/* https://www.youtube.com/watch?v=cCdn7Cy6TfE

    
    https://www.youtube.com/watch?v=a8l8PwCzw20 >>>
    Explica porque strok es peligroso y como funciona. 
    Es destructivo de la cadena original. Por lo tanto conviene hacer una copia con strdup
    Reemplaza a los delimitadores por 0x00
    Genera un puntero al token
    Cuando le pasas de argumento NULL recuerda la ultima posicion


 */



#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *original;
    char *token;

    //strdup copia la cadena de caracteres en una nueva posicion de memoria con malloc y retorna su puntero. Liberar el puntero.
    original = strdup("Cats,Dogs,Mice,, ,Dwarves,Elves:High,Elves:Wood");

    token = strtok(original,",");

    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL,",:");
    }
    
    free(original);// Agregado por mi. Porque strdup devuelve un puntero a una direccion de memoria creado con malloc
    return 0;


//     /*
//     strtok_r() ANSI compliant
//      Es seguro para subprocesos. El tercer parametro es un puntero que realiza un seguimiento del resto de la cadena para que no tenga que usar esas variables locales estaticas
//      
//     */

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char const *argv[])
// {
//     char *original;
//     char *token, *theRest;

//     original = strdup("Cats,Dogs,Mice,,,Dwarves,Elves:High,Elves:Wood");
//     theRest = original;
    
//     while ((token = strtok_r(theRest, ",", &theREst)))
//     {
//         print("Token: %s\n", token);
//     }
    

//     return 0;
// }


    
//     /*
//     strsep()
//     ANSI compliant ademas Incluido en la nueva libreria pero puede hacer que su codigo sea menos protable OJO. Sirve para subprocesos
//     Permite usar multiples delimitadores
//     Los delimitadores vacios los devuelve como vacios
//     Es destructivo. Modifica el arreglo original. Usar strdup
//     No se pueden pasar cadenas constantes
//     */

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char const *argv[])
// {
//     char *original;
//     char *token;

//     original = strdup("Cats,Dogs,Mice,,,Dwarves,Elves:High,Elves:Wood");

//     while ((token = strsep(&original, ",")) != NULL )
//     {
//         printf("Token: %s\n",token);
//     }
    
    
//     return 0;
// }





}
