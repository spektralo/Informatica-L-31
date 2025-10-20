#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define dim 10

void randFill(char *, int);
void printArr(char *, int);

int main(){
    int size_t;
    printf("\nChoose a size:");
    scanf("%d",&size_t); 

    char arr[dim], arrList[] = {'h','e','l','l','o','\0'};
    char arrStr[] = "niceTry"; 
    const char *arrRead = "example";
    
    printf("\narrRand:");
    randFill(arr,size_t);
    printArr(arr,size_t); 

    printf("\n");

    printf("\narrList:");
    printArr(arrList,strlen(arrList));
        printf("\n");

    printf("\narrStr:");
    printArr(arrStr,strlen(arrStr));
        printf("\n");


    printf("\narrRead:");
    printArr(arrRead,strlen(arrRead));

}

void randFill(char *arr, int size_t){
    for (int i = 0; i < size_t; i++)
    {
        *(arr+i) = rand()%(122-97+1)+97;
    }
}

