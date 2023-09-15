#include <stdio.h>

int main() {
	int tam; // Desde c99 pero gcc con norma c89 tiene algunas librerias extras y lo permite.
	printf("Cuantos elementos vas a meter? ");
	scanf("%d", &tam);
	int i, edades[tam];
	for (i = 0; i < tam; i++){
		printf("Introduce la edad %d: ", i+1);
		scanf("%d", &edades[i]);

	}
	for (i = 0; i < tam; i++){
		printf("edades[%d] = %d\n", i, edades[i]);
	}
	return 0;
}
	
