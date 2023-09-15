#if !defined GUARD1
#define GUARD1
#define REGISTROS_SIN_PROCESAR 3

typedef struct producto
{
    unsigned int idProducto;
    unsigned int cantidad;
    unsigned int precioCosto;
} Producto;


typedef struct pedido
{
    unsigned int idCliente;
    unsigned int idProducto;
    unsigned int cantidad;

} Pedido;

typedef struct envio
{
    unsigned int idCliente;
    char nombre[50];
    char telefono1[50];
    char telefono2[50];
    unsigned int idProducto;
    unsigned int cantidadEnviar;
    unsigned int precioCosto;
} Envio;


typedef struct cliente
{
    unsigned int idCliente;
    char nombre[50];
    char direccion[50];
    char correo[50];
    char telefono1[50];
    char telefono2[50];

} Cliente;

void cargarProductos(Producto array[], int tamanio);
void cargarPedidos(Pedido array[], int tamanio);
void cargarCliente(Cliente array[], int tamanio);

#endif