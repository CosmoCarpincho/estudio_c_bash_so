#include <stdio.h>

int main (void){

// 1-6 Verifique que la expresion getchar() != EOF es 0 o 1
// La precedencia de != es mas alta que la de = OJO
	
  int c;
  int cont = 0;
  while (c = getchar() != EOF){
	putchar(c);
	printf("%d",c);
	if (cont == 10 )
	  break;

	cont++;
  }

// 1-7 Escriba un programa que imprima el valor de EOF

  int a = EOF;
  //char b[10] = EOF; // no es valido esta expresion
  printf("\n\nel valor de EOF es: %d",a);

  return 0;
}
