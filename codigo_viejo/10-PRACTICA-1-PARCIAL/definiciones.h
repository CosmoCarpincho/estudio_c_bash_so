#if !defined GUARD1
#define GUARD1
#define REGISTROS_SIN_PROCESAR 3

typedef struct venta
{
    unsigned int codSucursal;
    unsigned int idProducto;
    unsigned int cantidad;
} Venta;

typedef struct stock
{
    unsigned int idProveedor;
    unsigned int idProducto;
    unsigned int stock;
    unsigned int stockCritico;
    unsigned int stockMaximo;
    unsigned int precioCosto;
} Stock;

typedef struct pedido
{
    unsigned int idProveedor;
    unsigned int idProducto;
    unsigned int cantPedir;
    unsigned int precioCosto;
} Pedido;

// Stock - Ventas
// Pide faltantes
void cargarVentas(Venta array[], int tamanio);
void cargarStocks(Stock array[], int tamanio);





#endif