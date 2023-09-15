#include <stdio.h>
#include <stdlib.h>

/* lista simplemente enlazadas Ejemplo creación de nodos y agregar elementos a
 * la lista
 */

// declaracion de una lista Simple

typedef struct nodo {
  char *nombre;
  struct nodo *sig;
} ListaSimple;

// creacion de subprogramas

ListaSimple *ListaMarcas(ListaSimple *Marcas) {
  Marcas = NULL;
  return Marcas;
}

ListaSimple *ListaAgregar(ListaSimple *Marcas, char *nombre) {
  ListaSimple *nuevo, *aux;
  nuevo = (ListaSimple *)malloc(
      sizeof(ListaSimple));  // reservo el espacio para el tipo ListaSimple
  nuevo->nombre = nombre;
  nuevo->sig = NULL;  //  asigno a siguiente NULL

  // insercion al inicio

  aux = nuevo;
  aux->sig = Marcas;
  Marcas = nuevo;

  // Marcas=nuevo;
  //  en el caso que se no NULL tengo que recorrer la lista hasta el final

  /*	if(Marcas==NULL)
          {
                  Marcas=nuevo;
          }else
          {
                  aux=Marcas;
                  while (aux->sig!=NULL)
                  {
                          aux=aux->sig;
                  }
                  aux->sig=nuevo;

                  }*/

  return Marcas;
}

void Ver(ListaSimple *Marcas) {
  while (Marcas != NULL) {
    printf("%s\n", Marcas->nombre);
    printf("%x\n", Marcas->sig);
    Marcas = Marcas->sig;
  }
}

int main(int argc, char *argv[]) {
  // declaracion del tipo Lista Simple

  ListaSimple *Marcas;

  // llamada para la creacion de la Lista Simple para apunta a NULL
  Marcas = ListaMarcas(Marcas);

  //  llamo para agrgar un nodo
  Marcas = ListaAgregar(Marcas, "Volkswagen");
  Marcas = ListaAgregar(Marcas, "ford");
  Marcas = ListaAgregar(Marcas, "fiat");
  Marcas = ListaAgregar(Marcas, "jeep");
  // llamo a ver
  Ver(Marcas);

  // visualiza la posicion en memoria
  // printf("%p\n", Marcas);
  // visualiza Marca
  //    printf("%s\n", Marcas->nombre);
  //	printf("%p\n", Marcas->sig);

  return 0;
}
