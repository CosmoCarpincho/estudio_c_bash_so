#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

  int fd = fork();

  if (fd < 0) {
    printf("Error fork");
    exit(2);
  }

  if (fd > 0) {
    // Padre
    wait(NULL);
    puts("Proceso padre");
  }

  if (fd == 0) {
    // Hijo
    printf("Proceso hijo pid: %d, ppid: %d\n", getpid(), getppid());
    execlp("ls", "ls", "-la", NULL); // recordar que no sigue mas.
    fprintf(stderr, "Error con ls");
  }

  return 0;
}
