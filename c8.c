#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>

int main() {
int data_processed;
int file_pipes[2];
pid_t fork_result;

const char some_data[] = "Lorem ipsum dolor sit amet, consectetuer";

if (pipe(file_pipes) == 0) {
    fork_result = fork();
}
if (fork_result == (pid_t)-1) {
        fprintf(stderr, "Fork failure");
        exit(EXIT_FAILURE);
}
    if (fork_result == (pid_t)0) {
        close(0);
        dup(file_pipes[0]);
        close(file_pipes[0]);
        close(file_pipes[1]);
        execlp("wc", "wc", "--words", (char *)0);
        exit(EXIT_FAILURE);
}
else {
        close(file_pipes[0]);
        data_processed = write(file_pipes[1], some_data, strlen(some_data));
        close(file_pipes[1]);
        printf("%d - wrote %d bytes\n", getpid(), data_processed);
} 
exit(EXIT_SUCCESS);
}