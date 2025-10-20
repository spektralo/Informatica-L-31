#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10

int main(){
    int arrA[size], arrB[size];
    int *pA = arrA, *pB = arrB;
    

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        *(pA+i) = rand()%(100-10+1)+10;
        *(pB+i) = rand()%(10-50+1)+50;
    }
    
    printf("elements before swapping:");
    for (int i = 0; i < size; i++)
    {
        printf("\nA[%d], value:%d",i,*(pA+i));
        printf("\t\tB[%d], value:%d",i,*(pB+i));
    }
    
    int *pA_end = (arrA + (size-1)), *pB_end = (arrB + (size-1));

    while(pA <= pA_end && pB <= pB_end) //SISTEMARE IL LOOP
    {
        *pA^=*arrB;
        *pB^=*arrA;
        *pA^=*arrB;
        
        pA++; pB++;
    }
   

    printf("\n\n");

    printf("elements after swapping:");
    for (int i = 0; i < size; i++)
    {
        printf("\nA[%d], value:%d",i,*(pA+i));
        printf("\t\tB[%d], value:%d",i,*(pB+i));
    }

}