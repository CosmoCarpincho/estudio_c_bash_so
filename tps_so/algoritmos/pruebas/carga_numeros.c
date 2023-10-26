#include <stdio.h>

int main() {
        FILE *archivo = fopen("archivo.data", "a");
        char numeros[30] = "1 2 3 4 5 6 7 8 9 10 11 12 13";
        fprintf(archivo, "%s\n", numeros);
        return 0;
}