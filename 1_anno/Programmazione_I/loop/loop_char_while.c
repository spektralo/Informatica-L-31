#include<stdio.h>
int main(){
    int carattere = 122;
    while (carattere>=98)
    {
        carattere--;
        switch (carattere)
         {
         case 'a':
            printf("\nVocale non elencata");
            break;

             case 'e':
            printf("\nVocale non elencata");
            break;

             case 'i':
            printf("\nVocale non elencata");
            break;

             case 'o':
            printf("\nVocale non elencata");
            break;
         
          case 'u':
            printf("\nVocale non elencata");
            break;
            
            default:
            printf("\nAlfabeto inverso:%c",(char)carattere);
         }
    }
    
}