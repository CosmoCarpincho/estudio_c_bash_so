#include <stdio.h>

/*
 * 	Ejercicio 1-4
 * 	Escriba un programa que imprima la tabla correspondiente Celsius a Farenheit
*/

int main (){

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("= celsius    farh =\n");
  while (celsius <= upper){
    fahr = 9.0/5.0 * celsius + 32; 
    printf("%9.0f  %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

