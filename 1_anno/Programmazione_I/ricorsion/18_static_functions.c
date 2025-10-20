#include <stdio.h>

// gcc -Wall 18_static_functions.c 18_bar.c


/* eventualmente, per eliminare il warning del compilatore.
* In ogni caso e' buona norma codificare i prototipi delle funzioni 
* in file header
*/ 
// void bar(); 

/* foo() visibile globalmente nel programma */ 
void foo(){
    printf("\n foo()"); 
}

static void static_foo(){
    printf("\n static_foo()"); 
}

int main(){
    foo();
    static_foo(); 
    bar(); // invoca foo(). 
}    
