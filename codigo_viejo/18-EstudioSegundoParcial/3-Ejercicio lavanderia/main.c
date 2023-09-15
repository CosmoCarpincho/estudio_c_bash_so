#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definiciones para el preprocesador. En vez de usar typedef sustituyo las palabras desde el preprocesador
#define Servicio struct servicio 
#define TAMSERVICIOS 6
// 
struct servicio {
    char tipo [30];
    unsigned int precio;
};



int main(void)
{
    Servicio listServicios[TAMSERVICIOS];

    Servicio ser;
    
    char tiposServicios[6][30] = {"Lavanderia","Pantalones","Trajes","Secado","Servicio A", "Servicio B"};
    
    int i1;
    for ( i1 = 0; i1 < TAMSERVICIOS; i1++)
    {
        strcpy(ser.tipo, tiposServicios[i1]);
        ser.precio = 1233 * (i1 +1.3);
        
        listServicios[i1] = ser;
        
    }
    
    int i2;
    for ( i2 = 0; i2 < TAMSERVICIOS; i2++)
    {
        printf("Servicio: %s , precioL %u\n", listServicios[i2].tipo, listServicios[i2].precio);
    }
    
   

    return 0;
}
