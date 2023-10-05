# Medir tiempo

Para medir la performance de un programa se puede usar el tiempo de ejecución.  

En BASH:  
time <programa>

En C :  
Usar <time.c>
```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    // Código que deseas medir

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}

```


