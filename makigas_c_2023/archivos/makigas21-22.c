#include <stdio.h>

int main(int argc, char **argv) {
        FILE *temperaturas = fopen("temperaturas.data", "r");
        if (!temperaturas) {
                puts("No he podido abrir el archivo.");
                return 1;
        }

        do {

                int leido = fgetc(temperaturas);
                if (leido != EOF) {
                        printf("%c", (char)leido);
                } else {
                        printf("\n== FIN ==");
                }
        } while (!feof(temperaturas));

        fclose(temperaturas);
        return 0;
}