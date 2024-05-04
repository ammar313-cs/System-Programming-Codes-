#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

   
    //mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    
    int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

   
    char *line = "Hello, world!\n";
    if (write(fd, line, strlen(line)) == -1) {
        perror("write");
        exit(1);
    }

    
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}
