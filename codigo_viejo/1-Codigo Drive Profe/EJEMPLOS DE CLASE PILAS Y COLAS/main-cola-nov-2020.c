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
void vaciarcola();      // agregado 2-11
float promediocola();   // agregado 2-11
void listadeprecios();  // agregado 2-11
void compra();
void carrito();
void pagar();
int cargarCantidad();

typedef struct persona {
  int id;
  char *nombre;
  struct persona *siguiente;
} nodo;

// agregado 2-11 nuevo nodo de la cola2 compras

typedef struct compra {
  int id;
  int cantidad;
  char *producto;
  struct compra *siguiente;
} nodo2;

nodo *inicio, *final;     // cola 1
nodo2 *inicio2, *final2;  // cola 2 carrito de compras

char *nombre;  // lo uso en ambas colas
int id;
float promedio = 0;  // variable de calculo

float precios[] = {458.23, 235.36, 125.6, 100.22,
                   47.8,   362.10, 12.52};  // 7 arreglo de lista de precios
int cantidad = 0;  // elemento nuevo del nodo de la cola2

main() {
  final = 0;   // o NULL
  inicio = 0;  // o NULL

  final2 = 0;   // o NULL Cola de Compras
  inicio2 = 0;  // o NULL cola de compras

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

int cargarCantidad() {
  int num;
  printf("Ingrese el Cantidad: ");
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
    printf("\n 5. VACIAR ");              // agregado 2-11
    printf("\n 6. PROMEDIO ");            // agregado 2-11
    printf("\n 7. LISTA DE PRECIOS ");    // agregado 2-11
    printf("\n 8. CARRITO DE COMPRAS ");  // agregado 2-11
    printf("\n q: SALIR\n");
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
      case '5':  // agregado 2-11 vaciemiento de una cola
        vaciarcola();
        break;
      case '6':  // agregado 2-11 promedio de valores de una cola

        promedio = promediocola();
        printf("El promedio es %f", promedio);
        break;
      case '7':  // agregado 2-11 tomando el id como codigo para acceder a un
                 // arreglo de precios

        listadeprecios();

        break;
      case '8':  // agregado 2-11 proceso sencillo de carrito de compras

        compra();  // proceso de compras

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

// agregados clase 2-11

void vaciarcola()  //  2-11 vaciamiento de una cola
{
  nodo *aux;
  clearBuffer();
  // aux = inicio;

  while (final != inicio) {
    aux = inicio;
    printf("%d | %s\n", aux->id, aux->nombre);
    inicio = aux->siguiente;
    free(aux);
  }
  printf("%d | %s\n", inicio->id, inicio->nombre);

  final = inicio = 0;  // dejamos los punteros en null
}

float promediocola()  // 2-11 promedio de una cola
{
  nodo *aux;
  clearBuffer();
  float suma = 0;
  int contar = 0;
  aux = inicio;
  while (aux != final) {
    suma = suma + aux->id;
    contar++;
    aux = aux->siguiente;
  }

  contar++;               // primero
  suma = suma + aux->id;  // primero
  printf("Total de Nodos: %d\n", contar);
  suma = suma / contar;
  return suma;
}

// 2-11 agregado

void listadeprecios() {  // lista de precios sobre cola1 tomando el id

  nodo *aux;
  clearBuffer();
  float publico, costo = 0;
  // int contar=0;
  aux = inicio;
  while (aux != final) {
    costo = precios[aux->id];  // lista de precios en el arreglo
    publico = costo + costo * .21;
    printf("Producto: %s Costo $ %f  Precio $ %f (21%)\n", aux->nombre, costo,
           publico);
    aux = aux->siguiente;
  }

  costo = precios[aux->id];  // lista de precios en el arreglo - del primero
  publico = costo + costo * .21;  // del primero
  printf("Producto: %s Costo $ %f  Precio $ %f (21%)\n", aux->nombre, costo,
         publico);
}

// agregado 2-11 proceso sencillo de compras "carrito de compas"
void compra() {
  int mas = 0;
  printf("Carga de Productos - con 0 TERMINA\n");
  scanf("%d", &mas);

  while (mas != 0) {
    clearBuffer();
    nombre = cargarNombre();
    id = cargarId();
    cantidad = cargarCantidad();
    carrito(inicio2, final2, cantidad, id, nombre);
    printf("Carga de Productos - 0 termina la carga\n");
    scanf("%d", &mas);
  }
  pagar();
}

// agregado 2-11 carrito de compras en una cola 2

void carrito(nodo2 *i, nodo2 *f, int cantidad, int id,
             char *nombre)  // proceso de carga de carrito de compras cola 2
{
  nodo2 *nuevo;
  nuevo = (nodo2 *)malloc(sizeof(nodo2));  // creo espacio para el NODO Nuevo
  nuevo->cantidad = cantidad;
  nuevo->producto = nombre;
  nuevo->id = id;
  nuevo->siguiente = 0;  // o NULL

  if (i == 0) {
    inicio2 = nuevo;  // Cola vacia, inserta el 1er elemento
  } else {
    final2->siguiente = nuevo;  // inserta al final
  }

  final2 = nuevo;  // pone puntero finalen el nodo agregado
}

// agregado 2-11 proceso de pago total de lo comprado

void pagar()  // proceso de suma de lo comprado
{
  nodo2 *aux;
  clearBuffer();
  float suma = 0;

  while (final2 != inicio2) {
    aux = inicio2;
    printf(" Producto %s Precio $ %f Cantidad %d\n", aux->producto,
           precios[aux->id], aux->cantidad);
    suma = suma + precios[aux->id] * aux->cantidad;
    inicio2 = aux->siguiente;
    free(aux);
  }
  suma = suma + precios[inicio2->id] * inicio2->cantidad;
  printf(" Producto %s Precio $ %f Cantidad %d\n", inicio2->producto,
         precios[inicio2->id], inicio2->cantidad);
  printf(" Total a Pagar $ %f\n", suma);

  final2 = inicio2 = 0;  // dejamos los punteros en null
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
