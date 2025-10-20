#include<stdio.h>
#include<stdlib.h>
#define dim 10
void fillArr(int*,int);
void printArr(int*,int);
void swapArr(int*,int*,int*);


int main(){
    int sourceArr[dim], destArr[dim], size;
    int *sourceP = sourceArr, *destP = destArr;
    
    
    
    printf("arr size:");
    scanf("%d",&size);
    fillArr(sourceArr,size);
    printArr(sourceArr,size);


    int *endP = &sourceP[size-1];
    printf("\ndestArr before swap:");
    printArr(destArr,size);
    
    swapArr(sourceP,endP,destP);
     printf("\ndestArr after swap:");
    printArr(destArr,size);

}

    
void swapArr(int *sourceP,int *endP,int *destP){
    while (sourceP <= endP)
    {
        *destP = *sourceP;
        sourceP++; destP++;
    }
    
    
}

void fillArr(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        *(array+i) = rand()%(100-10+1)+10;
    }
}

void printArr(int*array,int size){
    for (int i = 0; i < size; i++)
    {
        printf("\narr[%d], value:%d",i,*(array+i));
    }
    printf("\n");
}