#include <stdio.h>


  /* copia la entrada a la salida; 1er version */
int main(void){

    int c;

    c = getchar();
    while (c!= EOF){
      putchar(c);
      c = getchar();
    }
    
  return 0;
}
