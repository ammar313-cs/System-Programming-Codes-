#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<sys/wait.h>

int main() {


//int return_value;
//return_value = execl("/bin/ps", "ps", "ax", 0);

/*if ( return_value == 0 ) // wont run if exec executes
     printf("execl() was successful \n"); */

     execl("/bin/ps", "ps", "ax", 0);
     perror("execl() failed\n");
}