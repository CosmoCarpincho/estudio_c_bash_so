#include <stdio.h> // Busca en ubicacion de librerias standar. Depende del SO. Y pega todo el codigo en esta Linea
//#include "<ruta relativa>.h" Idem pero con ruta relativa 

//#error No compiles esto    // muestra un error de compilacion

#define VALOR_EN_PROGRAMA Valor_REAL //Reemplaza desde esta linea para abajo el VALOR_EN_PROGRAMA  por Valor_REAL.
#define MAX_REGISTRO 10

#undef VALOR_EN_PROGRAMA //Elimina el define.

#define VALOR  //SI no hago reemplazo me guarda una posicion de memoria sirve para los if, ifdef, etc

//MACROS es un reemplazo que se le puede pasar argumentos en este caso reemplazaria AREA_RECTANGULO(x,y) por (x * y). Es equivalente a la funcion de area_rectanculo pero es mas rapido porque no crea variables locales sino que solo hace la sustitucion como de copiar y pegar se hablara.
#define AREA_RECTANGULO(x,y) (x) * (y)

//esto se hace si no usas macro pero las macros son mas rapidas
int area_rectangulo(int ancho, int alto)
    {
        return ancho * alto ;
    }
#define LIMITE 80
#define VALOR 50


int main(int argc, char const *argv[])
{
    
#if LIMITE < VALOR
    int ancho = 5, alto = 4;
    printf("El area de un rectangulo es %d x %d = %d. \n", ancho, alto,AREA_RECTANGULO(ancho, alto));
#elif VALOR < 0
    printf("Es menor que cero y que el limite\n")

#else
    printf("Es menor que el LIMITE pero mayor que cero\n");
#endif


//Defined como condicion para el if
#define PREMIUM2

#if defined(PREMIUM) 
    printf("Tu cuenta es premium\n");
#else
    printf("Tu cuenta no es premium\n");
#endif

#if defined (PREMIUM2) // no funciona el ifdef en gcc windows
    printf("Es premium y El ifdef equivale a if defined\n");
#endif


// si no sucede algo entonces ... no funciona ifndef en gcc windows
#if !defined (PREMIUM)
    printf("No es premium, y el ifndef es la negacion de if\n");
#endif




    return 0;
}
