/* Como crear en C: ps -efl | cut -c5-12 | sort -u
 * -elf da muchos datos
 * -c5-12 corta del caracter 5 al 12
 * -u unique. Quita los repetidos
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error_fork() {
  fprintf(stderr, "Error con fork\n");
  exit(-1);
}

int main(int argc, char **argv) {

  int pipe1[2];
  int pipe2[2];
  pipe(pipe2);

  int pid = fork();

  if (pid < 0)
    error_fork();

  if (pid > 0) {
    // Padre pid
    puts("Entro en padre");

    close(STDIN_FILENO);
    close(pipe2[1]);
    dup(pipe2[0]);
    close(pipe2[0]);

    //    int c, j;
    //    for (j = 0; (c = getchar()) != EOF; j++) {
    //      printf("%c", c);
    //    }
    execlp("sort", "sort", "-u", NULL);
    puts("Error sort");
  }

  if (pid == 0) {
    // Hijo pid
    pipe(pipe1);
    int pid2 = fork();
    if (pid2 < 0)
      error_fork();

    if (pid2 > 0) {
      // Padre pid2 = Hijo pid
      close(STDIN_FILENO);
      close(pipe1[1]);
      dup(pipe1[0]);
      close(pipe1[0]);
      /*
            // CODIGO ERROR
            //  Esto de ma el siguiente error y no se porque:
            //  Señal 17 (CHLD) capturada por ps (4.0.3).
            //  ps:src/ps/display.c:75: por favor informe de este erro
            char buff[100000];

            fgets(buff, sizeof(buff) - 1, stdin);
            // fflush(stdin);
            close(0); // SOLUCION: si se cierra el fd no rompe
            // La conclusión es que el otro proceso queda enviando stream a el
         pipe
            // que si no lo cerras da error.

            printf("Leo la stdin de otro proceso por pipe: %s\n", buff);
            // FIN ERROR CODIGO ERROR
      */

      /*
      // Forma usando while para traer todas las lineas hasta EOF
      // Cuando llega a EOF devuelve NULL que es un puntero void a cero
      char buff2[1000];
      while (fgets(buff2, sizeof(buff2) - 1, stdin))
        printf("%s", buff2);
      */

      /* // Funciona porque trae todos los caracteres hasta el EOF.
      int c;
      for (int i = 0; (c = getchar()) != EOF; i++) {
        putchar(c);
      }
      */

      close(STDOUT_FILENO);
      close(pipe2[0]);
      dup(pipe2[1]);
      //  dup2(pipe2[1], STDOUT_FILENO);
      close(pipe2[1]);
      execlp("cut", "cut", "-c5-12", NULL);
      puts("Error cut");
    }

    if (pid2 == 0) {

      // Hijo pid2
      // execlp deja de ejecutar el proceso reemplazandolo por el comando usando
      // su imagen. ps devuelve por stdin entonces cambiar esos fd
      close(STDOUT_FILENO);
      close(pipe1[0]);
      dup(pipe1[1]);   // Duplica en el fd de menor número. En este caso en 1.
      close(pipe1[1]); // Cerramos el fd de pipe1[1] ya que esta tambien abierto
                       // en 1.
      close(pipe2[0]);
      close(pipe2[1]);
      execlp("ps", "ps", "-elf", NULL);
      puts("Error ps");
    }
  }

  return 0;
}
