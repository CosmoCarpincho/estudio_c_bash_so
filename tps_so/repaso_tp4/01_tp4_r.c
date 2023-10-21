// suma primeros 5 números naturales
#include <stdio.h>

int main() {
        int n = 0;

        int i;
        for (i = 0; i < 5; i++) {
                n += i + 1;
                printf("%i, ", i + 1);
        }

        printf("\nLa suma de los números es: %i\n\n", n);

        // Probando hacer lo mismo pero de distinta forma
        int j = 1, total = 0;
        while (j <= 5) {
                total += j;
                // interesante saber que primero usa j y después lo aumento OJO
                printf("%i, ", j++);
        }

        printf("\nla suma es: %i: \n", total);

        return 0;
}