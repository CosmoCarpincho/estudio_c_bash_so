#define TIPO_DATO int

#include<stdio.h>

int main(int argc, char const *argv[])
{
    TIPO_DATO num = 3;
    TIPO_DATO num2 = 3;

    TIPO_DATO resultado = num + num2;

    printf("%d", resultado);
    return 0;
}
