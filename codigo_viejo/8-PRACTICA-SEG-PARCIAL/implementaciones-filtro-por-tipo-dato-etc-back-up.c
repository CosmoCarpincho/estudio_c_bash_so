#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAMPO_INT 1
#define CAMPO_UNSIGNED_INT 2
#define CAMPO_LONG 3
#define CAMPO_FLOAT 4
#define CAMPO_DOUBLE 5
#define CAMPO_STRING 6 
#define PRIMER_REGISTRO 0
#define SEGUNDO_REGISTRO 1
void cargarProductos(Producto array[], int tamanio, int cantCampos)
{

    FILE *producoFILE = fopen("productos.csv", "r" );
    
    char *ref;
    char *refaux;
    char buffer[200];
    char campos[3][100];
    int tipocampo[10];
    char cadena[100];
    char arr_aux[100];
    

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
            
            if(i == PRIMER_REGISTRO)
            {
                
                // int a = strcmp(token, "int\0");
                // printf("HOLA");
            } 
            else if(i == SEGUNDO_REGISTRO)
            {
                //Asignar los tipos de datos
                
                if (strcmp(token, "int") == 0)
                {
                    tipocampo[j] = CAMPO_INT;
                }
                else if (strcmp(token, "unsigned int") == 0)
                {
                    tipocampo[j] = CAMPO_UNSIGNED_INT;
                }
                else if (strcmp(token, "long") == 0)
                {
                    tipocampo[j] = CAMPO_LONG;
                }
                else if (strcmp(token, "float") == 0)
                {
                    tipocampo[j] = CAMPO_FLOAT;
                }
                else if (strcmp(token, "double") == 0)
                {
                    tipocampo[j] = CAMPO_DOUBLE;
                } 
                else if (strcmp(token, "string") == 0)
                {
                    tipocampo[j] = CAMPO_STRING;
                }

            }
            else
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
            


            // }
            //campos[j] = token;

            // char cadena[40];
            // strcpy(cadena, token);
            j++;
            token = strtok(NULL,";");
        }
        if (!(i == PRIMER_REGISTRO) && !(i == SEGUNDO_REGISTRO))
        {
            printf("ENTRE A %d\n", i);
            array[i-2] = producto;
            printf("id: %lu cantidad: %lu\n", array[i].idProducto, array[i].cantidad);
        }
        
        
        // producto.idProducto = (unsigned long)campos[0];
        // producto.cantidad = (unsigned long)campos[1];
        // producto.precioCosto = (double)campos[2] ;
        // array[i] = producto;
    }
    int m;
    for (m= 0 ; m < 9; m++)
    {
        printf("id: %lu cantidad: %lu\n", array[m].idProducto, array[m].cantidad);
    }
    
    
        

    free(refaux);
    fclose(producoFILE);
}