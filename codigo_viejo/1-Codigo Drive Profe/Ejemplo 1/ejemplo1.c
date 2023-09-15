#include <stdio.h>
#include <stdlib.h>

/*

Ejemplo: Calles y Led de una ciudad




*/

// Estructura de LISTA se cargan las cantidad maximas de led encendidas por
// CALLE

typedef struct nodocalles {
  int calle;
  int max;
  struct nodocalles *sig;
} nodocalles;

// Estructura de PILA para cargar la configuracion de los LED que se encenderan
// durante la Noche

typedef struct nodoencendidas {
  int calle;
  int led;
  struct nodoencendidas *sig;
} nodoencendidas;

// Declaracion de los Subprogramas

nodocalles *ListaVacia();    // inicializar cn NULL la cabeza de la LISTA
nodocalles *ListaAgregar();  // Carga las LISTA con los maximos por calle
void Ver();                  // listado de la LISTA
// Para identificar el maximo de led por calle
int MaxLed();
// Carga de la Pila de Led encendidas por calle por la Noche
nodoencendidas *PilaVacia();  // inicializar con NULL la cabeza de la PILA
void apilar();                // Carga la PILA con los LED encendidos por calle
void encendido();             // configurar en encendido de los LED por CALLE
void encenderLed();           // enciendo cada uno de los LED por Calle
void ImprimirPila();  // Vista de Pila con la configuracion de Encendidos de LED
void cuantasencendidas();  // calcula cuantas estan encendidas sacadas desde la
                           // pila
void cualesmicamino();     // determino el camino y la vereda mas seguras
void sumoled();            // Cantidad de Led por cada una de las calles
void pordonde();   // se desapila la configuracion y se determina el camino:
                   // Izquierda, Derecha o cualquiera
void apagarled();  // desapilar la configuracion de LED encendendidas por calle

int main(int argc, char *argv[]) {
  // declaracion del tipo Lista Simple, para llevar la cantidad max de LED
  // encendidas por calle, de 15

  nodocalles *Cabezacalles;
  nodoencendidas *Cabezaencendidas;

  // llamada para la creacion de la Lista Simple para apunta a NULL
  Cabezacalles = ListaVacia(Cabezacalles);
  Cabezaencendidas = PilaVacia(Cabezaencendidas);

  // 1-CARGAR UNA LISTA CON LOS NUMERO MAXIMOS DE LED POR CALLE

  int sigue = 1;
  int calle, ledmax;

  printf("******CARGA DE MAXIMOS POR CALLE******\n\n");

  while (sigue == 1) {
    printf("Ingrese un numero de CALLE \n");
    scanf("%d", &calle);
    printf("Ingrese un numero de MAXIMO DE LED \n");
    scanf("%d", &ledmax);

    //  llamo para agrgar un nodo

    Cabezacalles = ListaAgregar(Cabezacalles, calle, ledmax);

    // pregunto si sigo cargando
    printf("Hay mas CALLES para carga si=1 no=0 \n");
    scanf("%d", &sigue);
  }

  // Observo que se Cargo en la LISTA
  printf("\n----LISTA CON CALLES Y LED MAXIMOS----- \n\n");
  Ver(Cabezacalles);

  // 2- PROCESO DE CONFIGURACIÓN
  printf("\n******CARGA DE LA PILA POR CALLES Y LED ENCENDIDOS****** \n\n");
  encendido(Cabezacalles, &Cabezaencendidas);

  // Observo que se Cargo en la PILA
  printf("\n----PILA CON CALLES Y SUS LED ENCENDIDAS----- \n\n");
  ImprimirPila(Cabezaencendidas);

  // 3 -PROCESO DE ENCENDIDAS POR CALLE
  printf("\n----LISTA Y PILA CUANTAS ENCENDIDAS POR CALLE----- \n\n");

  // 4- PROCESO DE LUMINOSIDAD
  printf("\n----LUMINOSIDAD POR CALLE----- \n\n");

  cuantasencendidas(Cabezacalles, Cabezaencendidas);

  // 5- PROCESO DE CAMINO SEGURO
  printf("\n----CAMINO Y VEREDA MAS SEGURA----- \n\n");
  cualesmicamino(Cabezacalles, Cabezaencendidas);

  // 6- BORRADO DE CONFIGURACON
  printf("\n----BORRADOR DE LA CONFIGURACION----- \n\n");
  apagarled(Cabezaencendidas);  // apagar los led, desapilar

  return 0;
}

// creacion de subprogramas

nodocalles *ListaVacia(nodocalles *Cabeza) {
  Cabeza = NULL;
  return Cabeza;
}

