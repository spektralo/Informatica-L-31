#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_SAMPLES 10

int main(){

  const time_t now = time(0); 

  srand(now); 

  for(int i=0; i<N_SAMPLES; i++)
    printf("%d", rand()%100);
       
}
