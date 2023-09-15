#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *stream = fopen("llenadoFprintf.txt","w");
    char text[200];
    scanf("%s",text);
    fprintf(stream, text);
    return 0;
}
