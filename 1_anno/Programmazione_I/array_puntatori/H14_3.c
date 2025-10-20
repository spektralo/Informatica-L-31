#include<stdio.h>
#include<stdlib.h>
#define N 200
int main(){
    double V[N];
    const double *ptrV=V;
    double *const ptrS=V;

    for (int i = 0; i < N; i++)
    { 
        V[i]=(50*rand()/RAND_MAX)+10;
        ptrV= V;
        
        if ((i%2)!=0 && (i%3)!=0)
        {
            *ptrS=(100*rand()/RAND_MAX)+100;
            printf("\nL'indice V[%2.f] e' stato sostituito con [%2.f]",*ptrV,V[i],*ptrS);
        }        
    }

    
}