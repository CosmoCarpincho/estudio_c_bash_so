/* Como crear en C: ps -efl | cut -c5-12 | sort -u
 * -elf da muchos datos
 * -c5-12 corta del caracter 5 al 12
 * -u unique. Quita los repetidos
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int pipe1[2];
  pipe(pipe1);
  char s[64];

  int pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Error con fork\n");
    exit(-1);
  }

  if (pid == 0) {
    // Padre
    close(pipe1[1]);
    close(STDIN_FILENO);
    // dup(pipe1[0]);
    dup2(pipe1[0], STDIN_FILENO);
    close(pipe1[0]);

    // scanf("%[\x01-\x7F]", s); // funciona porque lee todo lo que tenga dentro
    // de los corchetes.
    //  acepta regex. acepta caracteres en octal y en hexa. etc
    //  [^\n] acepta secuencia de escape. En este caso lee todo menos salto de
    //  linea. Ahi se interrumpe.
    //  MEJOR USAR fgets()
    fgets(s, sizeof(s) - 1,
          stdin); // recordar que las funciones de files trabajan con el struct
                  // file y no directamente con el fd.
    printf("padre: %s", s);
  }

  if (pid > 0) {
    // Hijo
    strcpy(s, "Hola mundo curso ssoo\n");
    close(pipe1[0]);
    close(STDOUT_FILENO);
    // dup(pipe1[1]);
    dup2(pipe1[1], STDOUT_FILENO);
    close(pipe1[1]);
    printf("%s", s);
  }

  return 0;
}
