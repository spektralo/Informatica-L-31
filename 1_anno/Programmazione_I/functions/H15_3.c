#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void strOp(char *);
int less(char*, char*);


int main(){
    char arrA[10], arrB[10];
    strOp(arrA);
    strOp(arrB);
    int res = less(arrA,arrB);
    printf("\nValue:%d",res);
}

void strOp(char *array){
    printf("\nInserisci una stringa:");
    scanf("%s",array);
    int len = strlen(array);
    printf("Lunghezza stringa:%d",len);

    }

int less(char *arrA, char *arrB){
    int res;
    int strA = strlen(arrA);
    int strB = strlen(arrB);
    if (strA<strB)
    {
        res = -1;
    }
    else if (strA > strB)
        {
            res = 1;
        }

        else res = 0;
        return res;
}




    
    
    