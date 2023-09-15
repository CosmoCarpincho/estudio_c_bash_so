#include <stdio.h>
#include <stdlib.h>
/*
Algoritmos y Estructura de Datos



*/

char *cargarNombre();
int cargarId();
int isEmpty();  // ESVACIA
int menu();
void clearBuffer();
void descolar();
void encolar();
void isEmptyWrap();
void listado();

typedef struct persona {
  int id;
  char *nombre;
  struct persona *siguiente;
} nodo;

nodo *inicio, *final;
char *nombre;
int id;

main() {
  final = 0;   // o NULL
  inicio = 0;  // o NULL

  return menu();
}

// retorna un nuevo puntero a un arreglo

char *cargarNombre() {
  char d, *newAr;

  int i = 0;

  newAr = (char *)malloc(sizeof(char) * 100);

  printf("Ingrese el nombre: ");

  while ((d = getchar()) != EOF && d != '\n') {
    newAr[i++] = d;
  }

  return newAr;
}

int cargarId() {
  int num;
  printf("Ingrese el ID: ");
  scanf("%d", &num);
  return num;
}

// cuando se manejan menus que tienen breaklines, se ocupa limpiar el buffer
// antes de empezar a leer caracteres
void clearBuffer() {
  while (getchar() != '\n')
    ;
}
int menu() {
  char op;

  do {
    printf("\n***** OPCIONES DE COLA *****");
    printf("\nOPCIONES");
    printf("\n 1. ENCOLAR ");
    printf("\n 2. DESENCOLAR ");
    printf("\n 3. ESTAVACIO ");
    printf("\n 4. VER COLA ");
    printf("\n 5: SALIR\n");
    op = getchar();
    switch (op) {
      case '1':

        clearBuffer();
        nombre = cargarNombre();
        id = cargarId();
        encolar(inicio, final, nombre, id);

        break;
      case '2':
        descolar();
        break;
      case '3':
        isEmptyWrap();
        break;
      case '4':
        listado(inicio, final);
        break;

      default:
        break;
    }
  } while (op != 'q' && op != EOF);

  return 1;
}

// metodo wrapper para el menu
void isEmptyWrap() {
  clearBuffer();
  if (isEmpty()) {
    printf("VACIO\n");
  } else {
    printf("NO ESTA VACIO\n");
  }
}

void descolar() {
  nodo *aux;

  clearBuffer();

  if (isEmpty()) {
    printf("ESTA VACIO");
  } else {
    if (final == inicio) {  // si solo hay 1 nodo

      final = inicio = 0;  // dejamos los punteros en null
    } else {               // si hay mas de 1 nodo

      aux = inicio;
      printf("%d | %s\n", aux->id, aux->nombre);
      inicio = aux->siguiente;
      free(aux);
    }
  }
}

// ENCOLAR

void encolar(nodo *i, nodo *f, char *nom, int id) {
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));  // creo espacio para el NODO Nuevo
  nuevo->nombre = nom;
  nuevo->id = id;
  nuevo->siguiente = 0;  // o NULL

  if (i == 0) {
    inicio = nuevo;  // Cola vacia, inserta el 1er elemento
  } else {
    final->siguiente = nuevo;  // inserta al final
  }

  final = nuevo;  // pone puntero finalen el nodo agregado
}

// VERIFICA SI ESTA VACIA ( TEORIA ESVACIA)

int isEmpty() {
  if (!final) {
    return 1;  // TRUE
  } else {
    return 0;  // FALSE
  }
}

void listado(nodo *i, nodo *f) {
  nodo *aux;

  aux = i;
  clearBuffer();

  while (aux != 0) {
    printf("%d | %s\n", aux->id, aux->nombre);
    aux = aux->siguiente;
  }
}
