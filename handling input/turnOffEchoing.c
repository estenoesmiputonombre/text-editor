#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

struct termios orig_termios;

// The ECHO feature causes each key you type to be printed to the terminal,
// so you can see what you're typing.
// Same behaviour as the terminal ask us to write the password.

// The ICANON feature causes to turn off the canon mode. It will allow
// the reading byte a byte.

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    // It comes from stdlib and it calls the function when the program exists.
    atexit(disableRawMode);

    struct termios raw = orig_termios;

    // c_lflag stands for local flags.
    raw.c_lflag &= ~(ECHO | ICANON);
    // we use the bitwise-NOT operator on this value.

    // we have other flags like:
    // c_iflag which means input flag.
    // c_oflag which means ouptut flag.
    // c_cflag which means control flag.

    // TCSAFLUSH argument specifies when to apply the change.
    // It waits for all pending output to be written to the terminal
    // and also discards any input that hasn't been read.
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}