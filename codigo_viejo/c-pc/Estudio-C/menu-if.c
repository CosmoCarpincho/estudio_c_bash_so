#include <stdio.h>

int main()
{
    titulo("Este es el titulo del trabajo",5,41);
    
    return 0;
}



/* METODOS Y FUNCIONES PARA ESTETICA */

//Saltos de linea. Cant define la cantidad
void sl (int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("\n");
    }
}

// Espacios en blanco
void es (int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf(" ");
    }
}

// Lineas ======
void ln (int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("=");
    }

    sl(1);
}

void titulo (char titulo[100], int sangria, int tamCaja)
{
    ln(tamCaja);
    printf("=");
    es(sangria); 
    printf("%s",titulo);
    es(sangria); 
    printf("=");
    sl(1);
    ln(tamCaja);
}

void utnAscii (void)
{
    printf("MWX000KNMMMMMMMMWNKXXXXNMMMMMMMMWK000KNM");sl(1);
    printf("MXl    dNMMMMMMMX      kMMMMMMMMO     kM");sl(1);
    printf("MWd     kWMMMMMMK      dWMMMMMMK      KM");sl(1);
    printf("MMX      kWMMMMMK      dWMMMMMK      xWM");sl(1);
    printf("MMMK      lKWMMMK      dWMMMXx      dNMM");sl(1);
    printf("MMMMXc      ckKWK      dWXOo       kWMMM");sl(1);
    printf("MMMMMNk       WWW      WWW       lKMMMMM");sl(1);
    printf("MMMMMMMNk                      oKWMMMMMM");sl(1);
    printf("MWNXXXXXXKOo                cx0XXXXXXXNM");sl(1);
    printf("Mk,MMMMMMMMMM              MMMMMMMMMMMoN");sl(1);
    printf("Wd                                    cN");sl(1);
    printf("M0                                    kW");sl(1);
    printf("MMMMMMMMMWK                  MMWMMMMMMMM");sl(1);
    printf("MMMMMMMNk                      dKWMMMMMM");sl(1);
    printf("MMMMMNx       ddd      ddd       oXMMMMM");sl(1);
    printf("MMMW0       ckXWK      dWXkl       kWMMM");sl(1);
    printf("MMM0      lKWMMMK      dWMMMXo      xWMM");sl(1);
    printf("MMK      OWMMMMMK      dWMMMMW0      kWM");sl(1);
    printf("MNl     OMMMMMMMK      dWMMMMMM0      XM");sl(1);
    printf("MNd    kWMMMMMMMN      0WMMMMMMWO     KM");sl(1);
    printf("MMWWWWWMMMMMMMMMMMWWMWWMMMMMMMMMMWWWWWMM");sl(1);
    printf("");sl(1);
}