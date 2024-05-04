#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t child_pids[3]; // Array to store child process PIDs
    
    for (i = 0; i < 3; i++) {
        pid_t child_pid = fork();
        
        if (child_pid == 0) {
            // Child process
            printf("Child %d created with PID: %d\n", i+1, getpid());
            execl("./part_a", "part_a", NULL); // Replace with the correct path to the compiled Part A program
            // execl will replace the child process with the Part A program, so the code below will only execute if execl fails
            printf("Failed to exec Part A program\n");
            exit(1);
        } else if (child_pid < 0) {
            // Fork failed
            printf("Fork failed\n");
            exit(1);
        } else {
            // Parent process
            child_pids[i] = child_pid; // Store child PID in array
        }
    }
    
    // Wait for all child processes to complete
    for (i = 0; i < 3; i++) {
        int status;
        waitpid(child_pids[i], &status, 0); // Wait for specific child process to complete
        if (WIFEXITED(status)) {
            // Child process exited normally
            printf("Child %d with PID %d completed\n", i+1, child_pids[i]);
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            printf("Child %d with PID %d terminated by a signal\n", i+1, child_pids[i]);
        }
    }
    
    return 0;
}