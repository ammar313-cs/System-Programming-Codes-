#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char ** argv)
{
    struct stat buf;

    int status = lstat(argv[1], &buf);

    printf("The Size of the %s file: %ld bytes\n", argv[1], buf.st_size);

    return 0;
}
