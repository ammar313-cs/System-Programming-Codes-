#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<sys/wait.h>


int main(){

    pid_t pid;
    int n;
    char *message;


    switch(pid) {
     case -1:
               perror("fork failed");
               exit(1);
     case 0:
          message = "This is the child";
          n = 3;
          break;
     default:
          message = "This is the parent";
          n = 5;
          break;
}

for (; n > 0; n--)
{
    fprintf(stderr,"%s\n",message);
    sleep(1);
}
exit(0);

}