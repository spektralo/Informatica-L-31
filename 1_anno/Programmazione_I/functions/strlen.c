#include<stdio.h>
#include<string.h>
#define N 10
 int stringLenght(char string[]){
    for (int i = 0; i < N; i++)
    {  
        scanf("%c",&string[i]);
    }
    int lenght = strlen(string);
    return lenght;
}

int main(){
    char string[N];
    printf("\nInserisci una stringa:");
    int res=stringLenght(string);
    printf("\nLa lunghezza della stringa e':%d",res);
}