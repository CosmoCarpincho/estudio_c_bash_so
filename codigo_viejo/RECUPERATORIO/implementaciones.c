// Implementacion de funciones
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //gestionar memoria dinamica ej: malloc()
#include <time.h>


void cargarProductos(Producto array[], int tamanio)
{       time_t t;
        srand((unsigned) time(&t));
        Producto producto;
        
        int i;
        for (i = 0; i < tamanio; i++)
        {   
            producto.idProducto = i + 1;
            producto.cantidad = rand() % (1001);
            producto.precioCosto= ((rand()  ) / 10.0);
            array[i] = producto; 

            // printf("- IdProducto: %20lu -\n- Cantidad: %22lu -\n- PrecioCosto: %19.2lf -\n", producto.idProducto, producto.cantidad, producto.precioCosto);
            // printf("-                                  -\n");
        }
        
}

void mostrarProductos(Producto arrProductos[], int tamanio)
{
    
    int i;
    printf("\n\n== PLANILLA DE PRODUCTOS QUE SON ENVIADOS AL DEPOSITO  ==\n\n");
    for (i = 0; i < tamanio; i++)
    {   
        printf("- IdProducto: %20lu -\n- Cantidad: %22lu -\n- PrecioCosto: %19.2lf -\n", arrProductos[i].idProducto, arrProductos[i].cantidad, arrProductos[i].precioCosto);
        printf("-                                  -\n");
    }

}



void cargarPedidoss(Pedido array[], int tamanio)
{       time_t t;
        srand((unsigned) time(&t));
        Pedido pedido;
        
        int i;
        for (i = 0; i < tamanio; i++)
        {   
            pedido.idCliente = rand() % (101);
            pedido.idProducto = rand() % (tamanio);
            pedido.cantidad= rand() % (1001);
            array[i] = pedido; 

            // printf("- IdCliente: %21lu -\n- IdProducto: %20lu -\n- Cantidad: %22lu -\n", pedido.idCliente, pedido.idProducto, pedido.cantidad);
            // printf("-                                  -\n");
        }
        
}

void mostrarPedidos(Pedido arrPedidos[], int tamanio)
{
    
    int i;
    printf("\n\n== LISTA DE PEDIDOS DE CLIENTES  ==\n\n");
    for (i = 0; i < tamanio; i++)
    {   
        printf("- IdCliente: %21lu -\n- IdProducto: %20lu -\n- Cantidad: %22lu -\n", arrPedidos[i].idCliente, arrPedidos[i].idProducto, arrPedidos[i].cantidad);
        printf("-                                  -\n");
    }

}


void procesarPedidos(Producto arrProductos[], int tamProd, Pedido arrPedidos[], int tamPed)
{
    int i = 0;
    int flag = 1;
    while (i < tamProd && flag == 1)
    {
        Producto paux = arrProductos[i];
        int j = 0;
        for ( j = 0; i < tamPed; j++)
        {
            if (arrProductos[i].idProducto == arrPedidos[j].idProducto)
        {

            if (arrProductos[i].cantidad < arrPedidos[j].cantidad)
            {
                printf("No se puede tomar el pedido: %ul\n\n ",arrProductos[i].idProducto );
            }
            


            flag == 0; // o puedo salir con el continue
        }

        }
        
        
        
        i++;
    }
    
}
