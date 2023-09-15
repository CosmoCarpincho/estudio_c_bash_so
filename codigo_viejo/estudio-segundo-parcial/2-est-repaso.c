//Primero tengo que repasar todas las estructuras que manejo

#include <stdio.h>

void entrarBoliche (int edad)
{

}




int main (void){

    int op = 0;
    printf("1) Ingresar al boliche\n");
    printf("2) Comprar en el almacen\n");
    printf("Ingrese la siguiente opcion:");
    scanf("%d", &op);
    printf("\n");

    while(op != -1){
       

        switch (op)
        {
        case 1: 
            printf("Ingrese su edad: ");
            
            // funcion ingresar boliche
            break;

        case 2: 
            // funcion comprar en almacer
            break;

        case -1: 
            printf("Gracias por usar la aplicacion\n");
            break;

        
        default:
            printf("La opcion igresada es incorrecta");
            break;
        }
        
        printf("1) Ingresar al boliche\n");
        printf("2) Comprar en el almacen\n");
        printf("Ingrese la siguiente opcion:");
        scanf("%d", &op);
        printf("\n");
    }
    
}