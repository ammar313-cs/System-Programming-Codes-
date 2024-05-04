#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    int n;

    while ((n = read(0, buffer, sizeof(buffer))) > 0) {
        if (write(1, buffer, n) != n) {
            perror("write");
            exit(1);
        }
    }

    if (n < 0) {
        perror("read");
        exit(1);
    }

    return 0;
}
