#include <stdio.h>
#include <time.h>
#include <unistd.h>

void funcion() {
        printf("Hola Mundo.\n\n");

        sleep(60);
}

int main() {
        clock_t start_time, end_time;
        double cpu_time_used;

        start_time = clock();

        funcion();

        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("start_time:%li\n", start_time);
        printf("end_time:%li\n", end_time);
        printf("CLOCKS_PER_SEC:%u\n", CLOCKS_PER_SEC);

        printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

        return 0;
}
