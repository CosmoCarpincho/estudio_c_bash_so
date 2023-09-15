#include <stdio.h>
#include <stdlib.h>

typedef struct datoLista
{
    int numero;
}datoLista;

typedef struct nodoLista
    {
        datoLista dato;
        struct nodoLista * sig;
    }nodoLista;


void crearListaVacia (nodoLista ** cabezaLista);
void mostrarElementosLista (nodoLista ** cabezaLista);
void insertarPrincipioLista (nodoLista ** cabezaLista, datoLista datoL);
void insertarFinalLista (nodoLista ** cabezaLista, datoLista dato);
void eliminarElementoLista(nodoLista **cabezaLista, int idEliminar);


int main(void)
{
    nodoLista * cabezaLista;
    
    datoLista datoL = {1};
    datoLista datoL2 = {2};
    datoLista datoL3 = {3};
    datoLista datoL4 = {4};

    crearListaVacia(&cabezaLista);
    insertarPrincipioLista(&cabezaLista, datoL);
    insertarPrincipioLista(&cabezaLista, datoL2);
    insertarFinalLista(&cabezaLista, datoL3);
    insertarOrdenado(&cabezaLista, datoL4);
    eliminarElementoLista(&cabezaLista, 7);

    mostrarElementosLista(&cabezaLista);
    
    return 0;
}

void crearListaVacia (nodoLista ** cabezaLista)
{
    (*cabezaLista) = NULL;
}

void mostrarElementosLista (nodoLista ** cabezaLista)
{
    nodoLista * aux = (*cabezaLista);

    while ( aux != NULL)
    {
        printf("| %d | ", aux->dato.numero);

        aux = aux->sig;
    }
    
}

void insertarPrincipioLista (nodoLista ** cabezaLista, datoLista datoL)
{
    nodoLista *nuevo = (nodoLista *) malloc(sizeof(nodoLista));
    nuevo->dato = datoL;
    
    nuevo->sig = (*cabezaLista);
    (*cabezaLista) = nuevo;

}

void insertarFinalLista (nodoLista ** cabezaLista, datoLista dato)
{
    nodoLista *nuevo,*actual;
    nuevo = (nodoLista *) malloc(sizeof(nodoLista));
    
    nuevo->dato = dato;
    nuevo->sig = NULL;

    actual = (*cabezaLista);

    if ((*cabezaLista) == NULL)
    {
        (*cabezaLista) = nuevo;
    }
    else
    {
        while (actual->sig != NULL)
        {
            actual = actual->sig;
        }
        actual->sig = nuevo;
    }
}

void insertarOrdenado(nodoLista ** cabezaLista, datoLista dato)
{
    nodoLista *nuevo, *actual, *anterior;
    nuevo = (nodoLista *) malloc(sizeof(nodoLista));

    nuevo->dato = dato;
    actual = (*cabezaLista);
    anterior = NULL;

    while (actual != NULL && actual->dato.numero != 3) // Insertar antes de el numero 3
    {
        anterior = actual;
        actual = actual->sig;
    }

    if (anterior != NULL)
    {
        anterior->sig = nuevo;
        nuevo->sig = actual;
    }
    else
    {
        nuevo->sig = (*cabezaLista);
        (*cabezaLista) = nuevo;
    }
    
}

void eliminarElementoLista(nodoLista ** cabezaLista, int idEliminar)
{
    nodoLista *actual, *anterior;

    actual = (*cabezaLista);
    anterior = NULL;

    while (actual != NULL && actual->dato.numero != idEliminar)
    {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual != NULL)
    {
        if (anterior != NULL)
        {
            anterior->sig = actual->sig;
        }
        else
        {
            (*cabezaLista) = actual->sig;
        }
            free(actual);
    }
    
} 




