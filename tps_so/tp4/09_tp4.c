// para 2 procesos hijos
// Voy a armar fork dentro de fork. Podria ser dos fork hermanos tambien.
// Y voy a esperar para que quede el orden hijo padre abuelo
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

  int fd = fork();

  if (fd < 0) {
    fprintf(stderr, "Error fork\n");
    exit(3);
  }

  if (fd > 0) {
    // Abuelo
    wait(NULL);
    printf("Abuelo pid: %d, ppid: %d\n", getpid(), getppid());
  }

  if (fd == 0) {
    int fd2 = fork();

    if (fd2 < 0) {
      fprintf(stderr, "Error del segundo fork\n");
      exit(4);
    }

    if (fd2 > 0) {
      // Padre
      wait(NULL);
      printf("Padre pid: %d, ppid: %d\n", getpid(), getppid());
    }

    if (fd2 == 0) {
      // Hijo
      printf("Hijo pid: %d, ppid: %d\n", getpid(), getppid());
    }
  }

  return 0;
}
