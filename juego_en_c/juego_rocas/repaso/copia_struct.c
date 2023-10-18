#include <stdio.h>
#include <string.h>

struct habilidades {
        char habilidad[30];
        unsigned int rango;
};

struct persona {
        char nombre[30];
        short int edad;
        struct habilidades habilidades;
};

struct grupo_personas {
        int numero;
        struct persona *persona;
};

void print_persona(struct persona *per) {
        printf("nombre: %s\n", per->nombre);
        printf("edad: %i\n", per->edad);
        printf("habilidad: %s\n", per->habilidades.habilidad);
        printf("rango: %i\n", per->habilidades.rango);
}

int main() {

        struct persona p1 = {.nombre = "Cosmo",
                             .edad = 30,
                             .habilidades.habilidad = "Programación",
                             .habilidades.rango = 10};

        printf("Imprimo p1 \n");
        print_persona(&p1);
        struct persona p2;

        p2 = p1;

        printf("imprimo p2\n");
        print_persona(&p2);

        strcpy(p1.nombre, "pepe");
        p1.edad = 20;
        strcpy(p1.habilidades.habilidad, "Hacer mates");
        p1.habilidades.rango = 8;

        printf("cambios en p1\n");
        printf("imprimo p1 y p2\n");
        print_persona(&p1);
        print_persona(&p2);

        printf("\n\n STRUCTS CON PUNTEROS\n");

        struct grupo_personas g1, g2;

        g1.numero = 1;
        g1.persona = &p1;

        g2 = g1;

        g1.persona->edad = 999;
        g2.persona->edad = 333;

        printf("g1.persona->edad: %i\n", g1.persona->edad);
        printf("g2.persona->edad: %i\n", g2.persona->edad);

        printf("Se observa claramente que se copian los punteros y no lo que apunta. Por "
               "lo tanto quedan dos punteros a la misma estructura\n\n");

        return 0;
}