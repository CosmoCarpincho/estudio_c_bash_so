// Quiero crear una lista pero sin encapsular sus partes en funciones
//QUiero crearla de forma secuencial
// Podria ser una lista de personas id, nombre, sueldo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona
{
    unsigned int id;
    char nombre[30];
    unsigned int sueldo;

}Persona;

typedef struct nodo
{
    Persona persona;
    struct Nodo * sigNodo;
}Nodo;

int main(void)
{
    

    // Crear el primer dato de nodo 

    Persona p1;
    p1.id = 1;
    strcpy(p1.nombre, "Cosmo");
    p1.sueldo = 2000;

    // Crear segundo dato de nodo

    Persona p2 = {2, "Pepe", 1000};

    printf("%d | %s | %d\n", p2.id, p2.nombre, p2.sueldo);

    //Crear Nodos

    Nodo n1 = {p1, NULL}; 
    Nodo n2 = {p2, NULL};// Esta forma de inicializar no es correcta. xq si lo meto dentro de una funcion el nodo es creado localmente.
                            //Lo que hay que hacer es crear con malloc que devuelve un puntero que apunta a una direccion de memoria del heap
                            // donde tenes una cantidad de bytes reservados para usar. Despues liberar con free.


    // OJOO!! no confundir un arreglo dinamico con crear una lista. Vos para las listas tenes que crear los nodos individuales y que se apunten entre ellos
    //Mientras que en los arreglos dinamicos los datos estan uno al lado del otro, permitiendo el algebra de punteros
    //*(p+1) equivalente a p[1]
    unsigned int tamArr = 10;
    unsigned int tamNodo = sizeof(Nodo);
    Nodo * arrNodos = (Nodo *) malloc( tamArr * tamNodo); // crearia un arreglo dinamico de tamaño 10 con espacios que ocupan lo que ocupa nodo.

    printf("Tam Nodo: %u\n", tamNodo);


    //AHORA SI VAMOS A CREAR BIEN UN NODO 
    Nodo * n3 = (Nodo *) malloc(sizeof(Nodo)); // n3 es un puntero que apunta a un espacio de memoria en heap que tiene el tamanio de un Nodo. Ahora tiene basura pero ya fue creado el nodo.
    Nodo * n4 = (Nodo *) malloc(sizeof(Nodo));
    // Inicializamos el nodo con los datos persona y que apunte a null.
    n3->persona.id = 3;
    //n3->persona.nombre = "Richard";
    strcpy(n3->persona.nombre, "Richard");
    n3->persona.sueldo = 6000;
    n3->sigNodo = NULL;

    n4->persona.id = 4;
    //n4->persona.nombre = "Marie";
    strcpy(n4->persona.nombre, "Marie");
    n4->persona.sueldo = 3000;
    n4->sigNodo = NULL;
    // Una lista es un puntero que apunta a la primer nodo (struct) y cada nodo apunta al siguiente

    Nodo * lista;

    Nodo * listaCorrecta;

    //El puntero apunta al primer nodo
    lista = &n1;
    
    listaCorrecta = n3;

    //Puedo agregar tanto por delante como por atras o por cualquier parte. 
    //Agrego desde adelante

    n2.sigNodo = (struct nodo*) lista;
    lista = &n2;

    n4->sigNodo = (struct nodo*) listaCorrecta;
    listaCorrecta = n4;

    //Tengo lista -> n1 -> n2 -> null


    //Imprimir los nombres
    Nodo * aux = lista;
    
    
    while (aux != NULL) {
        printf("%s\n",(*aux).persona.nombre);
        aux = (Nodo *) aux->sigNodo;
    } 
    
    Nodo * aux2 = (Nodo *) listaCorrecta;

    while (aux2 != NULL)
    {
        printf(" %u | %s | %u | dirAc: %p | sigNodo: %p\n", aux2->persona.id, aux2->persona.nombre, aux2->persona.sueldo, aux2, aux2->sigNodo);
        aux2 = (Nodo *) aux2->sigNodo;
    }
    


    return 0;
}
