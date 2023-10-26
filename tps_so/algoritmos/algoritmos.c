#include <stdio.h>
#include <stdlib.h>   // exit
#include <sys/stat.h> //mkdir
#include <time.h>     // para semilla de aletoriedad
#include <unistd.h>   //F_Ok

void crear_vector(unsigned int cant_elem) {

        int aux = access("data", F_OK); // Podría usar stat en vez de access
        if (aux == -1) {
                // mkdir solo crea un directorio. (no los padres) OJO
                if (mkdir("data", 0777) != 0) {
                        perror("Error al crear la carpeta");
                        exit(EXIT_FAILURE);
                }
        }

        FILE *archivo = fopen("./data/vector.data", "a");

        if (!archivo) {
                printf("Error en el archivo vector.data");
                exit(EXIT_FAILURE);
        }

        srand(time(NULL)); // Semilla pseudo aleatoria basada en el tiempo actual

        for (unsigned int i = 0; i < cant_elem; i++) {
                fprintf(archivo, "%d ", rand() % 1000); // Carga de números aleatorios
        }

        fprintf(archivo, "\n");

        fclose(archivo);
}

void menu() {
        char opcion; // Le pongo int porque puede entrar EOF etc
        unsigned int cant_elem;
        do {

                printf("\nMENU\n");
                puts("[1] Crear vector de números");
                puts("[q] salir");
                puts("");

                scanf("%c", &opcion);

                switch (opcion) {
                case '1':
                        printf("Ingrese la cantidad de elementos del vector: ");
                        scanf("%u", &cant_elem);
                        printf("cant de elementos: %u", cant_elem);
                        crear_vector(cant_elem);
                        break;

                default:
                        printf("Entraste en default");
                        break;
                }

                // Limpia buffer hasta salto de linea
                while (getchar() != '\n')
                        ;
                puts("");
                puts("");
        } while (opcion != 'q');
}

int main() {
        printf("Hola mundo");

        menu();

        return 0;
}