#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]){

    FILE *temperaturas = fopen("temperaturas.data","r");
    if (!temperaturas){
        printf("No he podido abrir el archivo\n");
       return 1;
    }

    // ftell retorna la posicion del cursor. placeholder ld. Si da error devuelve -1
    long pos = ftell(temperaturas);
    printf("El cursor esta en el: %ld posicion\n", pos);


    FILE *nombres = fopen("nombres.txt", "a");

    //fputc  ::: sirve para escribir caracteres
    int condicion = 1;
    while (condicion != -1) ///113 === q en ascii
    {
        char nombre[30];
        printf("Si desea salir ingrese quit\n");
        printf("\nIngrese el nombre a guardar: ");
        scanf("%s", nombre);
        printf("\n");
        
        if (strcmp(nombre, "quit") == 0){
            condicion = -1;        
        }
        else{
            int i;
            int res;
            for (i = 0;nombre[i] != '\0' && i < 30; i++){
                res = fputc((char)nombre[i], nombres);
                if (res == EOF){
                printf("Ups, algo ha salido mal");
                return 1;
                }
                else
                {
                    printf("%c",res);
                }
                
            }
            }
            int result = fputc('\n',nombres); // Guarda un caracter en el archivo donde esta el cursor, para manejar errores devuelve int. (devuelve EOF error)
            
            if (result == EOF){
                printf("Ups, algo ha salido mal");
            }
            else{
                printf("%c",result);
            }
        
            
    }
    
    // FILE* apellidos = fopen("apellidos.txt");

    // if (!apellidos){
    //     fputc
    // }
    
    


    fclose(temperaturas);
    fclose(nombres);

    return 0;
}