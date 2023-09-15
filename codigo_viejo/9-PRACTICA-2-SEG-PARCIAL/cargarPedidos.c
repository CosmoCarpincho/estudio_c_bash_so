#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarPedidos(Pedido array[], int tamanio) //**
{

    FILE *pedidoFILE = fopen("pedidos.csv", "r" ); //**
    
    char aux_ref = 'a';
    char *ref = &aux_ref ;
    char *refaux;
    char buffer[200];
    char cadena[100];
    
    printf("\n ++ Inicio Carga ++\n");
    Pedido pedido; //**
    int i ;
    for ( i= 0; (ref != NULL) && (i < tamanio); i++ )
    {
        ref = fgets(buffer, 200, pedidoFILE); // Si sale mal devuelve NULL, Deja de leer cuando se encuentra un salto de linea //**
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
                    pedido.idCliente = strtoul(cadena, NULL, 10); //**

                    //long int strtol(const char *str, char **endptr, int base)
                    // >> (int)strtol(cadena, NULL,10); para int
                    //unsigned long int strtoul(const char *str, char **endptr, int base)
                }
                else if (j == 1)
                {
                    pedido.idProducto = strtoul(cadena, NULL, 10); //**
                }
                else if (j == 2)
                {
                    pedido.cantidad = strtoul(cadena, NULL, 10); //**
                }
                
            }
            
            j++;
            token = strtok(NULL,";");
        }
        if (i >= REGISTROS_SIN_PROCESAR)
        {
            
            array[i - REGISTROS_SIN_PROCESAR ] = pedido; //**

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
    fclose(pedidoFILE); //**
}