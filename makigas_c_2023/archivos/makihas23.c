#include <stdio.h>

int main(int argc, char **argv) {
        FILE *temperaturas = fopen("temperaturas.data", "r");
        if (!temperaturas) {
                puts("No he podido abrir el archivo");
                return 1;
        }

        fseek(temperaturas, 0, SEEK_END); // Cursor al final
        long tam = ftell(temperaturas);   // Tam por ubicación
        rewind(temperaturas);             // Volver el cursor al inicio

        printf("El archivo tiene %ld bytes\n", tam);

        fclose(temperaturas);
}