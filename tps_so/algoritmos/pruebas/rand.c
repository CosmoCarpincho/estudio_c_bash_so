#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
        FILE *archivo = fopen("rand.data", "a");
        srand(time(NULL));
        for (size_t i = 0; i < 100; i++) {
                fprintf(archivo, "%d ", rand() % 1000);
        }

        fprintf(archivo, "\n");
        fclose(archivo);

        return 0;
}
