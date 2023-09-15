#include <stdio.h>
#include <stdlib.h>

/*

Ejemplo: Empresa de servicios de limpieza

Se tiene un listado de servicios de lavandería con la siguiente información:
servicio y precio. Todos los que acceden tienen un código de cliente, durante el
dia realiza el pedido de por medio de una App: codigo de cliente, servicio y
cantidad de prendas, llega a la lavandería por medio de un delivery. Toda esta
información se va apilando. Los pedido se aceptan hasta las 15hs. ahí en ese
momento hay un cierre para realizar la planificación de las tareas de la
lavandería y  se desapila los pedidos y se genera una lista de trabajo con la
siguiente información: código de cliente, servicio, cantidad de prendas y monto
a abonar. Además sobre esta lista de trabajo se desea saber, ( se debe recorrer
en forma recursiva):
- Cantidad de cliente
- cantidad de dinero recaudado


*/

// Estructura de LISTA de SERVICIO de Lavanderia

typedef struct nodoservicios {
  char servicio;
  float precio;
  struct nodoservicios *sig;
} nodoservicios;

// Estructura de PILA para cargar los pedido de la App

typedef struct nodoapp {
  int codigo;
  char servicio;
  int cantidad;
  struct nodoapp *sig;
} nodoapp;

// Estructura de LISTA para cargar los ticket de trabajo en la lavanderia.

typedef struct nodoticket {
  int codigo;
  char servicio;
  int cantidad;
  float monto;
  struct nodoticket *sig;
} nodoticket;

// Declaracion de los Subprogramas
void clearBuffer();
nodoservicios *ListaVaciaServicios(
    nodoservicios
        *cabeza);  // inicializar cn NULL la cabeza de la LISTA de Servicios
nodoapp *PilaVaciaApp(
    nodoapp *cabeza);  // inicializar con NULL la cabeza de la PILA de la App
nodoticket *ListaVaciaTicket(
    nodoticket
        *cabeza);  // inicializar con NULL la cabeza de la LISTA de Ticket
nodoservicios *ListaAgregarServicios(
    nodoservicios *cabeza, char ser,
    float pre);  // Carga la lista de precios de los servicios
void apilarTicket(nodoapp **cabeza, int cod, char ser,
                  int cant);  // Carga la PILA con los pedidos de la App
nodoticket *ListaAgregarTicket(
    nodoticket *cabeza, int cod, int cant, float mon,
    char ser);  // Carga la lista de trabajo de lavanderia
void ListaLavado(
    nodoapp *cabezaapp, nodoservicios *cabezaservicio,
    nodoticket **cabezaticket);  // desapilo e inserto en nueva pila
float BuscarPrecio(
    nodoservicios *cabeza,
    char servicio);  // obtiene de la LISTA el precio del Servicio
float RecMonto(nodoticket *cabeza);   // proceso recursivo para obtener el total
                                      // de lo recuaudado
int RecCantidad(nodoticket *cabeza);  // cantidad de ticket del dia

int main(int argc, char *argv[]) {
  // declaracion del tipo Lista Simple, para llevar la cantidad max de LED
  // encendidas por calle, de 15

  nodoservicios *Cabezaservicios;
  nodoapp *Cabezaapp;
  nodoticket *Cabezaticket;

  // llamada para la creacion de la Lista Simple para apunta a NULL
  Cabezaservicios = ListaVaciaServicios(Cabezaservicios);
  Cabezaapp = PilaVaciaApp(Cabezaapp);
  Cabezaticket = ListaVaciaTicket(Cabezaticket);

  // 1-CARGAR UNA LISTA CON PRECIOS DE SERVICIOS

  char ser[] = {'L', 'S', 'P', 'F', 'C', 'A'};
  float pre[] = {40.5, 44.5, 25.5, 100, 150.80, 200.25};
  char s;
  float p;
  int i;
  for (i = 0; i < 6; i++) {
    s = ser[i];
    p = pre[i];
    Cabezaservicios = ListaAgregarServicios(Cabezaservicios, s, p);
  }

  // 2- Carga de la Pila por Medio de la App hasta las 15hs.

  int termino = 0;
  int cod, cant;
  char servicio;

  printf("******CARGA DE LA APP******\n\n");

  while (termino == 0) {
    termino = 1;
    printf("Ingrese su CODIGO de Cliente \n");
    scanf("%d", &cod);
    printf(
        "Ingrese SERVICIO \n");  // puede ser un icono que se presione y libere
                                 // la letra que corresponde al Servicio
    clearBuffer();
    scanf("%c", &servicio);
    printf("Ingrese CANTIDAD de Prendas \n");
    scanf("%d", &cant);

    apilarTicket(&Cabezaapp, cod, servicio, cant);

    // Pregunto son las 15hs
    printf("Ya son las 15hs? si=1 no=0 \n");
    scanf("%d", &termino);
  }

  // 3- Terminacion de la carga de la App, crear Lista de trabajos de lavanderia

  ListaLavado(
      Cabezaapp, Cabezaservicios,
      &Cabezaticket);  // pila
                       // ListaLavado(iniciocola,fincola,Cabezaservicios,&Cabezaticket);

  // 4 -OBTENER EL TOTAL DE SERVICIOS VENDIDOS POR LA APP

  int cantidad = RecCantidad(Cabezaticket);  // cantidad de ticket del dia

  printf("Cantidad de Servicios App: %i \n\n", cantidad);

  // 5- OBTENER EL MONTO DE SERVICIOS VENDIDOS POR LA APP

  float total = RecMonto(Cabezaticket);  // proceso recursivo para obtener el
                                         // total de lo recuaudado

  printf("Monto recaudado de los Servicios de la App $: %f \n", total);

  return 0;
}

