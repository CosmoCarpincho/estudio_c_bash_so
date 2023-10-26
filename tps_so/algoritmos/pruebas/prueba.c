#include <stdio.h>

int main() {
        FILE *p;
        // Ver si crea los directorios.
        // No crea directorios revisar zotero respuesta de como crear la funcionalidad
        // con mkdir .
        p = fopen("prueba/prueba2/prueba.txt", "w");
        fclose(p);
}