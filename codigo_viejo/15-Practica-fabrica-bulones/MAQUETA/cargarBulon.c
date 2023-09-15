#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarBulon(Bulon array[], int tamanio) //** Bulon *arr
{
    tamanio = tamanio + 3;

    FILE *bulonFILE = fopen("bulones.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    char *token;
    
    printf("\n ++ Inicio Carga ++\n");
    Bulon bulon; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, bulonFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
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
                    bulon.codigo = strtoul(cadena, NULL, 10); //**
                    
                }
                else if (j == 1)
                {
                    strcpy(bulon.nombre, cadena)   ; //**
                }
                else if (j == 2)
                {
                   bulon.stock = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 3)
                {
                   bulon.precioUnitario = strtof(cadena, NULL); //**
                }
                
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = bulon; //**

            printf("     ^--- CARGADO EN EL INDICE: %d\n\n", (i - REGISTROS_SIN_PROCESAR));
            
        }
    }

    free(refaux);
    fclose(bulonFILE); //**
}