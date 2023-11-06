// La idea es ver los archivos abiertos por el proceso
// Se hace con el comando lsof (list open files)
// lsof -c <prog.out>

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

  int fd = open("archivo.txt", O_RDWR | O_CREAT | O_APPEND, 0600);

  char *saludo;
  saludo = " Hola que tal\n";

  for (int i = 0; i < 3; i++) {
    char n = i + '0';
    write(fd, &n, 1);
    write(fd, saludo, strlen(saludo));
  }

  sleep(60);

  return 0;
}
