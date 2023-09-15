#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definiciones para el preprocesador. En vez de usar typedef sustituyo las palabras desde el preprocesador
#define Servicio struct servicio 
#define TAMSERVICIOS 6

//#define Pedido struct pedido //1#
#define Nodo struct nodo //#2
#define Pila struct nodo

// Structs
struct servicio {
    char tipo [30];
    unsigned int precio;
};

//#1
typedef struct pedido {
    unsigned int codCliente;
    char servicio [30];
    unsigned int cantidad;
} Pedido ;

//#2

struct nodo {
    Pedido pedido;
    struct nodo * nodoSig;
};

void cargarPedido (Pedido  * pedido);
void crearPilaVacia(Pila **pila);
Nodo * crearNodo(Pedido pedido);
void apilar ( Pila** pila, Pedido pedido);
Nodo * desapilar (Nodo ** pila);

int main(void)
{
    // Arreglo dinamico.
    Servicio * listServicios = (Servicio *) malloc(TAMSERVICIOS * sizeof(Servicio));

    Servicio ser;
    
    char tiposServicios[6][30] = {"Lavanderia","Pantalones","Trajes","Secado","Servicio A", "Servicio B"};
    
    int i1;
    for ( i1 = 0; i1 < TAMSERVICIOS; i1++)
    {
        strcpy(ser.tipo, tiposServicios[i1]);
        ser.precio = 1233 * (i1 +1.3);
        
        listServicios[i1] = ser;
        
    }
    
    int i2;
    for ( i2 = 0; i2 < TAMSERVICIOS; i2++)
    {
        printf("Servicio: %s , precioL %u\n", listServicios[i2].tipo, listServicios[i2].precio);
    }
    
    
    //Creamos pila vacia
    // Nodo * pila = crearPilaVacia();
    Pila * pila;
    crearPilaVacia(&pila);

    Pedido pedidoAux;
    Nodo * auxPila;
    Nodo * auxNodo;

    char opcion = 'x';
    int desp15 = 0;
    while (opcion != 'q')
    {
        printf("\nMENU\n");
        printf("[1] Realizar Pedido \n");
        printf("[2] Ya paso las 15 hs. (usar esta opcion para habilitar las siguietes)\n");
        printf("[3] \n");
        printf("[4] \n");
        printf("[q] salir\n");
        scanf("%c",&opcion);
        

        switch (opcion)
        {
            case '1':
                cargarPedido(&pedidoAux);
                apilar(&pila, pedidoAux);
                
                break;

            case '2':
                desp15 = 1;

                break;
            case '3':
            if (desp15 == 1)
            {
               //Desapilar y generar lista de trabajo con codCliente, servicio, cantPrendas, monto a abonar
                //Desapilo y voy mostrando los datos??  // para no perder los datos los apilo en otra pila. QUedando invertidos??
                // Las pilas no se pueden recorrer porque sino ya pasaria a ser una lista condeptualmente

                
                crearPilaVacia(&auxPila);
                //desapilar(&pila);

                auxNodo = desapilar(&pila);
                pedidoAux = auxNodo->pedido;

                apilar(&auxPila, pedidoAux);
            }
            
                

                


                break;

            case '4':
                
                break;
        
            default:
                break;
        
        }
        while (getchar() != '\n');
        
        
    }
   

   //Liberar la memoria
   free(listServicios);

    return 0;
}


//Pila que tenga structs con codCliente, servicio, cantPrendas. Son los pedidos. Cada Nodo es un pedido.
//Primero datos crear el struc #1
//Crear el nodo de la pilas que es otro struct #2


void cargarPedido(Pedido  * pedido)
{

    printf("Numero de cliente:");
    scanf("%u",&(pedido->codCliente));
    
    printf("Ingrese el servicio:\nOpciones:\n Lavanderia,Pantalones,Trajes,Secado,Servicio A, Servicio B\n");
    scanf("%s",(pedido->servicio));
    
    printf("Ingrese cantidad");
    scanf("%u",&pedido->cantidad);
    
}

// Crear pila vacia
void crearPilaVacia(Pila **pila)
{
    *pila = NULL;
}

// Crear Nuevo nodo

Nodo * crearNodo(Pedido pedido)
{
    Nodo * nodo = (Nodo *) malloc (sizeof(Nodo));
    nodo->pedido = pedido;
    nodo->nodoSig = NULL;
    
    return nodo;
}

// Apilar

void apilar( Pila** pila, Pedido pedido){

    Nodo * nuevoNodo = crearNodo(pedido);

    if ((*pila) == NULL)
    {
        *pila = nuevoNodo;
    }
    else
    {
        nuevoNodo->nodoSig = (*pila);
        (*pila) = nuevoNodo; 
    }
    
    
}

Nodo * desapilar (Nodo ** pila)
{
    Nodo *aux = (*pila);
    (*pila) = (*pila)->nodoSig; //Desapilo
    (*aux).nodoSig = NULL; //Quito el enlace entre los nodos; Para que quede un nodo suelto

    return aux;

}



