#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
   Questo programma esegue una ricerca lineare 
   in un array ordinato in senso crescente
   che si interrompe se :
      1) non esiste il valore ricercato,
      2) si trova il valore ricercato,
      3) si sta esaminando un elemento 
	maggiore del valore ricercato.
*/

int main()
{ 
   int  A[100]; 
   int  i = 1;    // indice dell'array
   int  numero;   // contiene il valore da ricercare
   unsigned short trovato   = 0;  // esito della 2)  
   unsigned short trovabile = 1;   // esito della 3)

   printf("\n Inserisci il numero da ricercare (1..10) : ");
    scanf("%d", &numero); 

   srand(time(0));  
   A[0] = 1;  
   while (i<100) 
      {
        A[i] = A[i-1] + (rand()%2 + 1);
        i++;     
      }
             
   i = 0;
   while ( (i<100) && (!trovato) && trovabile ) 
      {
        if (A[i] == numero)   trovato   = 1;
        if (A[i] > numero)    trovabile = 0;
        i++;
      }
                     
   if ( trovato )  
        printf("\n Trovato nella posizione %d", (i-1)); 
   else
        printf("\n Non esiste (%d)!", A[i-1]); 

    return 1;

} // End main()
