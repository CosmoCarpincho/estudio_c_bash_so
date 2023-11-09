// #include <fcntl.h> /* Definition of AT_* constants */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

  int fd = fork();

  if (fd < 0) {
    exit(2);
  }

  if (fd > 0) {
    // Padre

    // Por comando:
    /*
    char comando[100] = "if [ ! -d MisDocumentos ];then mkdir MisDocumentos; "
                        "fi; touch 'MisDocumentos/procesos' ";
    system(comando);
    */

    // Por libreria

    // Para ver si existe el directorio se hace con stat pero considero que no
    // es necesario para este nivel.
    int ret;
    if ((ret = mkdir("MisDocumentos", 0700)) != 0) {
      printf("Ya existia el directorio %d\n", ret);
    };

    // Para cambiar de direcotio:
    // chdir("MisDocumentos");

    FILE *archivo = fopen("MisDocumentos/procesos", "w");

    if (archivo == NULL) {
      printf("Error al abrir archivo");
    }

    fclose(archivo);

    printf("Padre pip: %d, ppid: %d\n", getpid(), getppid());
  }

  if (fd == 0) {
    // Hijo
    printf("Hijo pip: %d, ppid: %d\n", getpid(), getppid());
    execlp("ls", "ls", "-la", NULL);
    fprintf(stderr, "Error con ls");
  }
  return 0;
}
