#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    int status;
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error forking child process\n");
        exit(2);
    }
    else if (pid == 0) { // Child process
        
        execlp("cmp", "cmp", "-s", argv[1], argv[2], (char *) NULL);
       
        perror("Error executing child process");
        exit(2);
    }
    else {  // Parent process
       
        if (waitpid(pid, &status, 0) == -1) {
            fprintf(stderr, "Error waiting for child process\n");
            exit(2);
        }

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            if (exit_code == 0) {
                printf("Files %s and %s are the same\n", argv[1], argv[2]);
            }
            else if (exit_code == 1) {
                printf("Files %s and %s are different\n", argv[1], argv[2]);
            }
            else {
                fprintf(stderr, "Error opening files %s and %s\n", argv[1], argv[2]);
                exit(2);
            }
        }
        else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Child process terminated abnormally\n");
            exit(2);
        }
    }

    return 0;
}



