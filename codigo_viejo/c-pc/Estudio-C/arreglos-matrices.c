#include <stdio.h>

int main ()
{
    // Suma numero anterior y posterior y lo guarda en nuevo arreglo. EN los extremos solo suma dos numeros.
    // Primeros 10 numeros
    //Arreglo de 10 con numeros aleatorios
    int arr1 [10] ;
    int resultados [10];

    int i = 0;
    int count = 10;

    printf("Primer Arreglo:\n");
    for (i = 0; i < count; i++)
    {
        arr1[i] = i + 1;
        printf("%d - ", arr1[i]); 
    }

    printf("\n\nArreglo con suma de anterior y posterior:\n");
    for (i = 0; i < count; i++)
    {
        if (i == 0)
            resultados[i] = arr1[i] + arr1[i+1];
        else if (i == 9)
        {
            resultados[i] = arr1[i] + arr1[i-1];
            printf("\n\nel i es: %d y el arr1[i-1]%d",i,arr1[i-1] );
        }
        else
            resultados[i] = arr1[i] + arr1[i+1] + arr1[i-1];
              
        printf("%d - ", resultados[i]); 
    }


    int balance[3];
    
    int size = sizeof balance / sizeof balance[0];

    printf("\nsizeof para sacar size\n%d,%d,%d",sizeof balance,sizeof balance[0],size);

    int i1; 
    for (i1 = 0; i < size; i1++)
    {
        printf("");
    }

    //Declaracion y carga de una de array con tamanio declarado aguera no me funciona pero
    //en un blog dice que se puede
    /*
    const int tam = 4;
    int arr3 [tam] = {2,4,8,10};

    printf("\n\n tam:%d, arr3[3]: %d", tam, arr3[3]);
    */

    //Carga de una array

    //int arr4 [4] = {1,2,3,4};

    
    // Carga de matris necesita dos for
    // 

    int mat[3][4];
    int i2 = 0;
    int fila = 3;
    int columna = 4;
    for (i2; i2 < fila; i2++)
    {
        int j2 = 0;
        for (j2; j2 < columna; j2++)
        {
            mat[i2][j2] = i2+1 + j2+1;
            printf("\ni2: %d j2: %d, fila:%d,columna: %d, matriz:%d", i2, j2,fila, columna,mat[i2][j2]);
        }
        
    }
    

    printf("Imprime la matris de suma de filas y columnas:\n");
    int i3,j3;
    for (i3 = 0; i3 < fila; i3++)
    {
        for (j3 = 0; j3 < columna; j3++)
        {
            printf("%d  ", mat[i3][j3]);
        }
        printf("\n");
                
    }
    
    




    printf("\n\n");

    

    return 0;
}