#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char ** argv)
{
    DIR *dir1 = opendir(argv[1]);

    struct dirent *e1; 
   
    while((e1 = readdir(dir1)) != NULL){
    	printf("%s\n", e1->d_name);
    }

    
    closedir(dir1);

    return 0;
}
