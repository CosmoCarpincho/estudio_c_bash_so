#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int fd = fork();

  if (fd < 0) {
    fprintf(stderr, "Error: con el fork\n");
    exit(3);
  }

  if (fd > 0) {
    // Padre
    puts("Soy el padre");
  }

  if (fd == 0) {
    // Hijo
    puts("Soy el hijo");
  }

  return 0;
}
