#include<stdio.h>
#include<stdlib.h>
int main(){
    for (int carattere = 122; carattere >= 97; carattere--)
    {   
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