#include <stdio.h>
#define SI 1
#define NO 0


int main()
{
    int balas = 50000;
    printf("desplegando arma principal\n");
    int i;
    for(i = 0; i < balas; ++i)
        printf("disparando %d balas\n",i);
    printf("\nenemigo eliminado\n");
    return 0;
}