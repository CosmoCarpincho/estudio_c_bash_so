#include <stdlib.h>
#include "pila_impl.c"

int main(int argc, char const *argv[])
{
    pila * p = new_pila(10);

    p->push(p, 11);
    p->push(p, 7);
    p->push(p, 35);

    printf("El iltimo elemento removido: %d\n", p->pop(p));
    printf("El iltimo elemento removido: %d\n", p->pop(p));
    printf("El iltimo elemento removido: %d\n", p->pop(p));
    return 0;
}
