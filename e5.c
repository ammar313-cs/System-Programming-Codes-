// Write a program that accepts a filename as an argument. 
// It then prints the size of that file using lstat()

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    struct stat file_stat;

    if (lstat(filename, &file_stat) < 0) {
        printf("Failed to stat file %s\n", filename);
        return 1;
    }

    printf("Size of %s: %lld bytes\n", filename, file_stat.st_size);

    return 0;
}
