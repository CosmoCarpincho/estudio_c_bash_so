#include <stdio.h>

int main ()
{
    int a,b,c, res;

    a = 1;
    b = 2;
    c = ' ';

    // res = (a = b = c);

    // printf("a:%d\n", a);
    // printf("b:%d\n", b);
    // printf("c:%d\n", c);
    // printf("Resultado:%d\n", res);

    while ((a = b = c) == ' ' || c == '\t')
    {
        printf("entro: %d\n",((a = b = c) == ' ' || c == '\t'));
        c = 12;
    }
    printf("afuera: %d\n",((a = b = c) == ' ' || c == '\t'));
        

    return 0;


}