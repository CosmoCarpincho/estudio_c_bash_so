#include <stdio.h>

int main(int argc, char const *argv[])
{
    // printf("Ingrese su nombre y apellido: ");

    // char string[100];
    // fgets(string, 100, stdin); 

    // float numFloat = 12.3456;

    // int val = printf("Su nombre y apellido es: %s numero: %.4f", string, numFloat);

    // printf("\n val = %d",val);


    char nombreAPellido[100];

    printf("Ingrese su nombre y apellido: ");
    //int leidos = scanf("%[][a-zA-Z0-9-]", nombreAPellido); // que caracteres queres leer
    int leidos = scanf("%[^\n]", nombreAPellido); // lee todo hasta llegar a un \n . El ^ sirve para indicar que caracter no debe leerce y si se encunetra con uno deja de leer.

    int val2 = printf("Su nombre y apellido es: %s", nombreAPellido);

    return 0;
}
