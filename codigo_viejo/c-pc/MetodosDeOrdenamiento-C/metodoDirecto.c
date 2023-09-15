// Comentario

/* CVL*/

#include <stdio.h>

int main(){
    //void Directo(rev v:vector; N: entero 2);
    //Variables:
    int i;
    int j;
    int aux;

    //Arreglo a ordenar
    int arr1 [10] = {5,3,6,5,1,9,8,5,1,4};
    int ord[10];
    int N = sizeof arr1 / sizeof arr1[0];

    printf("El valor de N: %d\n", N);

    for ( i = 0; i < N-1 ; i++)
    {
        for ( j = i + 1; j < N; j++)
        {
            if (arr1[i] > arr1[j])
            {
                aux = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = aux;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        printf("i: %d\n", i);
    }

    printf("Vetor:");

    for (i = 0; i < N; i++)
    {
        printf("%d", arr1[i]);
    }        
        
}

