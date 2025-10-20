#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
   Questo programma esegue una ricerca lineare 
   con sentinella in un array che si interrompe alla prima 
   occorrenza trovata
*/



int main()
{ 
   int  A[100+1]; // Locazione per la sentinella
   int  i = 0;    // indice dell'array
   int  numero;   // contiene il valore da ricercare

  printf("\n Inserisci il numero da ricercare (1..100) : ");
  scanf("%d", &numero); 

   srand(time(0));
   while (i<100) 
      {
        A[i] = rand()%100 + 1;
        i++;     
      }
      
   A[i] = numero;   // la sentinella !
         
   i = 0;
   while (A[i] != numero)    i++; // non vi e' il controllo i>=100
       
   // while (A[i++] != numero);    Funziona ? 
                   
   if ( i != 100 )  
        printf("\n Trovato nella posizione %d", i);
   else
        printf("\n Non esiste !");
        
    return 0; 
} // End main()
