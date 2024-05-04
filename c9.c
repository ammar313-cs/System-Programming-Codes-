#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>



int main() {

    
    char buffer[BUFSIZ + 1];
    


    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char argument[10];
    pid_t fork_result;
    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
}
        if (fork_result == 0) { /* child */
            sprintf(argument, "%d", file_pipes[0]);
            execl("pip4", "pip4", argument, (char *)0);
            exit(EXIT_FAILURE);
        }
        else {                  /* parent */
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("%d - wrote %d bytes\n", getpid(), data_processed);
        }
}
    exit(EXIT_SUCCESS);
}