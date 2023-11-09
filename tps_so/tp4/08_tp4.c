#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

  int fd = fork();

  if (fd < 0) {
    fprintf(stderr, "Error fork");
    exit(-3);
  }

  if (fd > 0) {
    // Padre
    wait(NULL);
    printf("Soy el padre, \"%d\" , Mi Padre es \"%d\"\n", getpid(), getppid());
  }

  if (fd == 0) {
    // Hijo
    printf("Soy el hijo, \"%d\" , Mi Padre es \"%d\"\n", getpid(), getppid());
    sleep(2);
  }

  return 0;
}
