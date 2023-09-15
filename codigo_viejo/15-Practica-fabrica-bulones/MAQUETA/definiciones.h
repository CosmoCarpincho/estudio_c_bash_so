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

typedef struct bulon
{
    unsigned int codigo;
    char nombre[50];
    unsigned int stock;
    double precioUnitario;
}Bulon;

typedef struct auditoria
{
    unsigned int codigo;
    unsigned int totalVendido;
    double totalRecaudado;
}Auditoria;



void cargarBulon(Bulon array[], int tamanio);

#endif