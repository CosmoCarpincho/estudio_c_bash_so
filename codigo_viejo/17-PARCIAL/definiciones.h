#if !defined GUARD1
#define GUARD1
#define REGISTROS_SIN_PROCESAR 3

typedef struct movimiento
{
    unsigned int codLugar;
    unsigned int idProducto;
    unsigned int cantidad;

}Movimiento;

typedef struct stock
{
    unsigned int idProveedor;
    unsigned int idProducto;
    unsigned int disponible;
    unsigned int stock_minimo;
    double costo;
}Stock;

typedef struct pedido
{
    unsigned int idProveedor;
    unsigned int idProducto;
    unsigned int cantPedir;
}Pedido;

typedef struct auditoria
{
    unsigned int cantPedir;
    unsigned int sucursales[10];

}Auditoria;


void cargarStock(Stock array[], int tamanio);

#endif