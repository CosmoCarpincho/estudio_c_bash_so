#include <stdio.h>
#include <stdlib.h>

/*Se tiene una lista de precios de productos vendidos en Carrefour y otra lista
   con los precios de los mismos productos vendidos en Disco. Se desea obtener
   una tercera lista con los nombres de cada uno de los productos y el nombre
   del supermercado donde me conviene comprarlos.

*/

// declaración de una lista precios

typedef struct nodo {
  float precio;
  int cod;
  struct nodo *sig;
} ListaSimple;

// declaración de una lista consolidada

typedef struct nodo1 {
  float precio;
  int cod;
  int super;  // 1: carrefour 2: disco
  struct nodo1 *sig;
} ListaConsolidada;

// creacion de subprogramas

ListaSimple *ListaVacio1(ListaSimple *Cabeza) {
  Cabeza = NULL;
  return Cabeza;
}

ListaConsolidada *ListaVacio2(ListaConsolidada *Cabeza) {
  Cabeza = NULL;
  return Cabeza;
}

ListaSimple *ListaAgregarSuper(ListaSimple *Cabeza, int cod, float precio) {
  // creación de Nodo de supermercados

  ListaConsolidada *nuevo, *aux;
  nuevo = (ListaConsolidada *)malloc(sizeof(ListaConsolidada));
  nuevo->cod = cod;
  nuevo->precio = precio;
  nuevo->sig = NULL;

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

ListaConsolidada *ListaAgregarConsolidado(ListaConsolidada *Cabeza, int cod,
                                          float precio, int suc) {
  // creación de Nodo de supermercados

  ListaConsolidada *nuevo, *aux;
  nuevo = (ListaConsolidada *)malloc(sizeof(ListaConsolidada));
  nuevo->cod = cod;
  nuevo->precio = precio;
  nuevo->super = suc;
  nuevo->sig = NULL;

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

ListaConsolidada *ListaModificar(ListaSimple *Cabeza, int cod, float precio) {
  // creacion de Nodo

  ListaSimple *nuevo, *anterior, *actual;

  actual = Cabeza;
  anterior = NULL;

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  while (actual != NULL && actual->cod != cod) {
    anterior = actual;
    actual = actual->sig;
  }

  if (actual != NULL) {
    if (actual->precio <= precio) {
      Cabeza =

          ListaAgregarConsolidador(Cabeza, actual->cod, actual->precio, 2);
    }
  } else {
    ListaAgregarConsolidador(Cabeza, cod, precio, 1);
  }

  return Cabeza;
}

void Ver(ListaConsolidada *Cabeza) {
  while (Cabeza != NULL) {
    printf("cod producto %d \n", Cabeza->cod);
    printf("cod supermercado %d \n", Cabeza->super);
    printf("Precio $ %d \n", Cabeza->precio);

    Cabeza = Cabeza->sig;
  }
}

// cuerpo principal

int main(int argc, char *argv[]) {
  // declaracion del tipo Lista Simple

  ListaSimple *Cabeza1;  // carrefour
  ListaSimple *Cabeza2;  // disco

  // declaracion del tipo Lista Consolidada

  ListaConsolidada *Cabeza3;  // lista de precios bajos

  // llamada para la creacion de la Lista Simple para apunta a NULL
  Cabeza1 = ListaVacio1(Cabeza1);
  Cabeza2 = ListaVacio1(Cabeza2);
  Cabeza3 = ListaVacio2(Cabeza3);

  int sigue = 1;
  int dato;
  float p;

  while (sigue == 1) {
    printf("Ingrese CARREFOUR \n");
  }

  printf("Ingrese código producto \n");
  scanf("%d", &dato);
  printf("Ingrese precio  producto \n");
  scanf("%f", &p);

  Cabeza1 = ListaAgregarSuper(Cabeza1, dato, p);

  printf("Ingrese DISCO\n");

  printf("Ingrese código producto \n");
  scanf("%d", &dato);
  printf("Ingrese precio  producto \n");
  scanf("%f", &p);

  Cabeza2 = ListaAgregarSuper(Cabeza2, dato, p);

  // pregunto si sigo cargando
  printf("Hay mas INFORMACION DE CARGA  si=1 no=0 \n");
  scanf("%d", &sigue);

  // PROCESO DE COMPARACIÓN O CONSOLIDACION

  while (Cabeza1 != NULL) {
    Cabeza3 = ListaModificar(Cabeza2, Cabeza1->cod, Cabeza1->precio);
    Cabeza1 = Cabeza1->sig;
  }

  // ver la lista 3

  ver(Cabeza3);

  return 0;
}
