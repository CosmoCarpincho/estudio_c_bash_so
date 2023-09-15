#define TAM_ARREGLO 10
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "cargarBulon.c"

int main(void)
{
    //struc
    //Bulon bulon;
    //Arreglos de struct
    Bulon bulones[TAM_ARREGLO];

    Auditoria auditorias[TAM_ARREGLO];
    
    

    //Cargar
    //cargarDATOS(dato, TAM_ARREGLO )

    cargarBulon(bulones, TAM_ARREGLO);


    cargaCodigosAuditoria(auditorias, bulones, TAM_ARREGLO);

    unsigned int codigo = 0;
    unsigned int venta = 0;
    int ia;

    
    char opcion;
    while (opcion != 'q')
    {
        printf("\nMENU\n");
        printf("[1] vender bulon\n");
        printf("[2] recaudado al final del dia\n");
        printf("[q] salir\n");
        scanf("%c",&opcion);
        

        switch (opcion)
        {
        case '1':
            printf("Ingrese el codigo del bulon: ");
            scanf("%u",&codigo);
            printf("Ingrese la cantidad de bulones a vender: ");
            scanf("%u", &venta);
            printf("\n");
            venderBulones(bulones, TAM_ARREGLO, codigo, venta, auditorias);
            break;

        case '2':
           
            for (ia = 0; ia < TAM_ARREGLO; ia++)
            {
                printf("Tipo bulon: %u, total vendido: %u, totalRecaudado: %f \n", auditorias[ia].codigo, auditorias[ia].totalVendido, auditorias[ia].totalRecaudado);
            }
            
            
            break;
        
        default:
            break;
        }

        while (getchar() != '\n');
        
        
    }

    
    
    return 0;
}


void venderBulones(Bulon bulones[], int tamArreglo, unsigned int codigo, unsigned int venta, Auditoria auditorias[])
{
    double totalVenta = 0;
    int ib;
   for (ib = 0; ib < tamArreglo && bulones[ib].codigo != codigo; ib++)
    {
       ;
    }

    if (ib < tamArreglo)
    {
    printf("Stock actual: %u >>> ", bulones[ib].stock);
       bulones[ib].stock = bulones[ib].stock - venta;
       printf("Stock Actualizado: %u \n", bulones[ib].stock);

       totalVenta = bulones[ib].precioUnitario * (double)venta;

       auditorias[ib].totalVendido = auditorias[ib].totalVendido + venta;
       auditorias[ib].totalRecaudado = auditorias[ib].totalRecaudado + totalVenta;
    }

    printf("TICKET:\nNombre bulon: %s \nPrecio Unitario: %f \nCantidad vendida: %u \n Monto total de la venta: %f \n",bulones[ib].nombre, bulones[ib].precioUnitario, venta ,totalVenta );

    
}

void cargaCodigosAuditoria(Auditoria auditorias[], Bulon bulones[],int tamanio)
{
    int j;
    for (j = 0; j < tamanio; j++)
    {
       auditorias[j].codigo = bulones[j].codigo;
       auditorias[j].totalRecaudado = 0;
       auditorias[j].totalVendido = 0;
    }
}