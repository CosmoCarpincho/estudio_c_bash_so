#include <stdio.h>
#include <stdlib.h>   // exit
#include <sys/stat.h> //mkdir
#include <unistd.h>   //F_Ok

void crear_vector(__attribute__((unused)) unsigned int cant_elem) {

        int aux = access("data", F_OK);
        if (aux == -1) {
                if (mkdir("data", 0777) != 0) {
                        perror("Error al crear la carpeta");
                        exit(EXIT_FAILURE);
                }
        }

        FILE *vector = fopen("./data/vector.data", "a");

        if (!vector) {
                printf("Error en el archivo vector.data");
                exit(EXIT_FAILURE);
        }

        fclose(vector);
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