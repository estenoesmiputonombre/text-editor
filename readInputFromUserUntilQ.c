#include <unistd.h>

// In this program, we are reading from the standard input of the user until the user press the key q or Ctrl+D or Ctrl+C.

int main() {
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}