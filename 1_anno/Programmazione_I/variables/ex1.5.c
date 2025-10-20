#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(){
    float x = 0, y = 0, tan = 0;
    printf("\nInserisci un valore per x:");
    scanf("%f",&x);
    printf("Inserisci un valore per y:");
    scanf("%f",&y);

    tan= pow(sin(x), 2) + pow(cos(y), 2);
    printf("Il valore della tangente e': %3.2f \n",tan);

    float cat1 = 0, cat2 = 0, ipotenusa = 0;
    printf("\nInserisci la misura del primo cateto(cm):");
    scanf("%f",&cat1);
    printf("Inserisci la misura del secondo cateto(cm):");
    scanf("%f",&cat2);
    ipotenusa = sqrt(pow(cat1, 2) + pow(cat2, 2));
    printf("L'ipotenusa misura: %3.2f \n",ipotenusa);

    float raggio = 0, circonferenza = 0, area= 0;
    printf("\nInserisci il valore del raggio del cerchio:");
    scanf("%f",&raggio);
    circonferenza = 2*(PI * raggio);
    area = PI * pow(raggio, 2);
    printf("Il valore della circonferenza e': %3.2f \n",circonferenza);
    printf("Il valore dell'area e': %3.2f \n",area);

    int a = ((double)(2+3)/2);
    int b = ((double)(7/4)+8.8);
    double somma = (double)a*b;
    printf("\nLa somma tra a e b e': %3.3lf",somma);

    /* DIVISIONE PER ZERO = WARNING !!!!
    double ics = 0, result = 0;
    printf("\nserisci un valore decimale per ics:");
    scanf("%lf",&ics);
    result = x/0 - x/0;
    printf("Il risultato della espressione e': %lf",result);
    */



}