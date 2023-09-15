#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Video 3x01 Archivos fopen y fclose
    // FILE* ::: Descriptor. Es un puntero a el archivo. Con F12 se puede ver que es un struc que tiene un puntero .
    // fopen (ruta, modo de acceso r read w lectura r+ lectura y escritura) Retorna un descriptor, que es un puntero a un archivo ::: FILE*
    // Cuando abre el archivo lo manda a un buffer de tipo FILE. 

    FILE *temperaturas = fopen("temperaturas.data", "r");

    // Si fopen no funciona devuelve devuelve NULL
    // NULL es puntero a cero al negarlo te da 1. En hexadecimal.
     if (!temperaturas){
        printf("No he podido abrir el archivo.");
        return 1;
    }

    //Leer archivo
    //fgetc lee un caracter del archivo. Arranca donde esta el cursor que fue definido en el modo de fopen. r esta al principio
    // fgetc devuelve int para que pueda devolver cosas que no son un caracter.
    //Si falla 
    int leido = fgetc(temperaturas);
    printf("Eh leido el caracter: %c\n\n", (char)leido);

    //feof sirve para ver si estas en fin de archivo. devuelve 0 no estas al final del archivo.
    int c;
    while ( c = !feof(temperaturas))
    {
        int leido = fgetc(temperaturas);
        printf("%c", (char) leido);
    }
    
    



    // Para cerrar el archivo que contiene el archivo se usa fclose
    fclose(temperaturas);

    // En el standar c NULL es un puntero a la posicion de memoria 0x0
    // y 0 en el stadar c tambien es un puntero a la posicion 0x0 por lo tanto son equivalentes.
    // No se puede acceder a la direccion de memoria 0 pero si apuntar. SI uno intenta hacer un printf con *p1
    // va a dar el error segmentation fault porque no esta permitido acceder.
    // https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
    int *p1 = NULL;
    int *p2 = 0;
    if(p1 == p2){
        //printf("p1 dir memoria %x, valor: %s  y p2 dir memoria %x, valor %s son equivalentes", p1, *p1, p2, *p2);
        printf("Son iguales\n");
    }

    printf("%x\n",p1);

    p1 = !p1;

   

    // Tamaio de arreglo con libreria vcruntime.h

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // Si apretas F12 en NULL te lleva  aun archivo llamado vcruntime.h . Define si usas c es un puntero a 0 si usas c++ es el valor cero. 
    // quise ejecutar __crt_countof(arr) pero el compilador que uso gcc en realidad no lo tiene
    // entonces me di cuenta que lo que se ve con f12 no es lo mismo que el gcc q estoy usando OJOOOO al PIOJOOO
    //int tam = __crt_countof(arr);
    return 0;
}
