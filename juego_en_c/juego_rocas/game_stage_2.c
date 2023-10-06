#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

// Extras
#include <sys/stat.h>

// Revisar sintaxis. ¿Porque tantos paréntesis?
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Tam pantalla
#define MAX_X 60 // Incluye el ultimo carácter.
#define MAX_Y 26

static struct termios old_termios, new_termios;

void reset_terminal() {
        printf("\e[m");    // reset color changes
        printf("\e[?25h"); // show cursor
        printf("at reset terminal\n");
        fflush(stdout);
        tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

void configure_terminal() {
        tcgetattr(STDIN_FILENO, &old_termios);
        new_termios = old_termios;

        new_termios.c_lflag &=
            ~(ICANON | ECHO); // turn off echo + non_canonical
        new_termios.c_cc[VMIN] = 0;
        new_termios.c_cc[VTIME] = 0;

        tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

        printf("\e[?25l");      // hide cursor
        atexit(reset_terminal); // esta función se llama cuando se salga del
                                // programa.
}

static int exit_loop;

void signal_handler(__attribute__((unused)) int signum) { exit_loop = 1; }

int read_key(char *buf, int k) {
        if (buf[k] == '\033' && buf[k + 1] == '[') {
                switch (buf[k + 2]) {
                case 'A':
                        return 1; // UP
                case 'B':
                        return 2; // DOWN
                case 'C':
                        return 3; // RIGHT
                case 'D':
                        return 4; // LEFT
                }
        }
        return 0;
}

int read_input() {
        char buf[4096]; // maximum input buffer
        int n = read(STDIN_FILENO, buf, sizeof(buf));
        int final_key = 0;
        // it's okay if we miss some keys
        // we will correct it on next frame
        for (int k = 0; k <= n - 3; k += 3) {
                int key = read_key(buf, k);
                if (key == 0)
                        continue;
                final_key = key;
        }
        return final_key;
}

void extra1() {

        struct stat info;
        fstat(STDIN_FILENO, &info);
        printf("Tam: %ld\n", (long)info.st_size);
        printf("Tam: %ld\n", (long)info.st_blksize);
}

void print_key(int key) {
        if (key == 1)
                printf("Up\n");
        if (key == 2)
                printf("Down\n");
        if (key == 3)
                printf("Right\n");
        if (key == 4)
                printf("Left\n");
}

// En casi 2 y 3 hay que tener ewn cuenta el carácter de nueva linea. (no es
// simétrico). Las posiciones 0 es la de borde.
void handle_player(int key, int *pos_x, int *pos_y) {
        switch (key) {
        case 1:
                *pos_y = MAX(1, *pos_y - 1);
                break;
        case 2:
                *pos_y = MIN(MAX_Y - 2, *pos_y + 1);
                break;
        case 3:
                *pos_x = MIN(MAX_X - 3, *pos_x + 1);
                break;
        case 4:
                *pos_x = MAX(1, *pos_x - 1);
                break;
        }
}

void render(int pos_x, int pos_y) {
        // No funciona en mi LXTerminal. Quedan todos los frames arriba.
        // printf("\033[2J");   // Clearing the screen

        // Uso clear de la consola. Aunque es mas lento
        //   system("clear");
        printf("\033[1;1H"); // Move to upper left corner

        for (int i = 0; i < MAX_X - 1; ++i) {
                printf("X");
        }
        printf("\n");

        for (int j = 1; j < MAX_Y - 1; ++j) {
                printf("X");
                for (int i = 1; i < MAX_X - 2; ++i) {
                        if (pos_x == i && pos_y == j) {
                                printf("@");
                        } else {
                                printf(" ");
                        }
                }
                printf("X");
                printf("\n");
        }

        for (int i = 0; i < MAX_X - 1; ++i) {
                printf("X");
        }
        printf("\n");

        fflush(stdout); // Fundamental para que no aparezcan errores
}

// Lower us faster
#define SPEED 0.1

int main() {

        // extra1();
        configure_terminal();

        signal(SIGINT, signal_handler);

        struct timespec req = {};
        struct timespec rem = {};

        int pos_x = 5;
        int pos_y = 5;

        // Como hay problemas con el scroll lo hago antes
        printf("\033[H\033[2J");

        while (!exit_loop) {
                int key = read_input();
                // print_key(key);

                handle_player(key, &pos_x, &pos_y);

                render(pos_x, pos_y);

                req.tv_nsec = SPEED * 1000000000; // 0.1 seconds
                nanosleep(&req, &rem);
        }

        return 0;
}