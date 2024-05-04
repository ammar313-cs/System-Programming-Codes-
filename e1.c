// Write a program that creates a file with read permissions for all,
// opens it in WRITE mode and
// then writes a line of text into it. 
// The name of the file to be created is passed on the command line

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Create the file with read permissions for all
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to create file\n");
        return 1;
    }
    chmod(filename, 0644); // set read permissions for all

    // Write a line of text to the file
    fprintf(file, "Hello, world!\n");

    // Close the file
    fclose(file);

    return 0;
}
