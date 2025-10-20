#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
  Ricerca lineare completa in uno array 
*/


int main()
{ 
   int A [100]; 
   int i = 0;      // indice dell'array
   int numero;     // contieneil valore da ricercare

   printf("\n Inserisci il numero da ricercare (1..10) : ");
    scanf("%d", &numero);

   srand(time(0));
   while (i<100) 
      {
        A[i] = rand()%10 + 1;
        i++;     
      }
         
   i = 0;
   unsigned short trovato = 0;
   while (i<100 && !trovato) 
      {
        if (A[i] == numero) 
	    trovato = 1;
        i++; 
      }

    if(trovato)
	printf("\n Trovato nella posizione %d", i-1);

    return 0;
} // End main()
