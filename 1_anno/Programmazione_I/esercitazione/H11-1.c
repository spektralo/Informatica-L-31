#include<stdio.h>
#include<float.h>
int main(){
    float x, y;
    printf("\nInserisci un valore < 1 per X:");
    scanf("%f",&x);
    printf("\nInserisci un valore > 0 per Y:");
    scanf("%f",&y);

    while (y > 0 && x < 1)
    {
        float times = y * x;
        float result = result * times;
        printf("\nIl risultato della moltiplicazione e': %2.2f",result);

        if (result > FLT_MAX)
        {
            printf("\nOverflow!");
            break;
        }
        
    }
    

}