#if !defined GUARD1
#define GUARD1
// Definicion de registos (struct) >>>

typedef struct producto {
    unsigned long   idProducto;
    unsigned long   cantidad;
    double  precioCosto;
    
}Producto;

typedef struct pedido {
    unsigned long    idCliente;
    unsigned long   idProducto;
    unsigned long     cantidad;
    
}Pedido;

typedef struct cliente {
    unsigned long    idCliente;
    char    nombre[20];
    char    direccion[30];
    char    correo[30];
    int    telefonos[6];
    
}Cliente;

typedef struct envio {
    unsigned    idCliente;
    char    nombre[20];
    int    telefonos[6];
    unsigned long   idProducto;
    unsigned long cantidadEnviar;
    double precioCosto;
    
}Envio;

// Definicion de metodos y funciones >>>

void cargarProductos(Producto array[], int tamanio);
void mostrarProductos(Producto arrProductos[], int tamanio);

void cargarPedidoss(Pedido array[], int tamanio);
void mostrarPedidos(Pedido arrPedidos[], int tamanio);

void procesarPedidos(Producto arrProductos[], int tamProd, Pedido arrPedidos[], int tamPed);
#endif
