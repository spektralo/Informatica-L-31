#include<stdio.h>
#include<math.h>
int main(){
    int N = 1;
    printf("Inserisci un numero N:");
    scanf("%d",&N);

    for (int i = 1; i <= N; i++)
    {
        double power = pow(2,i);
        printf("\n%da potenza di 2:%lf",i,power);
    } 
}