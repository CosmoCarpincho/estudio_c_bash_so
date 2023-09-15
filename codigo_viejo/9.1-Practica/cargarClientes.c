#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarCliente(Cliente array[], int tamanio) //**
{

    FILE *clienteFILE = fopen("clientes.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    
    printf("\n ++ Inicio Carga ++\n");
    Cliente cliente; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, clienteFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
        refaux = strdup(ref);

        char *token;
        
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
                else if (j == 3)
                {
                    strcpy(cliente.correo, cadena)   ; //**
                }
                else if (j == 4)
                {
                    strcpy(cliente.telefono1, cadena)   ; //**
                }
                else if (j == 5)
                {
                    strcpy(cliente.telefono2, cadena)   ; //**
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
    
    
    //int m;

    // printf("\n\n === REGISTROS ===\n");
    // for (m = 0 ; m < (tamanio - REGISTROS_SIN_PROCESAR); m++)
    // {
    //     printf("id: %lu cantidad: %lu\n", array[m].idClientes, array[m].cantidad);
    // }
    
    
        

    free(refaux);
    fclose(clienteFILE); //**
}