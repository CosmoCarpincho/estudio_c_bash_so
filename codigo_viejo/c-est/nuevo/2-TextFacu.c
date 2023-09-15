#include <stdio.h>

int main(){
int num1 = 10;
int num2;

int *pe;

pe = &num1;

printf("%p",&num1);

printf("Ingrese el valor del numero:");
scanf("%d", &num2);
printf("\n\n La direccion de memoria es: %p del numero : %i",&num2,num2);
return 0;
}
