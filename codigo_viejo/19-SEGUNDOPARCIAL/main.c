#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define APROBADO 1
#define REPECHAJE 2
#define DESAPROBADO 3


//Todos entregan los tps a la vez


// Structs

// Los datos que van a estar dentro del nodo de la pila
typedef struct AlumnoTP //coincide los datos que se usan en las listas asi que voy a reutilizarlo #1
{
    unsigned int dni;
    char apellido[30];
    char nombre[30];
    int cantidadTP;
    int estado;
}AlumnoTP; 

typedef struct nodoPila
    {
        AlumnoTP dato;
        struct nodoPila * sig;
    }nodoPila;

//Struct de Lista
typedef struct nodoLista
{
    AlumnoTP dato; //#1
    struct nodoLista * sig;
}nodoLista;


void crearPilaVacia (nodoPila ** cabezaPila);
void apilar(nodoPila ** cabezaPila, AlumnoTP dato);
void desapilar(nodoPila ** cabezaPila, AlumnoTP * dato);
int esVaciaPila(nodoPila ** cabezaPila);

void crearListaVacia (nodoLista ** cabezaLista);
void mostrarElementosLista (nodoLista ** cabezaLista);
void insertarPrincipioLista (nodoLista ** cabezaLista, AlumnoTP datoL);

int cantidadRepechaje (nodoLista * cabezaLista);
//int cantAlumnosAprobados(nodoLista * cabezaLista);


int main(void)
{
    //Inicializar Nodos
    nodoPila * cabezaPila;
    nodoLista * cabezaLista;
    
    //Creamos las estructuras vacias
    crearPilaVacia(&cabezaPila);
    crearListaVacia(&cabezaLista);

    //Variables aux de carga de datos
    // unsigned int dniAux;
    // char nombreAux[30];
    // char apellidoAux[30];
    // unsigned int cantidadTPAux;
    // int estadoAux;

    int contAlumnosTotales = 0;
    int cantAlumnosRepechaje = 0;
    int cantAlumnAprobados = 0;
    double porcentaje = 0;

    AlumnoTP alumnoTPAux;

    //Menu

    char opcion = 'x';
    while (opcion != 'q')
    {
        printf("\nMENU\n");
        printf("[1] Ingrese sus tps entregados \n");
        printf("[2] Fin de entregas. Procesar Trabajos. NO INGRESAR A PUNTO LOS SIGUIENTES PUNTOS SIN PROCESAR\n");
        printf("[3] Mostrar alumnos filtrados en la lista.\n");
        printf("[4] Mostrar alumnos en repechaje. (Ejercicio recursivo)\n");
        printf("[5]  Mostrar alumnos en repechaje. (Ejercicio recursivo)\n"); //no LLEGE HAY POR TIEMPO HAY PARTE HECHA
        printf("[q] salir\n");
        scanf("%c",&opcion);
        

        switch (opcion)
        {
            case '1':

                printf("\nIngrese su nombre: ");
                scanf("%s",alumnoTPAux.nombre );
                printf("\nIngrese su apellido:");
                scanf("%s", alumnoTPAux.apellido);
                printf("\nIngrese dni: ");
                scanf("%u",&alumnoTPAux.dni );
                printf("\nIngrese cantidad tps (MAX 10):");
                scanf("%d", &alumnoTPAux.cantidadTP);

                if (alumnoTPAux.cantidadTP >= 8 && alumnoTPAux.cantidadTP <= 10)
                {
                    alumnoTPAux.estado = APROBADO;
                }
                else
                {
                    if ((alumnoTPAux.cantidadTP < 8) && (alumnoTPAux.cantidadTP >= 5))
                    {
                        alumnoTPAux.estado = REPECHAJE;
                    }else
                    {
                        
                        if (alumnoTPAux.cantidadTP > 10)
                        {
                            printf("Dato cargado incorrectamente. Se sale del programa\n");
                            return 0;
                        }else
                        {
                            alumnoTPAux.estado = DESAPROBADO;
                        }
                    }
                }
                apilar(&cabezaPila, alumnoTPAux);
                
                

                
                break;

            case '2':
                //Primero hay que desapilar la pila e ingresar cada dato de alumno a una lista de control
                

                while (!esVaciaPila(&cabezaPila))
                {
                    desapilar(&cabezaPila, &alumnoTPAux);
                    if (alumnoTPAux.estado != DESAPROBADO)
                    {
                        insertarPrincipioLista(&cabezaLista, alumnoTPAux);
                    }
                    
                   contAlumnosTotales++; 
                }       

                break;
            case '3':
                mostrarElementosLista(&cabezaLista);
                break;

            case '4':
                
                cantAlumnosRepechaje = cantidadRepechaje(cabezaLista);
                printf("Cantidad de alumnos en repechaje: %i", cantAlumnosRepechaje);
                
                break;
            
            case '5':
                // printf("Stop\n");
                // cantAlumnAprobados = cantAlumnosAprobados(cabezaLista);
                //  porcentaje = (double)cantAlumnAprobados / (double)contAlumnosTotales;
                // printf("El porcentaje de alumnos aprobados es %f", porcentaje);
                
                break;
        
            default:
                break;
        
        }
        while (getchar() != '\n');
        
    }

    //Liberar memoria
    free(cabezaPila);
    free(cabezaLista);
    return 0;
}

