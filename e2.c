// Write a program that reads data from the shell (not from the command line...) and then echoes
//(prints) it back to the shell. End of input is indicated using the shell's EOF character (ctrl-d). You 
//must use file descriptors 0 & 1. The program should keep reading data until EOF is passed to it.



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = read(0, buffer, BUFFER_SIZE)) > 0) {
        if (write(1, buffer, read_size) != read_size) {
            fprintf(stderr, "Error: could not write to stdout\n");
            exit(1);
        }
    }

    if (read_size < 0) {
        fprintf(stderr, "Error: could not read from stdin\n");
        exit(1);
    }

    return 0;
}
