#define PRIMER_REGISTRO 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarProductos(Producto array[], int tamanio, int cantCampos)
{
    
    

    FILE *producoFILE = fopen("productos.csv", "r" );
    
    char *ref;
    char *refaux;
    char buffer[200];
    char campos[3][100];
    int i = 0;

    Producto producto;

    while (ref != NULL && i < tamanio )
    {
        ref = fgets(buffer, 200, producoFILE); // SI sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea

        

        refaux = strdup(ref);

        char *token;
        token = strtok(refaux, ";");
        int j = 0;
        while (token != NULL)
        {
            printf("Token: %s\n", token);
            
            if(PRIMER_REGISTRO)
            {
                token = strtok(NULL,";");
                break;
            }
            //campos[j] = token;
            strcpy(campos[j], token);
            j++;
            token = strtok(NULL,";");
        }

        producto.idProducto = (unsigned long)campos[0];
        producto.cantidad = (unsigned long)campos[1];
        producto.precioCosto = (double)campos[2] ;
        array[i] = producto;
    }
    
    
        

    free(refaux);
    fclose(producoFILE);

}