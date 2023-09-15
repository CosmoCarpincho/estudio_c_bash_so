#include <stdlib.h>
#include <stdio.h>

typedef struct datoCola
{
    int num;

} datoCola;

typedef struct nodoCola
{
    datoCola dato;
    struct nodoCola *sig;
} nodoCola;
    
typedef struct Cola
{
    struct nodoCola *pin;
    struct nodoCola *pfin;

}Cola;

void crearColaVacia(Cola ** cola);
void encolar(Cola ** cola, datoCola dato);
void desencolar(Cola ** cola, datoCola * dato);
int esVaciaCola(Cola ** cola);

int main(void)
{

    Cola * cola;

    datoCola dato1 = {1};
    datoCola dato2 = {2};
    datoCola dato3 = {3};
    datoCola dato4 = {4};

    crearColaVacia(&cola);
    
    printf("| %d |", dato1);
    encolar(&cola, dato1);
    printf("| %d |", dato2);
    encolar(&cola, dato2);
    printf("| %d |", dato3);
    encolar(&cola, dato3);
    printf("| %d |", dato4);
    encolar(&cola, dato4);
    
    printf("\n+++\n");

    datoCola auxDato;
    while (!esVaciaCola(&cola))
    {
        desencolar(&cola, &auxDato);
        printf("| %d |", auxDato.num);
    }

    return 0;
}

void crearColaVacia(Cola ** cola)
{
    (*cola)->pin = NULL;
    (*cola)->pfin = NULL;
}

void encolar(Cola ** cola, datoCola dato)
{
    nodoCola * nuevo = (nodoCola *) malloc (sizeof(nodoCola));
    nuevo->dato = dato;
    nuevo->sig = NULL;

    if ((*cola)->pin == NULL)
    {
        (*cola)->pin = nuevo;
    }
    else
    {
        (*cola)->pfin->sig = nuevo;
    }
    
    (*cola)->pfin = nuevo;
    
}

void desencolar(Cola ** cola, datoCola * dato)
{
    nodoCola * aux;
    aux = (*cola)->pin;
    *dato = aux->dato;
    (*cola)->pin = aux->sig;
    if ((*cola)->pin == NULL)
    {
        (*cola)->pfin = NULL;
    }

    free(aux);
}

int esVaciaCola(Cola ** cola)
{
    if ((*cola)->pin == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}