#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper){
        celsius = 5 * (fahr-32)/9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

    int cant = sizeof(int);
    
    int rnum = pow(2,cant * 8) / 2 - 1;
    printf("Camtidad de byte de int: %d, rango numerico: %d\n", cant, rnum );

    rnum++;
    printf("Camtidad de byte de int: %d, rango numerico: %d\n", cant, rnum);
    return 0;
}
