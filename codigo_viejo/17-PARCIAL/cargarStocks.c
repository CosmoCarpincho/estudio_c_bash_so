#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarStock(Stock array[], int tamanio) //** Stock *arr
{
    tamanio = tamanio + REGISTROS_SIN_PROCESAR;

    FILE *stockFILE = fopen("stocks.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    char *token;
    
    printf("\n ++ Inicio Carga ++\n");
    Stock stock; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, stockFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
        refaux = strdup(ref);

        //char *token;
        
        token = strtok(refaux, ";");
        int j = 0;
        
        printf("\n>  ");
        while (token != NULL)
        {
            printf("  %s", token);
            
            if(i >= REGISTROS_SIN_PROCESAR)
            {
                strcpy(cadena, token);
                if (j == 0)
                {
                    stock.idProveedor = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 1)
                {
                    stock.idProducto = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 2)
                {
                    stock.disponible = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 3)
                {
                    stock.stock_minimo = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 4)
                {
                    stock.costo = strtof(cadena, NULL); //**
                }
                
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = stock; //**

            printf("     ^--- CARGADO EN EL INDICE: %d\n\n", (i - REGISTROS_SIN_PROCESAR));
            
        }
    }

    free(refaux);
    fclose(stockFILE); //**
}