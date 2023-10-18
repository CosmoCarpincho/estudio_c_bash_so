// game_stage_repaso_1.c
#include <stdio.h>
#include <termios.h>

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