nodocalles *ListaAgregar(nodocalles *Cabeza, int calle, int led) {
  // creacion de Nodo

  nodocalles *nuevo, *aux;

  nuevo = (nodocalles *)malloc(
      sizeof(nodocalles));  // reservo el espacio para el tipo ListaSimple
  nuevo->calle = calle;
  nuevo->max = led;
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

void Ver(nodocalles *Cabeza) {
  while (Cabeza != NULL) {
    printf("CALLE:  %d \n", Cabeza->calle);
    printf("MAX LED:  %d\n", Cabeza->max);
    Cabeza = Cabeza->sig;
  }
}

int MaxLed(nodocalles *Cabeza, int calle) {
  int cantled;

  while (Cabeza != NULL) {
    if (calle == Cabeza->calle) {
      cantled = Cabeza->max;
    }
    Cabeza = Cabeza->sig;
  }

  return cantled;
}

// Pila

nodoencendidas *PilaVacia(nodoencendidas *Cabeza) {
  Cabeza = NULL;
  return Cabeza;
};

// apilar led

void apilar(nodoencendidas **Cabezaencendidas, int calle, int lednumero) {
  nodoencendidas *nodo =
      (struct nodoencendidas *)malloc(sizeof(struct nodoencendidas));
  if (NULL == Cabezaencendidas) {
    printf("\n La Pila es NULL \n");
  }
  if (NULL == nodo) {
    printf("\n Error en creacion de nodo \n");
  }
  nodo->calle = calle;
  nodo->led = lednumero;
  nodo->sig = *Cabezaencendidas;
  *Cabezaencendidas = nodo;
};

void encendido(nodocalles *Cabeza, nodoencendidas **Pila) {
  // recorro las calles donde estan el maximo de led y cargo las encendidas en
  // la pila. verifico de no excederme del maximo de led por calle

  while (Cabeza != NULL) {
    encenderLed(Pila, Cabeza->calle, Cabeza->max);
    Cabeza = Cabeza->sig;
  }
}

void encenderLed(nodoencendidas **Pila, int calle, int maxled) {
  int contar = 0;
  int numled, salgo = 1;

  printf("Encienda los Led de la Calle %d \n", calle);

  while (contar <= maxled && salgo == 1) {
    printf("Enciendo el Led#: \n");
    scanf("%d", &numled);
    apilar(Pila, calle, numled);
    contar++;
    printf("Sigue encendiendo LED 1=SI 0=NO \n");
    scanf("%d", &salgo);
  }
}

void ImprimirPila(nodoencendidas *cabeza) {  // Listar

  if (NULL == cabeza) {
    printf("La PILA esta vacia \n");
  } else {
    nodoencendidas *nodo = cabeza;
    printf("\n -------INICIO de la PILA------- \n");

    while (nodo != NULL) {
      printf("\n CALLE*****: %d \n ", nodo->calle);
      printf("LED#*** : %d \n", nodo->led);
      nodo = nodo->sig;
    }

    printf("\n -------FIN de la PILA------- \n");
  }
}

void sumoled(nodoencendidas *Pila, int calle, int maxled) {
  int contar = 0;
  float lumi = 0;

  printf("\n----Encienda los Led de la Calle %d------\n", calle);

  while (Pila != NULL) {
    if (calle == Pila->calle) {
      contar++;
    }
    Pila = Pila->sig;
  }
  lumi = (float)contar / (float)maxled;
  printf("\nTOTAL de ENCENDIDAS %d sobre %d\n", contar, maxled);

  printf("PORCENTAJE de LUMINOSIDAD %3.2f sobre %d\n ", lumi * 100, maxled);

  lumi = lumi * 100;

  // determino el tipo de luminosidad
  contar = (int)lumi;

  switch (contar) {
    case 100:
      printf("MUY LUMNINOSO \n");
      break;
    case 50 ... 99:
      printf("LUMNINOSO\n");
      break;
    case 30 ... 49:
      printf("PENUMBRAS\n");
      break;
    default:
      printf("OSCURO \n");
      break;
  };
}

void pordonde(nodoencendidas *Pila, int calle) {
  int contari = 0, contard = 0, led = 0;
  float paso = 0;

  printf("\nEncienda los Led de la Calle %d \n", calle);

  while (Pila != NULL) {
    if (calle == Pila->calle) {
      led = Pila->led;
      // calculo par o impar
      paso = led / 2;
      paso = paso * 2;
      // fin

      if (paso == led) {
        contard++;
      } else {
        contari++;
      }
    }

    Pila = Pila->sig;
  }

  if (contari > contard) {
    printf("VOY POR LA VERDERA DE IZQUIERDA \n");
  } else if (contari == contard) {
    printf("VOY POR CUALQUIERA DE LAS VEREDAS \n");
  } else {
    printf("VOY POR LA VERDERA DE DERECHA \n");
  }
}

void cuantasencendidas(nodocalles *cabeza, nodoencendidas *Pila) {
  // Recorro tola la Pila de encendidas
  // Determino cuantos led encendidas

  int cuantas = 0;

  while (cabeza != NULL) {
    sumoled(Pila, cabeza->calle, cabeza->max);

    cuantas++;
    cabeza = cabeza->sig;
  }

  printf("\n Total de Calles: %d \n", cuantas);
}

void cualesmicamino(nodocalles *cabeza, nodoencendidas *Pila) {
  // Recorro tola la Pila de encendidas
  // Determino cuantos en funcion de los led por cuadra por que vereda voy

  int cuantas = 0;

  while (cabeza != NULL) {
    pordonde(Pila, cabeza->calle);
    cabeza = cabeza->sig;
  }
}

void apagarled(nodoencendidas *Pila) {
  int max = 0, callemax = 0;
  int calle, led;
  nodoencendidas *aux;

  printf("APAGAR LOS LED DE LAS CALLES \n");

  while (Pila != NULL) {
    calle = Pila->calle;
    led = Pila->led;
    aux = Pila;
    printf("APAGAR LOS LED# %i DE LA CALLES# %i \n", led, calle);
    Pila = Pila->sig;
    free(aux);  // libero el espacio
  }
}
