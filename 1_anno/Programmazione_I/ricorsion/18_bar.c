// gcc -Wall 18_static_functions.c 18_bar.c

#include <stdio.h>

void bar(){
    printf("\n bar()"); 
    foo(); 
    //static_foo(); // errore del linker!! 
}
