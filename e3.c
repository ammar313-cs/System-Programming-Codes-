// Write a program that differentiates a C code file from other files, where the filename is passed
// to the program as a command line argument. You should use filename extensions as a means of
// differentiation; a C source file would end with a '.c' e.g hello.c. The program should just print a
// message saying whether, or not the filename-argument is a C source file.


#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *extension = strrchr(filename, '.'); // find last occurrence of '.'

    if (extension != NULL && strcmp(extension, ".c") == 0) {
        printf("%s is a C source file\n", filename);
    } else {
        printf("%s is not a C source file\n", filename);
    }

    return 0;
}
