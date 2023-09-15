#define TAM_ARREGLO 50
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "cargarVentas.c"
#include "cargarStocks.c"

int main(void)
{
    //struc
   // Venta venta;
   //Stock stock;
    Pedido pedido;

    //Arreglos de struct
    //Producto productos[TAM_ARREGLO];
    Venta ventas[TAM_ARREGLO];
    Stock stocks[TAM_ARREGLO];
    Pedido pedidos[TAM_ARREGLO];


    //Cargar
    cargarVentas(ventas,  TAM_ARREGLO);
    cargarStocks(stocks, TAM_ARREGLO);

    long int resultadoStock = 0;
    unsigned int cantidadPedir = 0;
    unsigned int montoTotal = 0;

    int iv, is, ip = 0;  // indices venta stock pedido
    for ( iv = 0; (iv < TAM_ARREGLO) && ventas[iv].idProducto != 0; iv++)
    {
        for (is = 0; (is < TAM_ARREGLO) && stocks[is].idProducto != 0; is++)
        {
            if (ventas[iv].idProducto == stocks[is].idProducto)
            {
                resultadoStock = stocks[is].stock - ventas[iv].cantidad;

                if (resultadoStock >= 0 )
                {
                    if (stocks[is].stockCritico > resultadoStock)
                    {
                        cantidadPedir = stocks[is].stockMaximo - resultadoStock;
                        printf("Se va a pedir para el producto: %u  %u para reponer el stock\n",stocks[is].idProducto, cantidadPedir );

                        pedido.idProveedor = stocks[is].idProveedor;
                        pedido.idProducto = stocks[is].idProducto;
                        pedido.cantPedir = cantidadPedir;
                        pedido.precioCosto = stocks[is].precioCosto;

                        pedidos[ip] = pedido;
                        ip = ip + 1;

                        // EJERCICIO 2 MONTO TOTAL

                        montoTotal = montoTotal + (cantidadPedir * stocks[is].precioCosto );

                    }
                                        
                }
                else
                {
                    //No deberia entrar aca porque la venta ya se hiso entonces se reviso el stock pero
                    // lo dejo como una "validacion"
                    printf("No hay suficiente stock para realizar la venta.Comuniquese con el genrente\n");
                }
                
                
            }
            
        }
        
    }
    

    

   //printf("El total no recaudado es: %lu, y la cantidad de clientes que no se pudo cumplir: %lu", totalNoRecaudado, clientesNoSeCumplio);
   

    //EJERCICIO 2
    int ix;
    unsigned int arr_provedores[TAM_ARREGLO];
    for (ix = 0; ix < TAM_ARREGLO; ix++)
    {
        arr_provedores[ix] = 0;
    }
    

    int ip2 = 0; // Indice para recorrer pedidos
    int iprov = 0; // Indice de array de proveedores
    int encontro = 0;
    int cantProveedores = 0;

    for ( ip2 = 0; ip2 < ip; ip2++)
    {
        iprov = 0;
        //Primera vez que entra
         if (arr_provedores[iprov] == 0)
        {
            arr_provedores[iprov] = pedidos[ip2].idProveedor;
            cantProveedores = cantProveedores + 1;
        }

        // Si ya tiene proveedores el arreglo para ver que no se repita
        for (iprov = 0; (iprov < TAM_ARREGLO) && arr_provedores[iprov] != 0; iprov++)
        {
            if (pedidos[ip2].idProveedor == arr_provedores[iprov])
            {
                encontro = 1;
            }
            
        }

        if (!encontro)
        {
            arr_provedores[iprov] = pedidos[ip2].idProveedor;
            cantProveedores = cantProveedores + 1;
        }
        
    }
    
    int size = sizeof arr_provedores / sizeof arr_provedores[0];
    int j;

    printf("Cantidad de proveedores %i y sus idProveedor:\n", cantProveedores);
    for (j = 0; (j < size) && arr_provedores[j] != 0; j++)
    {
        printf("id : %u\n",arr_provedores[j] );
    }
    
    // Ejercicio 2 Monto total

    printf("Monto total a pedir: %u , para reponer stock\n", montoTotal);

    return 0;
}
