// Write a program that accepts a directory name as an argument. 
// It then displays all the contents 
// of the directory using opendir() & readdir().

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *dirname = argv[1];
    DIR *dir = opendir(dirname);

    if (!dir) {
        printf("Failed to open directory %s\n", dirname);
        return 1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
