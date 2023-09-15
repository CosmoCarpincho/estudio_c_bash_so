#if !defined GUARD1
#define GUARD1

#define PRIMER_REGISTRO 0
#define SEGUNDO_REGISTRO 1
#define REGISTROS_SIN_PROCESAR 3

// Defincion de los registros (struct) >>>

typedef struct producto{
    unsigned int idProducto;
    unsigned int cantidad;
    int precioCosto;
} Producto;

typedef struct pedido
{
    unsigned long idClientes;
    unsigned long idProducto;
    unsigned long cantidad;
} Pedido;

typedef struct cliente
{
    unsigned long idCliente;
    char nombre[20];
    char direccion[30];
    char correo[30];
    unsigned int telefonos[6];
} Cliente;

typedef struct envio
{
    unsigned long idCliente;
    char nombre[20];
    unsigned int telefonos[6];
    unsigned long idProducto;
    unsigned long cantidadEnviar;
    double precioCosto;
} Envio;

// Definicion de metodos y funciones >>>

void cargarProductos(Producto array[], int tamanio);
void cargarPedidos(Pedido array[], int tamanio);



#endif