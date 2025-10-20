#include<stdio.h>
int main(){
    char carattere;
    printf("Inserisci un carattere:");
    scanf("%c", &carattere);

    switch (carattere)
    {
    case 'a':
        printf("char_code: %d",carattere);
        break;

         case 'e':
        printf("char_code: %d",carattere);
        break;

         case 'i':
        printf("char_code: %d",carattere);
        break;

         case 'o':
        printf("char_code: %d",carattere);
        break;

         case 'u':
        printf("char_code: %d",carattere);
        break;

        case 'A':
        fprintf(stdout,"char_code: %c",carattere);
        break;

         case 'E':
        fprintf(stdout,"char_code: %c",carattere);
        break;

         case 'I':
        fprintf(stdout,"char_code: %c",carattere);
        break;

         case 'O':
        fprintf(stdout,"char_code: %c",carattere);
        break;

         case 'U':
        fprintf(stdout,"char_code: %c",carattere);
        break;

        case '1':
        printf("value: %d", (carattere*10));
        break;

         case '2':
        printf("value: %d", (carattere*10));
        break;

         case '3':
        printf("value: %d", (carattere*10));
        break;
     
    default:
        printf("Carattere non valido");
        break;
    }
}