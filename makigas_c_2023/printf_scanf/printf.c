#include <stdio.h>

int main(){

  // Printf es imprimir con formato
  // retorna el número de caracteres que imprimio sin contar el \0 que es el final de el stream

  char texto[15] = "Hola bro\n"; // arreglo de 15. con 9 caracteres. un \0

  int cant_imp = printf("%s", texto);

  printf("\ncantidad impresa: %d\n", cant_imp ); // imprime 9 que es la cantidad de caracteres


  // como dar espacio
  int width_printf = 5;
  int numero = 33  ;
  printf(">%*d<\n",width_printf, numero);

  
  return 0;
}
