#include<stdio.h>
#include<stdlib.h>
#define lanci 5
int main(){
    printf("Coppie:");
    for (int i = 0; i < lanci; i++)
    {
        unsigned int lancio_a = rand()%(1-6+1)+1;
        unsigned int lancio_b = rand()%(1-6+1)+1;
        printf("\n%d %d",lancio_a,lancio_b);
    }
    
}