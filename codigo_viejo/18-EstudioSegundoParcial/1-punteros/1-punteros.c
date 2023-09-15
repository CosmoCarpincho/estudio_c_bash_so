//Quiero probar punteros, posiciones de memoria de variables, punteros dobles

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n1;
    int a;
    char caracter;
    char string[30]; //string es la direccion de memoria de el primer elemento del arreglo string. 
    strcpy(string, "Hola este viene de memoria estatica");
    char *pString = (char*) malloc( a = 80 * sizeof(char));
    strcpy(pString, "Hola esta texto viene de memoria dinamica");


    int arrNumeros[30];
    
    char *p = string;

    printf("Hola mundo %p | %p | %d | %s | %c",string, p, a, pString, *string);

    return 0;
}
