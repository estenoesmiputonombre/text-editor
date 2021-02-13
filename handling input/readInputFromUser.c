#include <unistd.h>

// typedef long ssize_t;
// typedef unsigned long size_t;

// We are using the read method to read input from the user.
// In this program, we are reading byte by byte because of the third parameter.
// We are storing the value in the variable char c and reading from standard input (file number 1)
// The method read returns the number of bytes that the method reads.

// We can finish this program with Ctrl+D or Ctrl+C

int main() {
    char c;
    //ssize_t read(int, void *, size_t)
    while (read(STDIN_FILENO, &c, 1) == 1);
    return 0;
}