#include <stdio.h>  // printf
#include <stdlib.h> // exit
#include <string.h> //strcpy
#include <unistd.h> // fork

int main() {

  int i;
  int pid;
  char tipo[10];

  for (i = 0; i < 4; i++) {

    pid = fork();

    if (pid < 0) {
      printf("Error en fork");
      exit(-1);
    }

    if (pid > 0) {
      // padre
      strcpy(tipo, "PADRE");
      printf("%s - pid: %d   ppid: %i  i = %d\n", tipo, getpid(), getppid(), i);
      break;
    }

    if (pid == 0) {
      // hijo
      strcpy(tipo, "HIJO");
      printf("%s - pid: %d   ppid: %i  i = %d\n", tipo, getpid(), getppid(), i);
    }
  }
  // printf("%s - pid: %d   ppid: %i  i = %d\n", tipo, getpid(), getppid(), i);
  sleep(50);
  return 0;
}
