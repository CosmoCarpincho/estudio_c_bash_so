/*
 * La idea es abrir un archivo para editarlo. Pero no cerrarlo y
 * matar el proceso desde afuera con kill para ver que el archivo
 * se guardo o no.
 *
 * En este experimento se observa que hasta que no se ejecuta el fclose
 * el archivo no se guarda de forma persistente.
 */

#include <stdio.h>

int main(){

  FILE * archivo_no_cerrar = fopen("./archivo_no_cerrar.txt", "a");

  fprintf(archivo_no_cerrar, "Hola que tal\n");

  printf("Quiere no cerrar el archivo: y/n:  ");
  int opcion;
  scanf("%s", &opcion);
  if((char)opcion == 'y'){
    puts("Cerra el programa con un kill -9");
    scanf("%s",&opcion);
  }

  fclose(archivo_no_cerrar);

  return 0;
}
