#include <stdio.h>
#include <stdlib.h> // Libreria mara manejar memoria dinamica

int main(int argc, char const *argv[])
{
    //calloc es igual que malloc pero inicializa todo en cero.
    //Ademas de que se PASAN DISTINTO LOS ARGUMENTOS
    //devuelve puntero void   void*
    int tamanioArreglo = 10;
    int* arregloCalloc = (int*) calloc(tamanioArreglo, sizeof(int));
    //
    //------------------------------------------------------------


    //malloc(cant-tipo * sizeof(int)); devuelve tipo puntero void OJO hay que castear
    printf("Cuantos elementos quieres almacenar?");
    int longitud;
    scanf("%d",&longitud);
    float* valores =  (float*) malloc (longitud * sizeof(float)); 
    
    
    if (valores == NULL) // MANEJO DE ERROR por si hay overflow
    {
       printf("Si no hay memoria suficiente malloc falla devolviendo null") ;
       return 1;
    }
    int i;
    for ( i = 0; i < longitud; i++)
    {
        valores[i] = 5.55E5;
    }
    


    // Para liberar memoria de malloc usar free() OJO porque no se libera solo
    free(valores);
    free(arregloCalloc);
    
    return 0;
}


