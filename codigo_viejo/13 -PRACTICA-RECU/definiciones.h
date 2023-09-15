#if !defined GUARD1
#define GUARD1
#define REGISTROS_SIN_PROCESAR 3

// typedef struct producto
// {
//     unsigned int idProducto;
//     unsigned int cantidad;
//     unsigned int precioCosto;
//     char nombre[50];
// } Producto;

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
     float precioCosto;

} Stock;

typedef struct pedido
{
     unsigned int idProveedor;
     unsigned int idProducto;
     unsigned int cantidadPedir;
     float precioCosto;

} Pedido;


void cargarVenta(Venta array[], int tamanio);
void cargarStock(Stock array[], int tamanio);

#endif