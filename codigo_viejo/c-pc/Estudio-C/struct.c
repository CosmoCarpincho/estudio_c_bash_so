#include <stdio.h>
#include <string.h>

int main ()
{
    struct alumnos
    {
        char nombre [20];
        char apellido [20];
        float matricula;
        float promedio;
        
        
    } a1, a2, a3;

    strcpy(a1.nombre,"pepe");    
    
    a1.matricula = 2.2;
    a1.promedio = 3;  

    printf("\n%s", a1.nombre);  
    printf("\n%.2f", a1.matricula);  

    // Otra forma de declarar struct

    typedef struct persona
    {
        int edad;
    }per;
    
    per p1;

    p1.edad = 21;
}