#include <stdio.h>

/*  Commentando le due dichiarazioni, il compilatore produrra' un warning per funzione, 
* ma assumera' che le funzioni siano estern. 
* Se il linker ricevera' i moduli oggetto che contengono le due funzioni, 
* non dara' alcun errore. 
* 
* Cio' non vale per le variabili (globali) dichiarate in un modulo A
* ed usate in un altro modulo B. Tali variabili vanno necessariamente 
* dichiarate ``extern'' nel modulo B. 
*  
*/  
extern int foo(int); 
extern int bar(int);

int main(){

    printf("\n foo(5): %d", foo(5)); 

    printf("\n bar(5): %d", bar(3)); 


}
