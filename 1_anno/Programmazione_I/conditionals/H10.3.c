#include<stdio.h>
#define N 5
int main(){
    float capitale = 0, interesse = 0, target = 0, anni = 0;
    printf("Inserisci capitale iniziale, interesse, target e numero anni:");
    scanf("%f %f %f %f", &capitale, &interesse, &target, &anni);

    while (target || anni <= 0)
    {
        printf("Parametro non calcolabile");
    }
    
    while (target && anni <= 0)
    {
        printf("Errore!");
        break;
    }
    
    while (capitale <= target && anni <= N)
    {
        capitale+=capitale*interesse;
    }
    

}