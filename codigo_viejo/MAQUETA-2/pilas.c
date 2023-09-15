#include <stdio.h>
#include <stdlib.h>

typedef struct datoPila
{
    int numero;
}datoPila;

typedef struct nodoPila
    {
        datoPila dato;
        struct nodoPila * sig;
    }nodoPila;


void crearPilaVacia (nodoPila ** cabezaPila);
void apilar(nodoPila ** cabezaPila, datoPila dato);
void desapilar(nodoPila ** cabezaPila, datoPila * dato);
int esVaciaPila(nodoPila ** cabezaPila);


int main(void)
{
    nodoPila * cabezaPila;
    
    datoPila datoP = {1};
    datoPila datoP2 = {2};
    datoPila datoP3 = {3};
    datoPila datoP4 = {4};

    datoPila auxDato;

    crearPilaVacia(&cabezaPila);
    apilar(&cabezaPila, datoP);
    apilar(&cabezaPila, datoP2);
    apilar(&cabezaPila, datoP3);
    apilar(&cabezaPila, datoP4);

    while (!esVaciaPila(&cabezaPila))
    {
        desapilar(&cabezaPila, &auxDato);
        printf("| %d |", auxDato.numero);
    }
    
    return 0;
}

void crearPilaVacia(nodoPila ** cabezaPila)
{
    (*cabezaPila) = NULL;
}



void apilar(nodoPila ** cabezaPila, datoPila dato)
{
    nodoPila *nuevo = (nodoPila *) malloc(sizeof(nodoPila));
    nuevo->dato = dato;
    
    nuevo->sig = (*cabezaPila);
    (*cabezaPila) = nuevo;

}

void desapilar(nodoPila ** cabezaPila, datoPila * dato)
{
    nodoPila * aux;
    aux = (*cabezaPila);
    *dato = aux->dato;
    (*cabezaPila) = (*cabezaPila)->sig;

    free(aux);
}

int esVaciaPila(nodoPila ** cabezaPila)
{
    if ((*cabezaPila)==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

