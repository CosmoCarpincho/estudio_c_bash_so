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

typedef struct {
        int key;
        int pos_x;
        int pos_y;
        char old_screen[MAX_Y][MAX_X];
        char screen[MAX_Y][MAX_X];
} GameState;

static struct termios old_termios, new_termios;

void reset_terminal() {
        printf("\e[m");    // reset color changes
        printf("\e[?25h"); // show cursor
        printf("\e[%d;%dH\n", MAX_Y + 3, MAX_X);
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

void read_input(GameState *state) {
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

        state->key = final_key;
}

void extra1() {

        struct stat info;
        fstat(STDIN_FILENO, &info);
        printf("Tam: %ld\n", (long)info.st_size);
        printf("Tam: %ld\n", (long)info.st_blksize);
}

// void print_key(int key) {
//         if (key == 1)
//                 printf("Up\n");
//         if (key == 2)
//                 printf("Down\n");
//         if (key == 3)
//                 printf("Right\n");
//         if (key == 4)
//                 printf("Left\n");
// }

// En casi 2 y 3 hay que tener ewn cuenta el carácter de nueva linea. (no es
// simétrico). Las posiciones 0 es la de borde.
void handle_player(GameState *state) {
        switch (state->key) {
        case 1:
                if (state->pos_y > 1) {
                        state->screen[state->pos_y][state->pos_x] = ' ';
                        state->screen[state->pos_y - 1][state->pos_x] = '@';
                        --state->pos_y;
                }
                //*pos_y = MAX(1, *pos_y - 1);
                break;
        case 2:
                if (state->pos_y < MAX_Y - 2) {
                        state->screen[state->pos_y][state->pos_x] = ' ';
                        state->screen[state->pos_y + 1][state->pos_x] = '@';
                        ++state->pos_y;
                }
                //*pos_y = MIN(MAX_Y - 2, *pos_y + 1);
                break;
        case 3:
                if (state->pos_x < MAX_X - 3) {
                        state->screen[state->pos_y][state->pos_x] = ' ';
                        state->screen[state->pos_y][state->pos_x + 1] = '@';
                        ++state->pos_x;
                }
                //*pos_x = MIN(MAX_X - 3, *pos_x + 1);
                break;
        case 4:
                if (state->pos_x > 1) {
                        state->screen[state->pos_y][state->pos_x] = ' ';
                        state->screen[state->pos_y][state->pos_x - 1] = '@';
                        --state->pos_x;
                }
                //*pos_x = MAX(1, *pos_x - 1);
                break;
        }
}

void update(GameState *state) {
        memcpy(state->screen, state->old_screen, sizeof(state->screen));
        handle_player(state);
}

void render(GameState *state) {
        for (int j = 0; j < MAX_Y; j++) {
                for (int i = 0; i < MAX_X; i++) {
                        if (state->old_screen[j][i] != state->screen[j][i]) {
                                // Ubicar el cursor
                                printf("\e[%d;%dH", j + 1, i + 1);
                                printf("%c", state->screen[j][i]);
                        }
                }
        }
        fflush(stdout);
}

void find_player_position(GameState *state) {
        for (int j = 0; j < MAX_Y; j++) {
                for (int i = 0; i < MAX_X; i++) {
                        if (state->screen[j][i] == '@') {
                                state->pos_x = i;
                                state->pos_y = j;
                                return;
                        }
                }
        }
}

void load_level(GameState *state) {
        FILE *f = fopen("./levels/level_1.txt", "r");
        if (!f) {
                fprintf(stderr, "Failed to open level_1.txt");
                exit(EXIT_FAILURE);
        }
        if (fread(state->screen, 1, MAX_X * MAX_Y, f) != MAX_X * MAX_Y) {
                fprintf(stderr, "Failed to read level_1.txt");
                fclose(f);
                exit(EXIT_FAILURE);
        }
        render(state); // To display the level
        find_player_position(state);
        memcpy(state->old_screen, state->screen, sizeof(state->screen));
        fclose(f);
}

// Lower us faster
#define SPEED 0.1

int main() {

        // extra1();
        configure_terminal();

        signal(SIGINT, signal_handler);

        struct timespec req = {};
        struct timespec rem = {};

        GameState state = {.pos_x = 5, .pos_y = 5};

        printf("\e[2J");

        load_level(&state);

        clock_t start, end;
        while (!exit_loop) {

                start = clock();

                read_input(&state);
                update(&state);
                render(&state);

                memcpy(state.old_screen, state.screen, sizeof(state.screen));

                end = clock();

                double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                if (time_taken > SPEED)
                        continue;

                req.tv_sec = 0;
                req.tv_nsec = (SPEED - time_taken) * 1000000000; // 0.1 seconds
                nanosleep(&req, &rem);
        }

        return 0;
}