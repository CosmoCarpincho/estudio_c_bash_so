#include <stdio.h>

/*
 *  Ej 1-3 Crear encabzezado
 	Imprime la tabla Fahrenheit-Celsius
 	para fahr = 0,20,...300; version de punto flotante
*/

int main (){

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("Fahr Celsius\n");
  while (fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

