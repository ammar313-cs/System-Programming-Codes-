#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <original_filename> <child_pid> <pipe_fd>\n", argv[0]);
        exit(1);
    }

    // Extract command line arguments
    char *original_filename = argv[1];
    int child_pid = atoi(argv[2]);
    int pipe_fd = atoi(argv[3]);

    // Create filename for child process
    char child_filename[256];
    sprintf(child_filename, "%s-%d", original_filename, child_pid);

    // Open input file for reading
    printf("Child PID: %d, Filename: %s\n", child_pid, child_filename);
    printf("Child process is ready to read data from standard input...\n");

    int input_fd = open(child_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (input_fd == -1) {
        perror("Failed to create file for child process");
        exit(1);
    }

    // Read data from standard input and write to the child file
    char buffer[1024];
    ssize_t bytes_read, bytes_written;
    int total_chars_written = 0;

    while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(input_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Failed to write to child file");
            exit(1);
        }
        total_chars_written += bytes_written;
    }

    if (bytes_read == -1) {
        perror("Failed to read from standard input");
        exit(1);
    }

    printf("Child PID: %d, Characters Written: %d\n", child_pid, total_chars_written);

    // Close input file and send total_chars_written to parent process
    close(input_fd);
    write(pipe_fd, &total_chars_written, sizeof(int));
    close(pipe_fd);

    return 0;
}