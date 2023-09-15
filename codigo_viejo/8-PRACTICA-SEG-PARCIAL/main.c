#define CANT_REGISTROS 23
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "implementaciones.c"
#include "cargaPedidos.c"

int main(void)
{
    Producto arrProductos[CANT_REGISTROS];
    Pedido arrPedidos[CANT_REGISTROS];

    //cargarProductos(arrProductos, CANT_REGISTROS);
    cargarPedidos(arrPedidos, CANT_REGISTROS);

    printf("COMPILA");
    //printf("\nPrimer registro: %lu, %lu, %d\n", arrProductos[0].idProducto, arrProductos[0].cantidad, arrProductos[0].precioCosto);
    printf("\nPEDIDOS: Primer registro: %lu, %lu, %lu\n", arrPedidos[0].idClientes, arrPedidos[0].idProducto, arrPedidos[0].cantidad);
    return 0;
}
