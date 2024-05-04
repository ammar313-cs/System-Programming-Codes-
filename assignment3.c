#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct arguments{
 int str_ind;
 int end_ind;

} args;

long int y;
pthread_mutex_t lock;

void *thread_cal_func(void *args1){

args *arg = args1 ;


for (int i= arg->str_ind ; i< arg->end_ind ;i++){
    pthread_mutex_lock(&lock);
    y = y+(((i-1)*(i-1))/5);
    pthread_mutex_unlock(&lock);
 }
 
  printf("The value of function y is: %ld \n", y);
}

int main(int argc, char **argv){

int n;
int m;
if(argc >=2){
n  = atoi(argv[1]);
m = atoi(argv[2]);
}

args arg[n];

for(int i = 0 ; i < n ; i++){
   arg[i].str_ind = (i*m)/n;
   arg[i].end_ind = ((i+1)*m)/n;
}

pthread_t tid[n];

for(int i = 0; i < n ; i++){
  pthread_create(&tid[i],NULL,thread_cal_func, &arg[i]);
}


for (int i=0 ; i<n ; i++ ){
   pthread_join(tid[i], NULL);
   
} 

}





