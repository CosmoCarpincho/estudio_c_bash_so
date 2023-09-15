#include <stdio.h>
#include <math.h>  // para atof()
#include <stdlib.h> // parece ser que el atof() esta aca. Convierte string en float. OJO que es un arreglo si pongo caracteres con 'x' rompe.

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

// Calculadora polaca inversa
main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: divisor cero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: comando desconocido %s\n", s);
            break;
        }
    }

    return 0;

}


#define MAXVAL 100

int sp = 0;             // siguiente posicion libre en la pila
double val[MAXVAL];     // valores de la pila

void push(double f)
{
    if (sp < MAXVAL)
        val[sp ++] = f;
    else
        printf("error: pila llena, no puede efectuar push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: pila vacia\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

// getop: obtiene el siguiente operador u operando numerico
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; // no es un número
    i = 0;
    if (isdigit(c)) // reúne la parte entera
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.') // reúne la parte fraccionaria
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer para ungetch
int bufp = 0; // siguiente posición libre en buf

int getch(void) // obtiene un (posiblemente ya regresado) caracter
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // regresa carácter a la entrada
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: demasiados caracteres\n");
    }
    else
            buf[bufp++] = c;
}
