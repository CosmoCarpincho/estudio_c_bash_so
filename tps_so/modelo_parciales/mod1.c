/*
 * Hijo1 script genere archivo de salida de nombre mem-info:
 *   - Total de memoria del sistema
 *   - TOtal de memoria Usada
 *   - Numero de procesos ejecutables esperando para accedera la CPU
 *   - Numero de proceso en un estado dormido continuo
 *
 * Hijo3 ejecutar script que genere archivo nombre Process con los procesos de
 * todos los usuarios.
 *
 * Padre ---> Hijo1
 *            Hijo2 --> Hijo21
 *                  ---> Hijo22
 *                  ---> Hijo 23
 *            Hijo3
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void datos_procesos(void) {
  printf("pip: %d , ppid: %d\n", getpid(), getppid());
}

int main() {

  for (int i = 0; i < 3; i++) {

    int pid1 = fork();

    if (pid1 < 0) {
      fprintf(stderr, "Error con el fork()\n");
      exit(3);
    }

    if (pid1 > 0) {
      // padre
      if (i == 0) // Para que no repita los mensajes
      {
        printf("Padre -- ");
        datos_procesos();
      }
      wait(NULL);
    }

    if (pid1 == 0) {
      // hijos

      if (i == 0) {
        // Hijo 1
        printf("Hijo 1: ejecuto script");
        datos_procesos();
        system("./script1.sh");
        wait(NULL);
        // execlp("./script1.sh", "script1.sh", "", NULL);
      } else if (i == 1) {
        // Hijos 2
        for (int j = 0; j < 3; j++) {
          int pid2 = fork();
          if (pid2 < 0) {
            printf("Error foek");
            exit(4);
          }

          if (pid2 > 0) {
            // Hijo 2
            if (j == 0) {
              printf("Hijo 2 == ");
              datos_procesos();
            }
            wait(NULL);
          }

          if (pid2 == 0) {
            // Hojo 2.X
            printf("Hijo 2.%d  == ", j + 1);
            datos_procesos();

            break;
          }
        }
        break;
      } else if (pid1 == 0 && i == 2) {
        //  Hijo 3
        printf("i : %i ", i);

        printf("=================\n\n");
        printf("Hijo 3 ejecuto script ;;; ");
        datos_procesos();
        system("ps");
        wait(NULL);

        // execlp("ps", "ps", "aux", NULL);
        printf("=================\n\n");
        break;
      }
      break; // Para que los hijos no cree
    }
  }

  return 0;
}
