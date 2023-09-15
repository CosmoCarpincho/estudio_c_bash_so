#include<iostream>
using namespace std;

int opcion,a,b,resultado;

void Menu();
void Operaciones(int);
void Suma(int,int);
void Resta(int,int);
void Multiplicacion(int,int);
void Division(int,int);

void Menu(){
	cout<<"Calculadora:"<<endl;
	cout<<"1- Suma"<<endl;
	cout<<"2- Resta"<<endl;
	cout<<"3- Multiplicacion"<<endl;
	cout<<"4- Division"<<endl<<endl;
	cout<<"Opcion: "; cin >> opcion;
}

void Operaciones(int opcion){
	cout << "ingrese dos numeros : " << endl;
	cin >>a>>b;
	switch (opcion){
	case1:
		Suma(a,b);
		break;
	case2:
		Resta(a,b);
		break;
	case3:
		Multiplicacion(a,b);
		break;
	case4:
		Division(a,b);
		break;
	}
}

void Suma(int a, int b){
	cout << "El resultado de "<<a<<" + "<<b<<" = "<< a + b <<endl; 
}
void Resta(int a, int b){
	cout << "El resultado de "<<a<<" - "<<b<<" = "<< a - b <<endl; 
}
void Multiplicacion(int a, int b){
	cout << "El resultado de "<<a<<" x "<<b<<" = "<< a * b <<endl; 
}
void Division(int a, int b){
	cout << "El resultado de "<<a<<" / "<<b<<" = "<< a / b <<endl; 
}


int main(){
	Menu();
	Operaciones(opcion);
	return 0;
}