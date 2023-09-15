/*
Se tiene una lista de precios de productos vendidos en Carrefour y otra lista con los precios de
los mismos productos vendidos en Disco. Se desea obtener una tercera lista con los nombres de
cada uno de los productos y el nombre del supermercado donde me conviene comprarlos.

*/

#include <stdio.h>
#include <string.h>

typedef struct nSuper
{
    char producto[30];
    unsigned int precio;
    struct nSuper *sig;
} ListaSupermercado;

typedef struct nConsolidado
{
    char producto[30];
    char nombreSuper[30];
    unsigned int precio;
    struct nConsolidado *sig;
} ListaConsolidada;


ListaSupermercado *ListaVaciaSupermercado(ListaSupermercado *cabeza)
{
    cabeza = NULL;
    return cabeza;
}

ListaConsolidada *ListaVaciaConsolidada(ListaConsolidada *cabeza)
{
    cabeza = NULL;
    return cabeza;
}


ListaSupermercado *ListaAgregarSupermercado(ListaSupermercado *cabeza, char producto[30],unsigned int precio)
{

    ListaSupermercado *nuevo, *aux;
    nuevo = (ListaSupermercado*)malloc(sizeof(ListaSupermercado));

    strcpy(nuevo->producto,producto);
    nuevo->precio = precio;
    nuevo->sig = NULL;

    if(cabeza == NULL)
    {
        cabeza = nuevo;
    }
    else
    {
        aux = cabeza;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        
        aux->sig = nuevo;
    }

    return cabeza;
}


void Ver(ListaSupermercado *cabeza){
	
	while (cabeza!=NULL)
	{
		printf("Producto: %s \n", cabeza->producto);
        printf("Precio: %d \n", cabeza->precio);
		cabeza = cabeza->sig;
	}
}

void Ver(ListaConsolidada *cabeza){
	
	while (cabeza!=NULL)
	{
		printf("Producto: %s \n", cabeza->producto);
        printf("Precio: %u \n", cabeza->precio);
        printf("Sucursa:%s \n", cabeza->nombreSuper)
		cabeza = cabeza->sig;
	}
}

ListaSupermercado *CompararListas(ListaSupermercado *cabezaCarregour, ListaSupermercado *cabezaDisco)
{

// creacion de Nodo

	ListaSimple *nuevo, *anterior, *actual;
	
	//nuevo= (ListaSimple*)malloc(sizeof(ListaSimple)); // reservo el espacio para el tipo ListaSimple
//	nuevo->nombre= dato;
	
	actual=Cabeza;
	anterior=NULL;

	// en el caso que se no NULL tengo que recorrer la lista hasta el final
	
	while (actual!=NULL && actual->nombre!=dato)
		{
			anterior=actual;
			actual=actual->sig;
		}
	
	if ( actual!=NULL){
		
		 
		 	actual->nombre=valornuevo;
		 }
		 else
		 {
		 	printf("No existe el Dato!!! \n");
		 }
		 
			
		
	return Cabeza;
}


int main(int argc, char const *argv[])
{
    
    ListaSupermercado carrefour;
    ListaSupermercado disco;

    ListaVaciaSupermercado(carrefour);
    ListaVaciaSupermercado(disco);

    int sigue = 1;
    unsigned int precio;
    char producto[30];

    while (sigue == 1)
    {
        printf("Ingres nombre producto\n");
        scanf("%s", &producto);
        printf("Ingrese precio producto\n");
        scanf("%u", &precio);

        carrefour.producto = 
    }
    
    

    return 0;
}
