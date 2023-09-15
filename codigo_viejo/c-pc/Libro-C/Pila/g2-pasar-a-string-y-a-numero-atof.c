#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    float val;
    char str[20];

    strcpy(str, "1234567");
    val = atof(str);
    printf("String value = %s, Float value = %f\n", str, val);

    strcpy(str, "m");
    val = atoi(str);
    printf("String value = %s, Int value = %d\n", str, val);

    return 0;
}