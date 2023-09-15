#include <stdio.h>

// Declaramos un enum sin asignarle declarar variables de este tipo enum
enum weekDays {Monday, Tuesday, Wedneday, Friday, Saturday,Sunday};

// Declaramos un enum y declaramos las variables card de tipo deek que es tipo enum

enum deek {
    copa = 5,
    copa2,
    copa3,

    espada = 10,
    espada2,
    espada3,

    oro = 15
} card1, card2, card3;

int main()
{
    enum weekDays today;
    today = Sunday;
    printf("Day %d\n", today+1);

    card1 = espada;
    card2 = espada2;
    card3 = copa3;

    printf("Power de las cartas\n");
    printf("Power this one card espada: %d\n", card1);
    printf("Power this two card espada2: %d\n", card2);
    printf("Power this three card copa3: %d\n", card3);

    return 0;
}