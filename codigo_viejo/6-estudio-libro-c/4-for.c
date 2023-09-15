#include <stdio.h>

#define LOWER 0  	// Limite inferior de la tabla
#define UPPER 300 	// Limite superior
#define STEP 20		// Tamanio del incremento
#define CELSIUS_F(fahr) (5.0/9.0)*(fahr-32)

// Imprime la tabla Fahrenheit-Celsius
int main (){

  int fahr;

  for (fahr = LOWER; fahr <=UPPER; fahr = fahr + STEP){
    printf("%3d %6.1f\n",fahr,CELSIUS_F(fahr));
  }


return 0;
}
