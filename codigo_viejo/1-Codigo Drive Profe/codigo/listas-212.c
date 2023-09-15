#include <stdio.h>
#include <stdlib.h>

/* lista simplemente enlazadas Ejemplo creacion de nodos y a borrar un elementos
   de una  lista



*/

// declaracion de una lista Simple

typedef struct nodo {
  int nombre;
  struct nodo *sig;
} ListaSimple;

// creacion de subprogramas

ListaSimple *ListaVacio(ListaSimple *Cabeza) {
  Cabeza = NULL;
  return Cabeza;
}

// AGREGAR

ListaSimple *ListaAgregar(ListaSimple *Cabeza, int dato) {
  // creacion de Nodo

  ListaSimple *nuevo, *aux;
  nuevo = (ListaSimple *)malloc(
      sizeof(ListaSimple));  // reservo el espacio para el tipo ListaSimple
  nuevo->nombre = dato;
  nuevo->sig = NULL;  //  asigno a siguiente NULL

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  if (Cabeza == NULL) {
    Cabeza = nuevo;
  } else {
    aux = Cabeza;
    while (aux->sig != NULL) {
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
  return Cabeza;
}

// ELIMINAR

ListaSimple *ListaBorrar(ListaSimple *Cabeza, int dato) {
  // creacion de Nodo

  ListaSimple *nuevo, *anterior, *actual;

  //	nuevo= (ListaSimple*)malloc(sizeof(ListaSimple)); // reservo el espacio
  //para el tipo ListaSimple 	nuevo->nombre= dato;

  actual = Cabeza;
  anterior = NULL;

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  while (actual != NULL && actual->nombre != dato) {
    anterior = actual;
    actual = actual->sig;
  }

  if (actual != NULL) {
    if (anterior != NULL) {
      anterior->sig = actual->sig;
    } else {
      Cabeza = Cabeza->sig;
    }

    free(actual);
  }

  return Cabeza;
}

// LISTAR

void Ver(ListaSimple *Cabeza) {
  while (Cabeza != NULL) {
    printf("Numero ingresado %d \n", Cabeza->nombre);
    //	printf("Direccion de Menoria %p\n", Cabeza->sig);
    Cabeza = Cabeza->sig;
  }
}

ListaSimple *ListaModificar(ListaSimple *Cabeza, int dato, int valornuevo) {
  // creacion de Nodo

  ListaSimple *nuevo, *anterior, *actual;

  // nuevo= (ListaSimple*)malloc(sizeof(ListaSimple)); // reservo el espacio
  // para el tipo ListaSimple
  //	nuevo->nombre= dato;

  actual = Cabeza;
  anterior = NULL;

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  while (actual != NULL && actual->nombre != dato) {
    anterior = actual;
    actual = actual->sig;
  }

  if (actual != NULL) {
    actual->nombre = valornuevo;
  } else {
    printf("No existe el Dato!!! \n");
  }

  return Cabeza;
}

int main(int argc, char *argv[]) {
  // declaracion del tipo Lista Simple

  ListaSimple *Cabeza;

  // llamada para la creacion de la Lista Simple para apunta a NULL
  Cabeza = ListaVacio(Cabeza);

  int sigue = 1;
  int dato, valor;

  while (sigue == 1) {
    printf("Ingrese un numero \n");
    scanf("%d", &dato);

    //  llamo para agrgar un nodo

    Cabeza = ListaAgregar(Cabeza, dato);

    // pregunto si sigo cargando
    printf("Hay mas nuemeros para carga si=1 no=0 \n");
    scanf("%d", &sigue);
  }

  // llamo a ver, para ver lo cargado
  Ver(Cabeza);

  /*	printf("Ingrese el numero que quiere Borra \n");
          scanf("%d", &dato);

      Cabeza= ListaBorrar(Cabeza,dato);

       */

  // MODIFICACION

  printf("Ingrese el numero que quiere Modificar \n");
  scanf("%d", &dato);

  printf("Ingrese el nuevo numero \n");
  scanf("%d", &valor);

  Cabeza = ListaModificar(Cabeza, dato, valor);

  // llamo a ver, para ver el la lista sin el elemento borrado
  Ver(Cabeza);
  return 0;
}