#define CANT_REGISTROS_ARCHIVO 17
#define TAM_ARREGLO 17
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "cargarPedidos.c"
#include "cargarClientes.c"
#include "cargarProductos.c"

int main(int argc, char const *argv[])
{
    //struc
    // Producto producto;
    // Pedido pedido;
    Envio envio;
    // Cliente cliente;

    //Arreglos de struct
    Producto productos[TAM_ARREGLO];
    Pedido pedidos[TAM_ARREGLO];
    Envio envios[TAM_ARREGLO];
    Cliente clientes[TAM_ARREGLO];

    

    //Cargar
    //cargarProductos()
    //cargarPedidos()
    //cargarEnvios()
    //cargarClientes()
    cargarProductos(productos, TAM_ARREGLO);
    cargarPedidos(pedidos, TAM_ARREGLO);
    cargarCliente(clientes,TAM_ARREGLO);


    //PROBLEMA PRINCIPAL
    int i = 0;
    int k = 0;
    int j = 0;
    int m = 0; // indice del arreglo final de envios
    for (i = 0; (i < TAM_ARREGLO) && (productos[i].idProducto != 0); i++)
    {
        for (j = 0; (j < TAM_ARREGLO ) && (pedidos[j].idProducto != 0) ; j++)
        {
            if ((productos[i].idProducto == pedidos[j].idProducto) && (productos[i].cantidad <= pedidos[j].cantidad) && (productos[i].cantidad != 0))
            {
                for (k = 0; (k < TAM_ARREGLO) && (clientes[k].idCliente != 0); k++)
                {
                    if (clientes[k].idCliente == pedidos[j].idCliente )
                    {
                       envio.idCliente = clientes[k].idCliente;
                       strcpy(envio.nombre,clientes[k].nombre);
                       strcpy(envio.telefono1,clientes[k].telefono1);
                       strcpy(envio.telefono2,clientes[k].telefono2);
                       envio.idProducto = productos[i].idProducto;
                       envio.cantidadEnviar = pedidos[j].cantidad;
                       envio.precioCosto = (productos[i].precioCosto * 1.21);

                       //Carga de envios
                        envios[m] = envio;
                        m++;
                       
                    }
                    
                }

            }
            
        }
    }

    printf("ENVIOS:\n");
    int i2 = 0;
    for (i2 = 0; i2 < m ; i2++)
    {
        printf("idCliente: %lu, nombre: %s, telefono1: %s, telefono2: %s, idProducto: %lu, Cantidad a enviar: %lu, precioCosto: %lu\n", envios[i2].idCliente, envios[i2].nombre, envios[i2].telefono1, envios[i2].telefono1, envios[i2].telefono2, envios[i2].cantidadEnviar, envios[i2].precioCosto);
    }

    //SEGUNDO EJERCICIO
    /*
    2.	Se desea saber a cuántos clientes no le pudo cumplir el pedido y el monto total que no se pudo recaudar con estas entregas
    */


   unsigned int noRecaudado = 0;
   unsigned int totalNoRecaudado = 0;
   unsigned int clientesNoSeCumplio = 0;
   int i3, i4, i5 = 0;
   int mach = 0;
   
   for (i4 = 0; ((i4 < TAM_ARREGLO) && (clientes[i4].idCliente != 0)); i4++)
   {    
       printf("CLIENTE: %u , I4:%d\n",clientes[i4].idCliente, i4);
       mach = 0;
       for (i3 = 0; ((i3 < TAM_ARREGLO) && (pedidos[i3].idProducto != 0)); i3++)
       {   
            if ((productos[i3].idProducto == pedidos[i4].idProducto) )
            {
                for (i5 = 0; (i5 < m ) && (pedidos[i5].idProducto != 0); i5++) //Envios
                {
                    if (envios[i5].idCliente == clientes[i4].idCliente)
                    {
                        mach = 1;
                        //Realizo la venta
                    }
                }
            }
           
       }
       if (mach == 0)
       {
                        clientesNoSeCumplio++;
                        noRecaudado = pedidos[i5].cantidad * productos[i5].precioCosto;
                        totalNoRecaudado = totalNoRecaudado + noRecaudado;
                        printf("No pudo venderce al cliente: %u, la cantidad $%u\n", clientes[i5].idCliente, noRecaudado);
       }
   }

   printf("El total no recaudado es: %lu, y la cantidad de clientes que no se pudo cumplir: %lu", totalNoRecaudado, clientesNoSeCumplio);
   



    return 0;
}
