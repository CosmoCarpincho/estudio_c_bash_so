#include <stdio.h>

int main(int argc, char const *argv[])
{
    char opcion;
    printf("MENU\n");

    do{
        printf("Selecciona una opcion [1/5]: ");
        scanf("%c", &opcion);
        printf("Has elegido %c\n", opcion);

        while (getchar() != '\n');
        

        
    }while (opcion < '1' || opcion > '5');


    return 0;
}
