// Ejecutar en proceso padre ps y en proceso hijo ls. Pero que el padre espere a
// que termine el hijo
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  int fd = fork();
  int codigo_error;

  if (fd < 0) {
    printf("ERROR = en fork \n");
  }

  if (fd > 0) {
    printf("Soy el padre mi pid es: %d y el pid de mi padre es: %d\n", getpid(),
           getppid());
    wait(NULL);
    execlp("ps", "ps", NULL);
  }

  if (fd == 0) {
    printf("Soy el hijo mi pid es: %d y el pid de mi padre es: %d\n", getpid(),
           getppid());
    execlp("ls", "ls", "-la", NULL);
  }
  return 0;
}
