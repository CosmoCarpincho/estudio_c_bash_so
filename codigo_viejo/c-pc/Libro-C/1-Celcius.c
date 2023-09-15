#include <stdio.h>

/* Imprime la tabla Fahrenheit-Celsius
    para fahr = 0, 20, ..., 300
*/
int main ()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0; // limite inferior de la tabla de temperatura
    upper = 300; //limite superior
    step = 20; // tamanio del incremento

    fahr = lower;
    while (fahr <= upper){
        celcius = 5.0/9.0 * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}