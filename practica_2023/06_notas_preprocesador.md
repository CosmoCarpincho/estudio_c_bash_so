# Notas preprocesador Makigas

El preprocesador procesa los las sentencias del preprocesador. Son las que conmienzas con #.  
``` c
#include <algo>  ;;; copia el codigo de la libreria en esta region. en directorios del SO.
#include "algo"  ;;; idem pero rutas relativas

#define <palabra a sustituir> <reemplazo>
#define LIMITE 100    ;;; reemplaza en donde encuentra LIMITE por 100

#undefine <algo> ;;; para eliminar el define

REEMPLAZAR FUNCIONES CON DEFINE (Macros)

#define NOMBRE_MACRO(PARAMETROS) (REEMPLAZO)
#define AREA_RECTANGULO(x, y) (x*y)

ERROR DE COMPILACIÓN
#error "No compiles esto"  ;;; esto se resuelve en tiempo de compilación


IF

#if LIMITE < 50
  printf("Limite por debajo de 50\n");

#else
printf("50 o mas");

#endif


IF con defined y define
#define PREMIUM

#if defined(PREMIUM)  ;;;; forma corta #ifdef
  printf("Estás usando la versión premium\n");
#else
  printf("Estás usando la versión gratuita\n");
#endif


Para negar el la condición del if
#ifndef
```