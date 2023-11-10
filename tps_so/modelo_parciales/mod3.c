/*
 * hijo -> arhcivo proc procesos del sistema
 * padre -> ejec scrip listado llamado usuarios con nombres que empiezan con so,
 * solo usuario y uid mostrar pid padre e hijo
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void pinfo() { printf("pid: %d, ppid: %d\n", getpid(), getppid()); }
int main(void) {

  int pid = fork();

  if (pid < 0) {
    perror("Error con fork\n");
    fprintf(stderr, "error con fork()\n");
    exit(2);
  }

  if (pid > 0) {
    // padre
    printf("Padre === ");
    pinfo();
    char script[100] = "cat /etc/passwd | awk -F \":\" '/^co/ {print "
                       "\"Usuario: \",$1,\", PID: \",$3}' > usuarios";
    printf("El padre ejecuta el script:\n %s\n\n", script);
    system(script);
    wait(NULL); // para que espere al hijo y se vea bien
  }

  if (pid == 0) {
    // hijo
    printf("Hijo === ");
    pinfo();
    puts("El hijo ejecuta: ps aux > proc");
    system("ps aux > proc");
  }

  return 0;
}
