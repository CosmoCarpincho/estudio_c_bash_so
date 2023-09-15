// Libreria
#include <stdio.h>

//Declaracion de funciones y metodos
int miFuncion(void);

void miMetodo(void);

// Programa Principal
int main()
{
    return 0;
}

// Estructuras

void estructuras (void)
{
    // Condicional
    int condicion = 1;
    if (condicion == 1 && condicion >= 2 || condicion != 0)
    {
        printf("se cumple condicion");
    }
    

    // OJO cuando se ejecuta una instruccion sale del if.
    // Si primera expresion se ejecuta pero en realidad quiero que entre en la 3ra es porque no delimite
    // bien el rango de la expresion1 n > 10  ... y la expresion2 n >20  .  Entra en n>10. 
    //Arreglado exp1 n > 10 && n <= 20.
    int num = 5;
    if (num > 10 && num <= 20)
    {
        printf("Exp1");
        printf("Exp2");
    }
    else if (num > 20)
        printf("Exp3");
    else if (num > 0)
        printf("Exp4");
    else
        printf("Exp5");



    //Switch
    int variable = 1;
    switch (variable)
    {
        case 1:
            printf("Caso 1");
            break;

        case 2:
            break;

        default:
            break;
        
    }


    // Bucle While
    int i = 0;
    while (i < 10)
    {
        /* code */
        i = i + 1;
    }
    

    //Do while
    int cont = 0;
    do
    {
        /* code */
        cont = cont + 1;
    } while (cont > 10);

    //For
    int count = 10;
    int i;
    for (i = 0; i < count; i++)
    {
        /* code */
    }
    
    // Arrays

    double balance[3];
    
    int size = sizeof balance / sizeof balance[0];

    for (int i = 0; i < size; i++)
    {
        /* code */
    }
    

    double balance2[3] = {3.2,6.7,8.5};


    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count; i++)
        {
            /* code */
        }
        
    }

}





