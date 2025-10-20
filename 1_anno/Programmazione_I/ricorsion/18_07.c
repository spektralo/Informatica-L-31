#include <stdio.h>
#include <stdlib.h>

/* 
   Questo programma implementa una funzione
   ricorsiva per il calcolo del fattoriale.
*/


long  fattoriale  ( int  n )
    {
      printf("\n fatt(%d)", n);
       
     if  ( n == 0 )     return  1; // caso base
      
      return   n * fattoriale ( n-1 ); // passo ricorsivo
   }


int main(int argc, char *argv[])
{
  if(argc<2){
    printf("\n No argument! "); 
    return -1;
  }
     
   printf("\n risultato: %lu", fattoriale(atoi(argv[1])));
    return 0; 
} // End main()
