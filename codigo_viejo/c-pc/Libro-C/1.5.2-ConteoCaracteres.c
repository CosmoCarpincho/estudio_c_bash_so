#include <stdio.h>

int main()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
        ++ nc;
        printf("%ld\n", nc);

    //con for
    double n;
    
    for (n = 0; getchar() != EOF; ++n)
    {
       ; //promosicion nula
    }
    printf("%.0f\n", n);
    
    return 0;
}