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

    int cantEnvios = 0;

    //Cargar
    //cargarProductos()
    //cargarPedidos()
    //cargarEnvios()
    //cargarClientes()
    cargarProductos(productos, TAM_ARREGLO);
    cargarPedidos(pedidos, TAM_ARREGLO);
    cargarCliente(clientes,TAM_ARREGLO);

    cantEnvios = generarEnvios(pedidos, productos, envios,clientes, TAM_ARREGLO);
    imprimirEnvios(envios, cantEnvios);

    
    

    

    

    //SEGUNDO EJERCICIO
    /*
    2.	Se desea saber a cuántos clientes no le pudo cumplir el pedido y el monto total que no se pudo recaudar con estas entregas
    */


   unsigned int noRecaudado = 0;
   unsigned int totalNoRecaudado = 0;
   unsigned int clientesNoSeCumplio = 0;
   int i3, i4, i5, m = 0;
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


int generarEnvios(Pedido pedidos[], Producto productos[],Envio envios[],Cliente clientes[], int tamanio)
{
    Envio envio;
    int ipe ,ipr, ic;
    int iev = 0;
    for (ipe = 0; ipe < tamanio && pedidos[ipe].idProducto; ipe++)
    {
        for (ipr = 0; ipr < tamanio && productos[ipr].idProducto != 0 ; ipr++)
        {
            if ((productos[ipr].idProducto == pedidos[ipe].idProducto))
            {
                if ((productos[ipr].cantidad <= pedidos[ipe].cantidad) && (productos[ipr].cantidad != 0))
                {
                    for (ic = 0; ic < tamanio && clientes[ic].idCliente != 0; ic++)
                    {
                        if (clientes[ic].idCliente == pedidos[ipe].idCliente )
                        {
                        // Actualizar productos
                        productos[ipr].cantidad = productos[ipr].cantidad - pedidos[ipe].cantidad;

                        // Crear envio
                        envio.idCliente = clientes[ic].idCliente;
                        strcpy(envio.nombre,clientes[ic].nombre);
                        strcpy(envio.telefono1,clientes[ic].telefono1);
                        strcpy(envio.telefono2,clientes[ic].telefono2);
                        envio.idProducto = productos[ipr].idProducto;
                        envio.cantidadEnviar = pedidos[ipe].cantidad;
                        envio.precioCosto = (productos[ipr].precioCosto * 1.21);    

                        //Carga de envios
                        envios[iev] = envio;
                        iev++;
                       
                        }
                        
                    }
                
               
                }
                else
                {
                    // SI NO HAY STOCK PARA EL PEDIDO. En teoria no deberia de entrar aca pero queda para validacion
                    printf("No hay stock del producto, asi que no se deberia haber podido realizar el pedido. Comunicarce con un supervisor\n");

                }
                
                
            }
            
        }
        
    }
    return iev;
}

void imprimirEnvios(Envio envios[], int tamEnvios)
{
    printf("ENVIOS:\n");
    int i2 = 0;
    for (i2 = 0; i2 < tamEnvios ; i2++)
    {
        printf("idCliente: %lu, nombre: %s, telefono1: %s, telefono2: %s, idProducto: %lu, Cantidad a enviar: %lu, precioCosto: %lu\n", envios[i2].idCliente, envios[i2].nombre, envios[i2].telefono1, envios[i2].telefono1, envios[i2].telefono2, envios[i2].cantidadEnviar, envios[i2].precioCosto);
    }
}
