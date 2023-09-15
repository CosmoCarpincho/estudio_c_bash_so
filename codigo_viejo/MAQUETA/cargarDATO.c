#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarCliente(Cliente array[], int tamanio) //** Cliente *arr
{

    FILE *clienteFILE = fopen("clientes.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    char *token;
    
    printf("\n ++ Inicio Carga ++\n");
    Cliente cliente; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, clienteFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
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
                    cliente.idCliente = strtoul(cadena, NULL, 10); //**

                    //long int strtol(const char *str, char **endptr, int base)
                    // >> (int)strtol(cadena, NULL,10); para int
                    //unsigned long int strtoul(const char *str, char **endptr, int base)
                }
                else if (j == 1)
                {
                    strcpy(cliente.nombre, cadena)   ; //**
                }
                else if (j == 2)
                {
                    strcpy(cliente.direccion, cadena)   ; //**
                }
                
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = cliente; //**

            printf("     ^--- CARGADO EN EL INDICE: %d\n\n", (i - REGISTROS_SIN_PROCESAR));
            
        }
    }

    free(refaux);
    fclose(clienteFILE); //**
}