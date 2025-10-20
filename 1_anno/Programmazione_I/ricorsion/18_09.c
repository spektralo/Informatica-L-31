#include <stdio.h>

/* 
   Questo programma usa una funzione che 
   implementa la ricerca dicotomica ricorsiva.
*/


// Ricerca binaria ricorsiva
int ricerca(int array[], int key, int left, int right)
   {
      printf("\n ricerca(key=%d, left=%d, rigth=%d)",key, left, right); 

      if (left > right)   return -1;    // non trovato!
      
      int middle = ( left + right ) / 2;
            
      if ( key == array[middle] )  // trovato! 
            return middle; 
      
      if ( key < array[middle] )   
           return ricerca (array, key, left, middle-1);  
      else 
           return ricerca (array, key, middle+1, right);  
   }

   
int search (int array[], int length, int key) 
  {
    return  ricerca (array, key, 0, length-1);
  }
  

int main()
{ 
   int numeri[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    printf("\n \n search(numeri, 8, 0)=%d \n", search(numeri, 8, 0));
    printf("\n \n search(numeri, 8, 8)=%d \n", search(numeri, 8, 8));
 
} // End main()
