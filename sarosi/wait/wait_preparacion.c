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
    int retorno = wait(&codigo_error);
    if (codigo_error != 0) {
      puts("ERROR - proceso hijo no termino correctamente.");
    }

    printf("retorno = %d ; codigo %d\n", retorno, codigo_error);
    puts("Ejecutando ps");
  }

  if (fd == 0) {
    printf("Soy el hijo mi pid es: %d y el pid de mi padre es: %d\n", getpid(),
           getppid());
    puts("Ejecutando otra cosa del hijo");
    exit(-1);
  }
  return 0;
}
