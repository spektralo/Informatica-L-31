#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5

void fillstr(char *, int);
void printArr(char *, int);

 void strSort(char*,char*,char*);
int main(){
    char stringA[size], stringB[size], stringC[size];
    int size_t;

    printf("\nChoose a size (10-20):");
    scanf("%d",&size_t); 
    if (size_t < 10 || size_t > 20 )
    {
        printf("\nChosen value is not permitted!");
        exit(1);
    }
    
    
    fillstr(stringA,size_t);
    fillstr(stringB,size_t);
    fillstr(stringC,size_t);
    strSort(stringA,stringB,stringC);
    

}

void fillstr(char *arr, int size_t){
    for (int i = 0; i < size_t; i++)
    {
        *(arr+i) = rand()%(122-58+1)+58;
    }
}


 void printArr(char *arr, int size_t){
        for (int i = 0; i < size_t; i++)
        {
            printf("\narr[%d], value:%c",i,*(arr+i));
        }
        
    }

    void strSort(char *arrA, char *arrB, char *arrC){

        char *max, *med, *min;
        if (strncmp(arrA, arrB, strlen(arrB) && strncmp(arrA,arrC,strlen(arrC))))
        {
             if (strncmp(arrB,arrC, strlen(arrC))){
             {
                max = arrC, med = arrB, min = arrA;
             }
        }
             else if (strncmp(arrB,arrC, strlen(arrC)))
             {
              max = arrA, med = arrB, min = arrC;  
             }
             printf("max:%s\nmed:%s\nmin:%s",max,med,min);
        }
        
    }