void crearPilaVacia(nodoPila ** cabezaPila)
{
    (*cabezaPila) = NULL;
}



void apilar(nodoPila ** cabezaPila, AlumnoTP dato)
{
    nodoPila *nuevo = (nodoPila *) malloc(sizeof(nodoPila));
    nuevo->dato = dato;
    
    nuevo->sig = (*cabezaPila);
    (*cabezaPila) = nuevo;

}

void desapilar(nodoPila ** cabezaPila, AlumnoTP * dato)
{
    nodoPila * aux;
    aux = (*cabezaPila);
    *dato = aux->dato;
    (*cabezaPila) = (*cabezaPila)->sig;

    free(aux);
}

int esVaciaPila(nodoPila ** cabezaPila)
{
    if ((*cabezaPila)==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}


// Metodos y funciones de Lista
void crearListaVacia (nodoLista ** cabezaLista)
{
    (*cabezaLista) = NULL;
}

void mostrarElementosLista (nodoLista ** cabezaLista)
{
    nodoLista * aux = (*cabezaLista);
    printf("\n");
    char estadoTexto[20];
    while ( aux != NULL)
    {   
        switch (aux->dato.estado)
        {
        case 1:
            strcpy(estadoTexto,"Aprobado");
            break;
        
        case 2:
            strcpy(estadoTexto,"Repechaje");
            break;
        
        case 3:
            strcpy(estadoTexto,"Desaprobado"); //Esta de mas porque no se usa pero asi queda completo
            break;
        
        default:

            break;
        }
       
        printf("| Alumno: %s | %s | %u | tps: %i| estado: %s | | \n ", aux->dato.nombre, aux->dato.apellido, aux->dato.dni, aux->dato.cantidadTP, estadoTexto);

        aux = aux->sig;
    }
    
}

void insertarPrincipioLista (nodoLista ** cabezaLista, AlumnoTP datoL)
{
    nodoLista *nuevo = (nodoLista *) malloc(sizeof(nodoLista));
    nuevo->dato = datoL;
    
    nuevo->sig = (*cabezaLista);
    (*cabezaLista) = nuevo;

}

int cantidadRepechaje (nodoLista * cabezaLista) // Es el punto recursivo
{
if (cabezaLista != NULL ){
        if (cabezaLista->dato.estado = REPECHAJE)
        {
            return cantidadRepechaje(cabezaLista->sig) + 1; // Repechaje aumenta 1 al contador.
        }
        else
        {
            return cantidadRepechaje(cabezaLista->sig);   // Aprobado no aumenta
        }
}
else  {
	
	return 0; //Cuando llega a NULL;
	
	}

}
//NOTA
// no me alcanzaba el timpo asi que decidi para entregar algo del ejercicio que de forma recursiva me devuelva la cantidad
// y a posterior hacer la division
//
// double porcentajeAlumnosAprobados(nodoLista * cabezaLista, double totalAlumnos)
// {
//     if (cabezaLista != NULL ){
//         if (cabezaLista->dato.estado = APROBADOS)
//         {
//             return (porcentajeAlumnosAprobados(cabezaLista->sig, totalAlumnos) * ) + 1; // Aprobado aumenta 1 al contador.
//         }
//         else
//         {
//             return porcentajeAlumnosAprobados(cabezaLista->sig, totalAlumnos);   // Aprobado no aumenta
//         }
// }
// else  {
	
// 	return (1/totalAlumnos); //Cuando llega a NULL;
	
// 	}
// }

// int cantAlumnosAprobados(nodoLista * cabezaLista)
// {
//     if (cabezaLista != NULL )
//     {
//         if (cabezaLista->dato.estado = APROBADO)
//         {
//             return cantAlumnosAprobados(cabezaLista->sig, totalAlumnos) + 1; // Aprobado aumenta 1 al contador.
//         }
//         else
//         {
//             return cantAlumnosAprobados(cabezaLista->sig, totalAlumnos);   //  no aumenta
//         }
//     }
//     else
//     {
	
// 	    return 0; //Cuando llega a NULL;
	
// 	}

// }

