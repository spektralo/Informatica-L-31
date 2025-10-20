#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_SAMPLES 10


int main(){

  const int primo_seme = 11223344; 
  const int secondo_seme = 22334455; 

  srand(primo_seme); 

  printf("\n Primo campionamento, seme=%d", primo_seme);

  for(int i=0; i<N_SAMPLES; i++)
    printf("\n%d", rand()%100);


  srand(secondo_seme); 

  printf("\n Secondo campionamento, seme=%d", secondo_seme);

  for(int i=0; i<N_SAMPLES; i++)
    printf("\n%d", rand()%100);

  srand(secondo_seme); 

  printf("\n Terzo campionamento, seme=%d", secondo_seme);

  for(int i=0; i<N_SAMPLES; i++)
    printf("\n%d", rand()%100);       
}
