#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
Pilas - Algoritmos y Estructura de Datos


*/

struct persona {
  int id;
  char *nombre;
  struct persona *siguiente;  // 1-gustavo- *-->2-ceciliar-*--->null
};

typedef struct persona Nodo;

Nodo *cabeza = NULL;
Nodo *actual = NULL;

char *cargarNombre();
void clearBuffer();
int cargarId();
void apilar();     // apilar
void desapilar();  // desapilar
void CrearRaiz();
void ContarNodos();
void ImprimirLista();  // vista

int main() { return menu(); }

void apilar() {  // apilar

  Nodo *nodo = (struct persona *)malloc(sizeof(struct persona));

  if (NULL == nodo) {
    printf("\n Error en creacion de nodo \n");
  }

  nodo->id = cargarId();
  clearBuffer();
  nodo->nombre = cargarNombre();
  nodo->siguiente = cabeza;
  cabeza = nodo;
}

void desapilar() {  // desapilar

  if (NULL == cabeza) {
    printf("La PILA esta vacia \n");
  } else {
    printf("\n -------DESAPILO------- \n");
    Nodo *nodo = cabeza;
    printf("\n ID: %d ", nodo->id);
    printf("Nombre: %s \n", nodo->nombre);

    cabeza = nodo->siguiente;
    free(nodo);
  }
}

void ImprimirLista(void) {  // Listar

  if (NULL == cabeza) {
    printf("La PILA esta vacia \n");
  } else {
    Nodo *nodo = cabeza;
    printf("\n -------Inicio de la PILA------- \n");

    while (nodo != NULL) {
      printf("\n ID: %d ", nodo->id);
      printf("Nombre: %s \n", nodo->nombre);
      nodo = nodo->siguiente;
    }

    printf("\n -------Final de la Pila------- \n");
  }
}

void ContarNodos(void) {  // Elementos de una Pila
  Nodo *nodo = cabeza;
  int i = 0;

  while (nodo != NULL) {
    i++;
    nodo = nodo->siguiente;
  }

  printf("\n Cantidad de nodos de la PILA: %d\n", i);

  return;
}

int cargarId() {
  int num;
  printf("\n Ingrese el ID: ");
  scanf("%d", &num);
  return num;
}

char *cargarNombre() {
  char d, *newAr;

  int i = 0;

  newAr = (char *)malloc(sizeof(char) * 100);

  printf("\n Ingrese el nombre: ");
  while ((d = getchar()) != EOF && d != '\n') {
    newAr[i++] = d;
  }

  return newAr;
}

void clearBuffer() {
  while (getchar() != '\n')
    ;
}

int menu() {
  char c;

  do {
    printf("\n~~ PILA ~~");
    printf("\nELEGIR: ");
    printf("\n 1. APILAR");
    printf("\n 2. DESAPILAR");
    printf("\n 3. VER PILA");
    printf("\n 4. TOTAL DE NODOS");
    printf("\n q: salir.\n");
    c = getchar();

    switch (c) {
      case '1':
        clearBuffer();
        apilar();
        break;
      case '2':
        clearBuffer();
        desapilar();
        break;
      case '3':
        clearBuffer();
        ImprimirLista();
        break;
      case '4':
        clearBuffer();
        ContarNodos();
        break;
      default:
        break;
    }
  } while (c != 'q' && c != EOF);
}
