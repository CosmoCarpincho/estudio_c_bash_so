// Implementacion de funciones
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //gestionar memoria dinamica ej: malloc()
#include <time.h>

void cargarRegistros(Registro array[], int tamanio)
{       time_t t;
        srand((unsigned) time(&t));
        Registro r1;
        
        int i;
        for (i = 0; i < tamanio; i++)
        {   
            r1.idproducto = i + 1;
            r1.cantidad = rand() % (1001);
            r1.codsucursal= rand() % (101);
            array[i] = r1; 

            //printf("- IdProducto: %20u -\n- Cantidad: %22d -\n- CodSucursal: %19ld -\n", r1.idproducto, r1.cantidad, r1.codsucursal);
            //printf("-                                  -\n");
        }
        
}

void mostrarRegistros(Registro array[], int tamanio)
{
    
    int i;
    printf("\n\n== PLANILLA VENTAS 2 ==\n\n");
    for (i = 0; i < tamanio; i++)
    {   
        printf("- IdProducto: %20u -\n- Cantidad: %22d -\n- CodSucursal: %19ld -\n", array[i].idproducto, array[i].cantidad, array[i].codsucursal);
        printf("-                                  -\n");
    }

}
