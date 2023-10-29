// 2. Realizar una rutina en lenguaje C que pida cargar un vector de 10 elementos numéricos y los
// devuelva ordenado de menor a mayor.>
#include <stdio.h>

int vector[10];

int main(){
  for (int i; i <= 10; i++) {
    printf("[%d] Ingrese un número: ", i);
    scanf(&(vector[i]));
    printf("\n");
  }

  puts("Numeros:");
  for (int j; j <= 10; j++){
    printf("%d ", &vector[j]);
  }

  return 0;

}

