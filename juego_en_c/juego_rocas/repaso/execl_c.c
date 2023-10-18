#include <stdio.h>
#include <unistd.h>

int main() {
        execl("./script_execl.sh", "");
        return 0;
}