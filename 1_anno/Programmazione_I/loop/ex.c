#include<stdio.h>
int main(){
    int sum;
    
    for (int i = 0; i <= 99; i+=2)
    {
        
        if (i % 3 == 0)
        {
            sum = sum - i;
        }
       else
        sum = sum + i;
    }
    printf("\nSomma:%d",sum);
}