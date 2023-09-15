#define TAM_ARREGLO 50
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "cargarVenta.c"
#include "cargarStock.c"

int main(void)
{
    //struc
    // Producto producto;
    //Venta venta;
    //Stock stock;
    //Pedido pedido;


    //Arreglos de struct
    //Producto productos[TAM_ARREGLO];
    Venta ventas[TAM_ARREGLO];
    Stock stocks[TAM_ARREGLO];
    Pedido pedidos[TAM_ARREGLO];


    //Cargar los datos se cargan en arreglos de tamanio fijo. Para saber cuando  es el ultimo dato se recorre hasta encontrace con un cero
    //cargarDATOS(dato, TAM_ARREGLO )
    cargarVenta(ventas, TAM_ARREGLO);
    cargarStock(stocks, TAM_ARREGLO);

    procesarStock(ventas, stocks, TAM_ARREGLO);
    generarPedidos(stocks, pedidos, TAM_ARREGLO);
    mostrarPedidos(pedidos, TAM_ARREGLO);
    auditoria(pedidos, TAM_ARREGLO);

    return 0;
}


// procesar stocks - ventas

    void procesarStock (Venta ventas[], Stock stocks[], int tam_arreglo)
    {
        //recorro ventas y actualizo stocks
        int iv;
        for (iv = 0;  ventas[iv].idProducto != 0 && iv < tam_arreglo ; iv++)
        {
            int is;
            for (is = 0; is < tam_arreglo && stocks[is].idProducto != 0 ; is++)
            {
                if (ventas[iv].idProducto == stocks[is].idProducto)
                {
                    stocks[is].stock = stocks[is].stock - ventas[iv].cantidad;
                }
                
            }
               
        }
        
    }



// Generar lista de pedidos
void generarPedidos(Stock stocks[], Pedido *pedidos, int tamanio_arr)
   {
       Pedido pedido;
    int is;
    int ip = 0;
    for (is = 0; is < tamanio_arr && stocks[0].idProducto != 0 ; is++)
    {   
        if (stocks[is].stock < stocks[is].stockCritico)
        {
            pedido.cantidadPedir = stocks[is].stockMaximo - stocks[is].stock;
            pedido.idProducto = stocks[is].idProducto;
            pedido.idProveedor = stocks[is].idProveedor;
            pedido.precioCosto = stocks[is].precioCosto;

            pedidos[ip] = pedido;
            ip++;
        }
        
    }

   }

//mostrar pedidos
    void mostrarPedidos(Pedido pedidos[], int tam_arreglo)
    {
        int ip;
        for (ip = 0; ip < tam_arreglo && pedidos[ip].idProducto != 0 ; ip++)
        {
            printf("Los pedidos a realizar son:\n");
            printf("IdProducto: %u , IdProveedor:%u Cantidad a pedir: %u\n", pedidos[ip].idProducto, pedidos[ip].idProveedor, pedidos[ip].cantidadPedir);
        }

    }


    //EJe dos

    void auditoria( Pedido pedidos[], int tam_arreglo)
    {
        unsigned int idProveedoresAux_arr[tam_arreglo];

        // Inicializa el arreglo auxiliar con todos valores 0
        int j2;
        for (j2 = 0; j2 < tam_arreglo; j2++)
        {
            idProveedoresAux_arr[j2] = 0;
        }
        

        int ip;
        int existe;
        int cantidad = 0;
        for (ip = 0; ip < tam_arreglo && pedidos[ip].idProducto != 0 ; ip++)
        {
            existe = 0;
            int iaux;
            for (iaux = 0; iaux < tam_arreglo && idProveedoresAux_arr[iaux] != 0 && existe != 0; iaux++)
            {
                if (pedidos[ip].idProveedor == idProveedoresAux_arr[iaux])
                {
                    existe = 1;
                }
                
            }

            if (existe == 0)
            {
                idProveedoresAux_arr[iaux] = pedidos[ip].idProveedor;
                cantidad++;

            }
            
            printf("id: %u\n",idProveedoresAux_arr[iaux] );
        }

        int it;
        double totalDesembolsar = 0;
        for (it = 0; it < tam_arreglo && pedidos[it].idProducto != 0; it++)
        {
            totalDesembolsar = totalDesembolsar + (pedidos[it].cantidadPedir * pedidos[it].precioCosto);
        }
        

        printf("Se le van a realizar los pedidos a %d proveedores.\n", cantidad);
        printf("La cantidad a desembolsar es: %.2f\n", totalDesembolsar);
    }