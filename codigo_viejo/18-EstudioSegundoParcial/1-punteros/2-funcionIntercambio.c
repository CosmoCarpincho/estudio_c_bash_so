#include <stdio.h>
#include <stdlib.h>
void intercambio(int *n1, int *n2);

int main(int argc, char const *argv[])
{
    int n1 = 10;
    int n2 = 50;
    char * memoriaDinamica = (char *) malloc(char * 10);
    
    intercambioERROR(&n1,&n2);
    printf("n1 = %d | n2 = %d \n", n1, n2);

    intercambioPunteros(&n1,&n2);
    printf("n1 = %d | n2 = %d \n", n1, n2);


    return 0;
}
//ERROR!! OJO! Esta funcion no cambia los valores porque se esta pasando al puntero por copia.
//!! Para pasar por referencia y intercambiar los punteros usar punteros dobles
void intercambioERROR(int *n1, int *n2)
{
    int *temp;
    temp = n1;
    n1 = n2;
    n2 = n1;
}

//Y si no quiero cambiar los valores internos porque son muy grandes
//Me conviene cambiar los punteros

void intercambioPunteros(int **n1,int **n2)
{
    int *temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}