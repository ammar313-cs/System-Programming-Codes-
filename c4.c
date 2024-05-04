#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<sys/wait.h>



int main(){

pid_t pid;
char *message;
int n;
int exit_code;

pid = fork();

switch (pid)
{
case -1:
perror("fork failed");
exit(1);
case 0:
message ="child process";
n = 5;
exit_code = 37;
break;
default:
message ="parent process";
n = 3;
exit_code = 57;
break;


  
}
for (; n > 0; n--)
{
    fprintf(stderr,"%s\n",message);
    sleep(1);
}
exit(0);

if(pid !=0){

    pid_t childpid;
    int stat_val;

    childpid = wait(&stat_val);
    printf("Child pid: %d\n", childpid);

    if(WIFEXITED(stat_val)){
        printf("child exited with exit code %d\n",WEXITSTATUS(stat_val));
    }
    else{
        printf("Child terminated abnormally\n");
    }
}

exit(exit_code);

}