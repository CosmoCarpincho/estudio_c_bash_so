/******************************************************************************

 EJEMPLO: 

SE NECESITA DETERMINAR LA RECAUDACIÓN PROMEDIO DE TODAS LAS 20 SUCURSALES DE LA EMPRESA TEXTIL.

ESTRATEGIA

ENTRADA (20)
INGRESAR RECAUDACIÓN DE SUCURSALES
PROCESO
GUARDAR EN UN LISTA
SUMAR TODAS LAS RECAUDACIONES
SALIDA
DIVIDIRLAS LA SUMA DE RECAUDACIÓN POR 20
IMPRIMIR EL PROMEDIO


*******************************************************************************/

#include <stdio.h>

int main()
{
    const int suc=5;
  
    float lista[suc];
    
    int i;
    
    float suma=0;
    
    for(i=0;i<=4;i++)
    
        {
            printf("Recaudacion de la Sucursal %d \n", i);
            scanf("%f", &lista[i]);
            
        }
    
    for(i=0;i<=4;i++)
    
        {
            suma=suma +lista[i];
            
        }
    
    printf("El promedio de Recaudación es  %f \n", (suma/suc));
    
    
    }
