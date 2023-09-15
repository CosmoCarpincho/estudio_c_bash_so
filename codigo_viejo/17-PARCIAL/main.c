#define TAM_ARREGLO 30
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "cargarStocks.c"

int main(void)
{
    //struc
    // Producto producto;

    //Arreglos de struct
    //Producto productos[TAM_ARREGLO];

    Movimiento movimientos[TAM_ARREGLO];
    Stock stocks[TAM_ARREGLO];
    Pedido pedidos[TAM_ARREGLO];
    Auditoria auditoria;
    auditoria.cantPedir = 0;
    int ia;
    for (ia = 0; ia < 10; ia++)
    {
        auditoria.sucursales[ia] = 0;
    }
    
    

    //Cargar
    cargarStock(stocks, TAM_ARREGLO);
   
    int cantPedidos = 0;
    char opcion = 'x';
    while (opcion != 'q')
    {
        printf("\nMENU\n");
        printf("[1] cargar movimiento\n");
        printf("[2] realizar pedidos\n");
        printf("[3] cantidad productos a realizar el pedido\n");
        printf("[4] dinero que se recaudo por sucursal\n");
        printf("[q] salir\n");
        scanf("%c",&opcion);
        

        switch (opcion)
        {
            case '1':
            
                cargarMovimientos(movimientos,stocks, TAM_ARREGLO);
                break;

            case '2':

                cantPedidos = realizarPedidos(movimientos,stocks,pedidos,TAM_ARREGLO, cantPedidos, &auditoria);
                break;
            case '3':
                printf("Se van a realizar %u pedidos de producto \n", auditoria.cantPedir);
                break;

            case '4':
                printf("El dinero que se recaudo por sucursal\n");
                int i2;
                for (i2 = 0; i2 < 10; i2++)
                {
                     printf("%.2f", auditoria.sucursales[i2]);
                }
                
                break;
        
            default:
                break;
        
        }
        while (getchar() != '\n');
        
        
    }


    return 0;
}


void cargarMovimientos(Movimiento movimientos[], Stock stocks[], int tamanio)
{
    unsigned int idProd, cant, codLugar;


    printf("Ingrese el id del producto que se realizo el movimiento: ");
    scanf("%u",&idProd);
    printf("Ingrese la cantidad: ");
    scanf("%u", &cant);
    printf("Ingrese el codigo del lugar al que se realizo el movimiento: ");
    scanf("%u",&codLugar);
    printf("\n");

    int im, is;
    for (im = 0; im < tamanio && movimientos[im].idProducto != 0; im++)
    {
        ; //Se recorre para cargar al final del arreglo
    }

    if (im != tamanio)
    {
        movimientos[im].idProducto = idProd;
        movimientos[im].codLugar =codLugar;
        movimientos[im].cantidad = cant;

        printf("Cargo el siguiente movimiento\n");
        printf("idProducto: %u, codLugar: %u , cantidad :%u\n",movimientos[im].idProducto, movimientos[im].codLugar,movimientos[im].cantidad);

        for (is = 0; is < tamanio && stocks[is].idProducto != 0; is++)
        {
            if (movimientos[im].idProducto == stocks[is].idProducto)
            {
                if (stocks[is].disponible > cant)
                {
                    stocks[is].disponible = stocks[is].disponible - cant;
                    printf("Nuevo stock: %u\n",stocks[is].disponible );
                }
                else
                {
                    printf("No se puede hacer un movimiento con esa cantidad\n");
                }
                
                
                
            }
            
        }
        
        
    }

    
}

int realizarPedidos(Movimiento movimientos[], Stock stocks[], Pedido pedidos[], int tamanio, int ip, Auditoria* auditoria)
{
    printf("PEDIDOS\n");
    int im, is;
    for (im = 0; im < tamanio && movimientos[im].idProducto != 0; im++)
    {
        for (is = 0; is < tamanio && stocks[is].idProducto != 0 ; is++)
        {
            if (movimientos[im].idProducto == stocks[is].idProducto)
            {
               if ( stocks[is].disponible < ((stocks[is].stock_minimo)* 0.5))
                {
                    pedidos[ip].idProducto = movimientos[im].idProducto;
                    pedidos[ip].idProveedor = stocks[is].idProveedor;
                    pedidos[ip].cantPedir = pedidos[ip].cantPedir + movimientos[im].cantidad;
                    
ip++;
                    printf("=>\n");
                    printf("Proveedor: %u, Producto: %u, Cantidad: %u\n",pedidos[ip].idProducto,pedidos[ip].idProveedor,pedidos[ip].cantPedir);

                    //Ejercicio 2
                    auditoria->cantPedir = auditoria->cantPedir + pedidos[ip].cantPedir;
                    
                    unsigned int dinero = (double)pedidos[ip].cantPedir * stocks[is].costo;
                    auditoria->sucursales[movimientos[im].codLugar] = auditoria->sucursales[movimientos[im].codLugar] + dinero;
                }
                else
                {
                    /* code */
                }
            }
        }
    }

    return ip;
}

// void cantProductos()
// {
//     int auditoria[TAM_ARREGLO];

//     for (j = 0; j < TAM_ARREGLO; j++)
//     {
//        auditoria[j] = 0; // Cargo un vector con ceros
//     }
    
//     int ipe;
//     for (ipe = 0; ipe < count; ipe++)
//     {
//        int i;
//        for (i = 0; i < TAM_ARREGLO && (pedidos[ipe].idProducto != auditoria[ipe]); i++)
//        {
//            ; // Solo para hacer 
//        }
               
//        if (/* condition */)
//        {
//            /* code */
//        }
       

       
        
// //     }
    
// }

