#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"


int main(){
    int running = 1;

    struct shared_use_t *shared_stuff;

    void *shared_memory = (void*)0;

    int shmid;

    char buffer[BUFSIZ];

    shmid = shmget((key_t)1234,
                  sizeof(struct shared_use_t),
                  IPC_CREAT | 0666);

    if(shmid == -1){
        exit(EXIT_FAILURE);
    }  

    shared_memory = shmat(shmid,(void*)0,0);

    if(shared_memory == -1){
        exit(EXIT_FAILURE);
    }

    printf("memory attached %X", shared_memory);

    shared_stuff = (struct shared_use_st*) shared_memory;

    while (running)
    {
        while (shared_stuff->written == 1)
        {
           sleep(1);
           printf("waiting for client");
        }
        printf('Enter text:');
        fgets(buffer,BUFSIZ,stdin);

        strncpy(shared_stuff->some_text,buffer ,sizeof(buffer));

        shared_struff->written = 1;

        if(strncmp(buffer,"end",3) == 0){
            running = 0;
        }
        
        
    }
    if(shmdt(shared_memory) == -1){
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
     
    
    



}