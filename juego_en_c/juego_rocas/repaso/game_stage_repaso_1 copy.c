// game_stage_repaso_1.c
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios old_termios, new_termios;

void reset_terminal() {
        printf("\033[m");    // reset color changes
        printf("\033[?25h"); // show cursor
        printf("at reset terminal\n");
        fflush(stdout);
        tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

void configure_terminal() {
        tcgetattr(STDIN_FILENO, &old_termios);
        new_termios = old_termios;
}
void configurarTermios() {
        struct termios n_term;
        struct termios *term;
        struct termios *nueva_conf_term;

        tcgetattr(0, term);

        //       n_term = *term;
        //        nueva_conf_term = &n_term;

        printf("c_cc:%u\nc_cflah:%u\n", term->c_cc, term->c_cflag);
}

int main() {

        printf("Hola mundo\n");
        configurarTermios();

        return 0;
}
