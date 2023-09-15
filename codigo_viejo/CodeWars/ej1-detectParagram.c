#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char texto[20] = "Hola Mun";

    int resultado = is_pangram(texto);
    return 0;
}


int is_pangram(char *str_in) {

  //tengo que recorrer el arreglo hasta que llegue a /0 o con strlen saco la longitud primero y despues recorro con otro for
  int i;
  char * p = str_in;
  
  //Usar la funcion strlen me da la longitud de p
  int leng = strlen(p);
  
  //Hacerlo a mano con un while
  int cant = 0;
  while (p[cant] != '\0')
  {
    cant = cant + 1;
    //
  }
  
  
  for (i=0; i < cant; i++){
  
    printf("%c",p[i]);
    
    
  }
  return i;

}

