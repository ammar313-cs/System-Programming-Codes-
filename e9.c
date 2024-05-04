// Using execv(), list all the files of /bin directory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "/bin", NULL};
    execv("/bin/ls", args);
    return 0;
}
