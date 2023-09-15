# include <stdio.h>

short Hex_a_int(char Hex){
    if(Hex >= '0' && Hex <= '9')
        return(short)Hex - 48;
    else if(Hex >= 'A' && Hex <= 'F')
        return(short)Hex - 55;
    else if(Hex >= 'a' && Hex <= 'f')
        return(short)Hex - 87;
    else
        return 0;}


int main()
{
    char c = 64;

    printf ("El caracter es: %c  y su numero es %d\n", c, c);
    short s = Hex_a_int('D');
    printf ("Es un short: %hi", s);
    return 0;

}