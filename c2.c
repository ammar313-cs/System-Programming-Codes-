#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//size_t read(int fildes, void *buf, size_t nbytes); standard for write command 

int main(){
     
     char buffer[128];
     int nread;
     int byteswritten;

     nread = read(0,buffer,128);

     if(nread == -1){
        write(2,"A read error has occured\n",26);
        exit(1);
     }
     byteswritten = write(1,buffer,nread);

     if(byteswritten != nread )
     write(2,"A write error has occured \n",27);
exit(0);


}