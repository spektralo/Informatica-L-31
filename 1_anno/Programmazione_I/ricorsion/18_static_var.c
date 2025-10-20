#include <stdio.h>

void foo(){
    static unsigned int foo_calls=0;
    foo_calls++;
    printf("\n foo_calls: %d", foo_calls);
}

int main(){

    for(int i=0; i<10; i++)
	foo(); 
}
