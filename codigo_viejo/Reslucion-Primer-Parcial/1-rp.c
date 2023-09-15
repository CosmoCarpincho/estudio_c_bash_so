#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//rand() http://www.chuidiang.org/clinux/funciones/rand.php
// time_t t;
// srand((unsigned) time(&t));
//numero = rand () % (N-M+1) + M;   // Este está entre M y N

#define CANT_REGISTROS 5

typedef struct venta
   {
        unsigned  idproducto;
        int       codsucursal;
        long       cantidad;
            
   } Venta;

typedef struct stock
    {
        unsigned    idproveedor;
        unsigned    idproducto;
        long        stock;
        unsigned    stockCritico;
        unsigned    stockMaximo;
        long        precioCosto;
        
    } Stock;

void cargaVentas(Venta planillaVentas[] , int tamnioRegistro);
void mostrarVentas(Venta planillaVentas[], int tamnioRegistro);


int main(int argc, char const *argv[])
{
    
    /*
        ventas
            idproducto
            codsucursal
            cantidad

        consolidacion-stock
            idproveedor
            idproducto
            stock
            stock-critico
            stock-maximo
            precio-costo

            Area de compras realiza un procesamientos de ambas planillas consolidadndo la informacion del stock en funcion de los movimientos de venta que se registraron en la planilla compartida

            stock << Mov ventas

            1)
            SOLO los que tienen un stock < stock-critico
            generar lista de pedido a proveedores
                idproveedor
                idproducto
                cantidad-a-pedir stockmaximo-stock
                precio-costo
            
            2) auditoria nos pide
                1 cant proveedores que se le realiza el pedido
                2 monto total para desembolsar para realizar la reposicion del stock

            Las planillas tienen una dimension de hasta 100000 registros


    */
   

   
    
   
    Venta venta;
    Stock stock;

    Venta planillaVentas[CANT_REGISTROS];
    Stock planillaConsolidacionStock[CANT_REGISTROS];

    

    
    
    cargaVentas(planillaVentas, CANT_REGISTROS);

    mostrarVentas(planillaVentas, CANT_REGISTROS);

    


    return 0;
}

void cargaVentas(Venta planillaVentas[] , int tamnioRegistro)
{       time_t t;
        srand((unsigned) time(&t));
        Venta v1;
        
        int i;
        for (i = 0; i < tamnioRegistro; i++)
        {   
            v1.idproducto = i + 1;
            v1.cantidad = rand() % (1001);
            v1.codsucursal= rand() % (101);
            planillaVentas[i] = v1; 

            //printf("- IdProducto: %20u -\n- Cantidad: %22d -\n- CodSucursal: %19ld -\n", v1.idproducto, v1.cantidad, v1.codsucursal);
            //printf("-                                  -\n");
        }
        
       
        
}

void mostrarVentas(Venta planillaVentas[], int tamnioRegistro)
{
    
    int i;
    printf("\n\n== PLANILLA VENTAS 2 ==\n\n");
    for (i = 0; i < tamnioRegistro; i++)
    {   
        printf("- IdProducto: %20u -\n- Cantidad: %22d -\n- CodSucursal: %19ld -\n", planillaVentas[i].idproducto, planillaVentas[i].cantidad, planillaVentas[i].codsucursal);
        printf("-                                  -\n");
    }

}
