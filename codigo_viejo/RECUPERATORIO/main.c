#define CANT_REGISTROS 10
#define EXIT "exit"
#define PRIMER_WHILE 1
#define EXIT_WHILE 2
#define RESIDUO_WHILE 0
#include <stdio.h>
#include <string.h>
#include "definiciones.h"
#include "implementaciones.c"

int main(int argc, char const *argv[])
{   

    printf("ESTO COMPILA\n");

    Producto arrProductos[CANT_REGISTROS];
    
    

    Pedido arrPedidos[CANT_REGISTROS];
    
    

    

    //Menu
    int op = 0;
    char opString[5];//   lo dejo en string porque quiero usar un concatenar y no se si funciona con char
    int c; //Necesito que sea int porque EOF es -1

    printf("Bienvenido al programa\n\n");
    char exit[5] = EXIT;
    do
    {
        printf("1) Cargar producto y pedidos \n2) Opcion 2 ver\n 3( Procesarrr\n\\");
        printf("Ingrese la opcion deseada: ");

        int flag = PRIMER_WHILE;
        int k = 0;
        while ((c = getchar()) != '\n')
        {   

            if (flag == PRIMER_WHILE)
            {
                op = (int)c; //ASCII: 49  es el simbolo 1
                opString[k] = c;
                flag = EXIT_WHILE;
                k++;
                continue;
            }

            if (flag == EXIT_WHILE)
            {
                opString[k] = c;
                if (k == 3)
                {
                    flag = RESIDUO_WHILE;
                    opString[k+1] = NULL;
                }
                k++;
                continue;
            }
        }

        switch (op)
        {
        case 49:
            
            cargarProductos(arrProductos, CANT_REGISTROS);
            cargarPedidoss(arrPedidos, CANT_REGISTROS);

            break;   

        case 50:
            mostrarProductos(arrProductos, CANT_REGISTROS);
            mostrarPedidos(arrPedidos,CANT_REGISTROS);
            break;

        case 51:
            procesarPedidos(arrProductos, CANT_REGISTROS, arrPedidos, CANT_REGISTROS);
            break;


        default:
            
            if (!(strcmp(opString,exit)))
            {
                printf("La opcion ingresada es incorrecta\n\n"); 
            }
            break;
        }

    } while (strcmp(opString,exit));


    return 0;
}
