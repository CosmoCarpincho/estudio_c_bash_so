// HEADER de pila, definicion

//definicion del objeto/estructura
typedef struct pila pila;

struct pila {
    int size;
    int index;
    int * content;
    //metodos
    void (* push)(pila * this, int val);
    int (* pop)(pila * this);

};

//definicion de los metodos
void pila_push(pila * this, int val);
int pila_pop(pila * this);

//constructor
pila * new_pila(int size);
