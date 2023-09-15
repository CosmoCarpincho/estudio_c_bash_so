#if !defined GUARD1
#define GUARD1
// Definicion de estructuras y funciones

//definicion de struct

typedef struct registro {
    unsigned  idproducto;
    int       codsucursal;
    long       cantidad;
    
}Registro;

//Registro array[CANT_REGISTROS];

//definicion de los metodos
void alta(Registro array[] , int tamanio);
int baja(Registro * array, int tamanio);
void modificacion(Registro * array, int tamanio);

void cargarRegistros(Registro array[], int tamanio);
void mostrarRegistros(Registro array[], int tamanio);
#endif
