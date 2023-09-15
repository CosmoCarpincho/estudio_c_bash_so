#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void cargarProductos(Producto array[], int tamanio)
{

    FILE *producoFILE = fopen("productos.csv", "r" );
    
    char *ref;
    char *refaux;
    char buffer[200];
    char cadena[100];
    
    

    Producto producto;
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, producoFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea
        refaux = strdup(ref);

        char *token;
        
        token = strtok(refaux, ";");
        int j = 0;
        while (token != NULL)
        {
            printf("Token: %s\n", token);
            
            if(i >= REGISTROS_SIN_PROCESAR)
            {
                strcpy(cadena, token);
                if (j == 0)
                {
                    producto.idProducto = strtoul(cadena, NULL, 10);
                }
                else if (j == 1)
                {
                    producto.cantidad = strtoul(cadena, NULL, 10);
                }
                else if (j == 2)
                {
                    producto.precioCosto = (int)strtoul(cadena, NULL, 10);
                }
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = producto;

            printf("\n=== CARGE DATOS EN %d\n", (i - REGISTROS_SIN_PROCESAR));
            printf("id: %lu cantidad: %lu ===\n\n", array[i - REGISTROS_SIN_PROCESAR].idProducto, array[i - REGISTROS_SIN_PROCESAR].cantidad);
        }
    }
    int m;

    printf("\n\n === REGISTROS ===\n");
    for (m = 0 ; m < tamanio - REGISTROS_SIN_PROCESAR; m++)
    {
        printf("id: %lu cantidad: %lu\n", array[m].idProducto, array[m].cantidad);
    }
    
    
        

    free(refaux);
    fclose(producoFILE);
}