#include <stdio.h>

int main()
{

  char a = 'x';

  //Quanto vale a? Intero con segno o senza segno?  
  printf("Il carattere a: %c\n", a);
  printf("a= %c\n\n", a);

  for(int start=(int) 'A'; start<(int) 'z'; start++)
    printf("%c ", (char) start);
  printf("\n\n");

  //quanto vale il carattere '~'? 
  printf("'~' == %d \n",(int) '~');
  
} // end main()
