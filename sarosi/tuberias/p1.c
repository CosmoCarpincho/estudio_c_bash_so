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
    read(pipe1[0], s, sizeof(s));
    close(pipe1[0]);
    printf("Soy el padre he leido desde el fd %d la cadena: %s\n", pipe1[0], s);
  }

  if (pid > 0) {
    // Hijo
    strcpy(s, "Hola mundo curso ssoo\n");
    close(pipe1[0]);
    write(pipe1[1], s, strlen(s));
    close(pipe1[1]);
    printf("Soly el hijo he escrito en el fd %d la cadena: %s\n", pipe1[1], s);
  }

  return 0;
}
