#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<sys/wait.h>

int main() {
  printf("Running ps with execlp\n");
  //execlp("ps", "ps", "ax", 0); //file name 
  execl("/bin/ps", "ps", "ax", 0); //path name 
  printf("Done.\n"); //wont run if exec runs properly
  exit(0);
}