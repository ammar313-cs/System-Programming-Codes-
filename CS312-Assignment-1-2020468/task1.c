#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char c;
    size_t nbytes = 8192; // buffer size 
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input-filename> <output-filename>\n", argv[0]);
        return 1;
    }
    
    
    int in, out;
    in = open(input_filename, O_RDONLY);
    if (in == -1) {
        fprintf(stderr, "Error opening input file 1: %s\n", input_filename);
        return 3;
    }

    out = open(output_filename, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (out == -1) {
        fprintf(stderr, "Error opening input file 2: %s\n", output_filename);
        close(in);
        return 4;
    }

    while(read(in,&c,nbytes) == 1){
        write(out,&c,nbytes);
    }
    
exit(0); 
}