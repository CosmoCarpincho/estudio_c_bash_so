#include <stdio.h>
// Se reserva en memoria el espacio del de mayor tamaño. Despues se pisan los
// datos.
union dato {
  int x;
  char letra;
  float z;
};

int main() {
  union dato d;
  d.x = 10;
  printf("Impresion del entero:%i\n", d.x);
  d.letra = 'A';
  printf("Impresion del caracter: %c\n", d.letra);
  printf("Impresion del entero: %i\n", d.x);  // 65 que es el A en ASCII
  d.z = 5.25;
  printf("Impresion del float: %0.2f\n", d.z);
  printf("Impresion del entero:%i\n", d.x);
  printf("Impresion del entero en formato flotante:%f\n", d.x);

  // OTRA UTILIDADA
  // Acceder a los datos con dos modelos distintos

  struct coordenada {
    int x;
    int y;
  };

  union punto {
    int v[2];
    int* punt;  // Este no funciona porque hay que asignarle a donde apunta
    struct coordenada co;
  };

  union punto p;
  p.co.x = 10;
  p.co.y = 20;
  printf("%i %i\n", p.co.x, p.co.y);
  printf("%i %i\n", p.v[0], p.v[1]);

  // El puntero
  int* v0 = &p.v[0];
  int* v1 = &p.v[1];
  int aux1 = *v0;

  // p.punt = &p.v[1]; // No funciona porque el puntero usa la misma memoria que
  // p.v[1].
  p.punt = &(p.v[0]);  // No funciona porque el puntero usa la misma memoria que
                       // p.v[1].
  printf("%i %i\n", *(p).punt--, *(p).punt++);
  return 0;
}