#include <stdio.h>
// define define un nombre simbólico o constante simbólica 
// #define 1) nombre 2)texto de reemplazo
//         1) secuencia de letras y numeros que comienza con una letra 2) cualquier secuencia de caracteres.No esta limitado a numeros

#define LOWER 0 // limite inferior de la tabla de temperatura
#define UPPER 300 //limite superior
#define STEP 20 // tamanio del incremento

/* Imprime la tabla Fahrenheit-Celsius
    para fahr = 0, 20, ..., 300
*/
int main ()
{
    float fahr, celcius;
    
    
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        celcius = 5.0/9.0 * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celcius);
        
    }
}