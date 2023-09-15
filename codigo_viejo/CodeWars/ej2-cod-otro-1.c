#include <stdio.h>

char * retornoTexto();

int main(int argc, char const *argv[])
{

    
    printf("%x >> %s", retornoTexto(),  retornoTexto());
    return 0;
}

char * retornoTexto(){

    return "texto retornado por funcion puntero";    
}
