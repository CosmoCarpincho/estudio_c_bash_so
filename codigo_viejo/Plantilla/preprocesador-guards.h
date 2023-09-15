// como guard no esta definido entra pero si despues otro archivo importa el .h no va a reemplazarlo porque guard esta definido por entrar una vez. Esto evita tener mas de un tipo, funcion declarada mas de una vez.

#if !defined GUARD
#define GUARD

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

#endif