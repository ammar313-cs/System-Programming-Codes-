#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>

int main(){


    int dta_p;
    int file_pipes[2]
    char dt = '123';

    int arg;


    if(pipe(file_pipes) == 0){
        pid_t pid = fork();

        if(pid == 0){
            //child
            dup(file_pipes[0]);
            close(file_pipes[0]);
            close(file_pipes[1]);
            sprintf(arg, "%d", file_pipes[0])
            execlp('pip4','pip4',arg,(char*)0)

        }

        else{
            dup2(file_pipes[1],4);
            close(file_pipes[0]);
            int b_r =  write(file_pipes[1],dt,strlen(dt))
            close(file_pipes[1]);
        }
    }

}

main(char *argv[], int argc){

    int fd;
    char buffer[BUFSIZ +1];

    memset(buffer,"0/",BUFSIZ)

    

sscanf(argv[0],"%d", fd);
  
int r =  read(fd,buffer,1024)
}