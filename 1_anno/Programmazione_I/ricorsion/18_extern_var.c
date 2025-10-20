#include <stdio.h>

// vedi 18_zoo.c

// la rimozione questa dichiarazione dara' errore di compilazione 
extern int var; // meglio se in un header file

//la rimozione di questa linea di codice dara' solo un warning
extern void zoo(); // oppure void zoo(); meglio se in un header file

int main(){

    var = 10; // va dichiarata ``extern'' in questo file sorgente
    zoo(); 

    printf("\n main(), var=%d", var); 

}
