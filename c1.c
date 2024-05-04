#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//size_t write(int fildes, const void *buf, size_t nbytes); standard for write command 

int main(){
     size_t bytesWritten;

     bytesWritten = write(1,"Here is some data %d\n",18);

     if(bytesWritten != 18){
        write(2,"An error",46);

     }
exit(0);


}