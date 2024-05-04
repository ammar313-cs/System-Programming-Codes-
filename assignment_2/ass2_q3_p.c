#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to handle child process
void childProcess(int read_pipe, int write_pipe, int num_chars) {
    char buffer[num_chars];
    int chars_written = 0;
    int total_chars_written = 0;
    
    // Read data from parent through read_pipe
    while ((chars_written = read(read_pipe, buffer, num_chars)) > 0) {
        // Write data to output file
        fwrite(buffer, sizeof(char), chars_written, stdout);
        total_chars_written += chars_written;
    }
    
    // Write total_chars_written to write_pipe
    write(write_pipe, &total_chars_written, sizeof(int));
    
    // Close pipes
    close(read_pipe);
    close(write_pipe);
    
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <num_children> <num_chars>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    int num_children = atoi(argv[2]);
    int num_chars = atoi(argv[3]);

    // Open input file
    FILE* file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Failed to open input file: %s\n", input_file);
        return 1;
    }

    // Create pipes
    int pipes[num_children][2];
    for (int i = 0; i < num_children; i++) {
        if (pipe(pipes[i]) < 0) {
            printf("Failed to create pipe for child %d\n", i+1);
            return 1;
        }
    }

    // Fork and spawn child processes
    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            close(pipes[i][1]); // Close write_pipe in child process
            childProcess(pipes[i][0], pipes[i][1], num_chars);
        } else if (pid > 0) {
            // Parent process
            continue; // Continue to spawn next child
        } else {
            printf("Failed to fork child process %d\n", i+1);
            return 1;
        }
    }

    // Parent process
    char buffer[num_chars];
    int chars_read = 0;
    int total_chars_written = 0;

    // Read data from input file and send to children through pipes
    while ((chars_read = fread(buffer, sizeof(char), num_chars, file)) > 0) {
        for (int i = 0; i < num_children; i++) {
            write(pipes[i][1], buffer, chars_read); // Send data to child through write_pipe
        }
    }

    fclose(file);

    // Wait for child processes to finish and get total_chars_written from each child
    for (int i = 0; i < num_children; i++) {
        int child_status;
        pid_t child_pid = wait(&child_status);
        if (WIFEXITED(child_status)) {
            read(pipes[i][0], &total_chars_written, sizeof(int));
            printf("Child PID: %d, Characters Written: %d\n", (int)child_pid, total_chars_written);
        } else {
            printf("Child PID: %d exited abnormally\n", (int)child_pid);
}
}

// Close pipes
for (int i = 0; i < num_children; i++) {
    close(pipes[i][0]);
    close(pipes[i][1]);
}

return 0;

}