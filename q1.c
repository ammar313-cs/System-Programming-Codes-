#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char *argv[]){
   
   
   
       int n = strlen(argv[1]);
       if (argv[1][n-2] == '.' && argv[1][n-1] == 'c')
        {
            printf("\n this is a C file\n", argv[1]);
            return 0;
        }
     
   
   
   
   printf("\n The file  %s is not a C source file.\n", argv[1]);

    return 0;
}






