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