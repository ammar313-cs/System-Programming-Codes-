// Do something illegal in your program 
// (thus mischievously generating an error condition) and 
// try to print the corresponding errno and 
// error message (the latter one using perror()).

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistentfile.txt", "r");

    if (!file) {
        perror("Failed to open file");
        printf("errno: %d, %s\n", errno, strerror(errno));
        return 1;
    }

    fclose(file);
    return 0;
}
