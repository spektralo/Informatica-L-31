#include<stdio.h>
#include<stdlib.h>
#define size 5

int main(){
    int arr[size], *beginP = arr, *endP = (arr + (size-1));

    for(int i = 0; i < size; i++)
    {
        *(beginP+i) = rand()%(100-10+1)+10;
    }

    printf("elements before swapping:");
    for (int i = 0; i < size; i++)
    {
        printf("\nA[%d], value:%d",i,*(beginP+i));
    }

    beginP = arr;
    while (beginP < endP)
    {
        *beginP ^= *endP;
        *endP ^= *beginP;
        *beginP ^= *endP;

        beginP++; endP++;
    }
    
    printf("elements after swapping:");
    for (int i = 0; i < size; i++)
    {
        printf("\nA[%d], value:%d",i,*(beginP+i));
    }
    
    
}