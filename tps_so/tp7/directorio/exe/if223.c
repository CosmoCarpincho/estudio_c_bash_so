// ¿Qué valores rompen el if? 
// Por lo que veo mientras que no sea 0 entra al if 
// entro con entero positivo y negativo. caracter. string.flotante.

#include <stdio.h>

int main (){

  if(1){
    puts("1");
  }

  if(0){
    puts("0");
  }

  if(-1){
    puts("-1");
  }

  if(2){
    puts("2");
  }

  if('a'){
    puts("a");
  }

  if("hola"){
    puts("hola");
  }

  if(1.2){
    puts("1.2");
  }

  return 0;
}

/* Salida:
$ ./if.out 
1
-1
2
a
hola
1.2
*/
