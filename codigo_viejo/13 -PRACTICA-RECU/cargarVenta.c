#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarVenta(Venta array[], int tamanio) //** Venta *arr
{

    FILE *ventaFILE = fopen("ventas.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    char *token;
    
    printf("\n ++ Inicio Carga ++\n");
    Venta venta; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, ventaFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
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
                    venta.codSucursal = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 1)
                {
                    venta.idProducto = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 2)
                {
                   venta.cantidad = strtoul(cadena, NULL, 10);//**
                }
                
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = venta; //**

            printf("     ^--- CARGADO EN EL INDICE: %d\n\n", (i - REGISTROS_SIN_PROCESAR));
            
        }
    }

    free(refaux);
    fclose(ventaFILE); //**
}