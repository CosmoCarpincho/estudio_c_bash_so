// Mostrar pid nombre hijo3
// del hijo que crea los nietos
// pid nombre 4 nietos
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // para que se vean en orden
#include <unistd.h>

void pdata() { printf("  pid: %d, ppid: %d\n", getpid(), getppid()); }
int main() {

  for (int i = 1; i < 5; i++) {
    int pid1 = fork();

    if (pid1 < 0) {
      fprintf(stderr, "error forkń");
      exit(2);
    }
    if (pid1 > 0) {
      // padre
      if (i == 1) {
        printf("Padre ==");
        pdata();
      }
      wait(NULL);
    }
    if (pid1 == 0) {
      // hijos
      if (i == 1) {
        printf("Hijo%d == ", i);
        pdata();
      }
      if (i == 2) {
        printf("Hijo%d == ", i);
        pdata();
      }
      if (i == 3) {
        for (int j = 1; j < 4; j++) {
          int pid2 = fork();
          if (pid2 < 0) {
            fprintf(stderr, "Error fork 2");
            exit(3);
          }

          if (pid2 > 0) {
            // Hijo3
            if (j == 1) {
              printf("Hijo%d == ", i);
              pdata();
            }
            wait(NULL);
          }

          if (pid2 == 0) {
            if (j == 1) {
              // Nieto1
              printf("Nieto%d == ", j);
              pdata();
            }
            if (j == 2) {
              // Nieto2
              printf("Nieto%d == ", j);
              pdata();
            }
            if (j == 3) {
              // Nieto3
              printf("Nieto%d == ", j);
              pdata();
            }
            break;
          }
        }
      }
      if (i == 4) {
        printf("Hijo%d == ", 4);
        pdata();
        // execlp("ps", "ps", NULL);
        printf("hijo 4 ejecuta ps\n");
        wait(NULL);
        system("ps aux | grep $(whoami) ");
      }

      break;
    }
  }

  return 0;
}
