#include <stdio.h>

int main(void){
	//Variables
	int variableEntera;
	char variableCaracter;
	float variableFlotante;
	char variableString[10];

	//Operaciones Leer y Escribir
	printf("Ingrese un dato entero");
	scanf("%d",&valor);
	printf("\nIngreso: $d", valor);
	
	//Estructura de decision
	if (a != b ){
		void;
	}
	else{
		void;
	}

	//Switch
	switch (valor){
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("3");
			break;
		default:
			printf("Rama falsa");
			break;
	}
	
	//For
	for (int i=1; i<11; i++){
		printf("Valor: %d\n",i);
	
	//While
	while (1){
		printf("Loop Infinito");
	}

	//Arreglos
	
	int vNumeros[10];
	int mNumeros[10][5];

	//Struct
	
	struct Persona{
		char nombre[15];
		char apellido[15];
		int edad;
	};

	struct Persona p1;

	//Procedimientos
	
	//Modulos prototipados o definidos antes de Main
	void moduloA (unParam, otroParam);
	void moduloB (unParam, otroParam){
		void;
	}

	int main(){
		void;
	}

	//Definicion de modulos prototipados
	void moduloA (unParam, otroParam){
		void;
	}


	//PASAJE DE PARAMETROS
	//Procedimiento que recibe dos numeros y devuelve la suma en
	//"resul"
	void unProcedimiento(int param1, int param2, int *resul){
		*resul = param1 + param2; //Para usar el puntero, uso
					  //asterisco
	int x, y, z;

	int main(){
		//..
		unModulo (x, y, &z);//Invoco al procedimiento
		//..
	}
	// Param1 y param2 son parametros recibidos por valor.
	// Resul es un parametro que se rebice por referencia
	
	//PASAJE DE PARAMEROS - REGISTRO
	//Pasaje por referencia
	void cargarPersona (struct Persona *reg){
		strcpy(reg -> apellido, "Apellido");
		strcpy(reg -> nombre, "Nombre");
		reg -> edad = 24;

	//Pasaje por valor
	void mostrarPersona (struct Persona reg){
		printf("Datos de la persona\n-------\n\n");
		printf("Nombre: %s\n", reg.nombre);
		printf("Apellido: %\n", reg.edad);
		getch();
	}

	//FUNCIONES
	//Funcion de tipo entero que recibe dos numeros y retorna la suma
	int unaFuncion (int param1, int param2){
	return param1 + param2;
	}

	int x, y, z;

	int main(){

	z = unaFuncion(x,y); // Invoco a la funcion	
	}

	//LISTAS
	
	struct Producto { // Defino Producto, el registro de datos
		int codigo;
		char nombre[15];
		int stock;
	};

	struct Lista{ // Defino el registro de la lista
		struct Producto dato;
		struct Lista *psig;
	};	

	struct Lista *L; //Declaro una variable tipo Lista

	//NUEVO NODO DE LA LISTA
	
	struct Lista *nuevo=malloc(sizeof(struct Lista));

	//PASAJE DE LISTA POR PARAMETRO
	//
	//Pasaje por referencia
	void porReferencia(struct TipoReg **lista){
		void;
	}
	//Invocacion
	porReferencia(&lista);

	//Pasaje por copia
	void porCopia(struct TipoReg *lista){
		void;
	}
	//Invocacion
	porCopia(lista);

	//PILA
	struct Producto{//Defino producto, el registro de datos
		int codigo;
		char nombre[15];
		int stock;
	};

	struct Pila{ 	//Definicion de pila
		struct Producto dato;
		struct Pila *psig;
	};

	struct Pila *pila;  //Declaro una variable de tipo Pila

	//COlA
	struct Proceso{	//Registro del proceso que almacena la cola
		int id;
		char nombre[20];
		char prioridad[15];
		char estado[15];
	};
	struct lCola{	//Definicion de la lista de la cola
		struct Proceso dato;
		struct lCola *psig;
	};

	struct Cola{	//El regisro que maneja los punteros de cola
		struct lCola *pini;// Puntero inicial
		struct lCola *pfin;// Puntero final
	};
}
