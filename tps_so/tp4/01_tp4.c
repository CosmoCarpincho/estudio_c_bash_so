/*
1. Instalar compilador de lenguaje C (gcc) y librerías necesarias. Además
realice una rutina en este lenguaje que sume los 5 primeros números naturales.

*/

#include <stdio.h>

int main() {
        int num = 0;
        int i;
        for (i = 1; i <= 5; i++) {
                num += i;
        }

        printf("La suma de los primeros 5 números naturales es: %d\n", num);

        return 0;
}
