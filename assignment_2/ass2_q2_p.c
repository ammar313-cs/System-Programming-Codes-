#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fprintf(stderr, "A\n");
    fork();
    fprintf(stderr, "B\n");

    return 0;
}