// Desarrollo de los Subprogramas

void clearBuffer() {
  while (getchar() != '\n')
    ;
}

nodoservicios *ListaVaciaServicios(
    nodoservicios
        *cabeza)  // inicializar cn NULL la cabeza de la LISTA de Servicios
{
  cabeza = NULL;
  return cabeza;
}

nodoapp *PilaVaciaApp(
    nodoapp *cabeza)  // inicializar con NULL la cabeza de la PILA de la App
{
  cabeza = NULL;
  return cabeza;
}

nodoticket *ListaVaciaTicket(
    nodoticket *cabeza)  // inicializar con NULL la cabeza de la LISTA de Ticket
{
  cabeza = NULL;
  return cabeza;
}

nodoservicios *ListaAgregarServicios(
    nodoservicios *cabeza, char ser,
    float pre)  // Carga la lista de precios de los servicios
{
  // nodo nuevo de servicios
  nodoservicios *nuevo, *aux;
  nuevo = (nodoservicios *)malloc(
      sizeof(nodoservicios));  // reservo el espacio para el tipo ListaSimple
  nuevo->servicio = ser;
  nuevo->precio = pre;
  nuevo->sig = NULL;  //  asigno a siguiente NULL

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  if (cabeza == NULL) {
    cabeza = nuevo;
  } else {
    aux = cabeza;
    while (aux->sig != NULL) {
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
  return cabeza;
}

// CON PILA
void apilarTicket(nodoapp **cabeza, int cod, char ser,
                  int cant)  // Carga la PILA con los pedidos de la App
{
  nodoapp *nodo = (struct nodoapp *)malloc(sizeof(struct nodoapp));
  if (NULL == cabeza) {
    printf("\n La Pila es NULL \n");
  }
  if (NULL == nodo) {
    printf("\n Error en creacion de nodo \n");
  }
  nodo->codigo = cod;
  nodo->servicio = ser;
  nodo->cantidad = cant;
  nodo->sig = *cabeza;
  *cabeza = nodo;
}

nodoticket *ListaAgregarTicket(
    nodoticket *cabeza, int cod, int cant, float mon,
    char ser)  // Carga la lista de trabajo de lavanderia
{
  // nodo nuevo de servicios
  nodoticket *nuevo, *aux;
  nuevo = (nodoticket *)malloc(
      sizeof(nodoticket));  // reservo el espacio para el tipo ListaSimple
  nuevo->servicio = ser;
  nuevo->monto = mon;
  nuevo->codigo = cod;
  nuevo->cantidad = cant;

  nuevo->sig = NULL;  //  asigno a siguiente NULL

  // en el caso que se no NULL tengo que recorrer la lista hasta el final

  if (cabeza == NULL) {
    cabeza = nuevo;
  } else {
    aux = cabeza;
    while (aux->sig != NULL) {
      aux = aux->sig;
    }
    aux->sig = nuevo;
  }
  return cabeza;
}

// pila

void ListaLavado(nodoapp *cabezaapp, nodoservicios *cabezaservicio,
                 nodoticket **cabezaticket) {
  int cod, cant;
  float monto;
  char ser;

  nodoapp *aux;

  while (cabezaapp != NULL) {
    aux = cabezaapp;
    cod = aux->codigo;
    cant = aux->cantidad;
    ser = aux->servicio;
    monto = BuscarPrecio(cabezaservicio, aux->servicio) *
            aux->cantidad;  // calculo el precio total ser servicio por cantidad
                            // de prendas
    *cabezaticket = ListaAgregarTicket(*cabezaticket, cod, cant, monto,
                                       ser);  // inserto lista lavanderia
    cabezaapp = cabezaapp->sig;
    free(aux);  // libero el espacio
  }
}

float BuscarPrecio(nodoservicios *cabeza,
                   char servicio)  // retorno el precio del servicio
{
  float precio = 0;

  while (cabeza != NULL) {
    if (servicio == cabeza->servicio) {
      precio = cabeza->precio;
    }

    cabeza = cabeza->sig;
  }

  return precio;
}

float RecMonto(nodoticket *cabeza)  // proceso recursivo para obtener el total
                                    // de lo recuaudado
{
  if (cabeza != NULL) {
    return RecMonto(cabeza->sig) + cabeza->monto;
  } else {
    return 0;
  }
}

int RecCantidad(nodoticket *cabeza)  // proceso recursivo para obtener la
                                     // cantidad de servicios vendidos en la app
{
  if (cabeza != NULL) {
    return RecCantidad(cabeza->sig) + 1;
  } else {
    return 0;
  }
}
