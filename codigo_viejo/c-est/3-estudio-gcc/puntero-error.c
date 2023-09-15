int foo (int *p);

int main (void){

	int *p = 0; // Puntero nulo
	return foo (p);
}

int foo (int *p){
	int y = *p;
	return y;

