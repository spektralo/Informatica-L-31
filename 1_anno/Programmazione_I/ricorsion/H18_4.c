#include<stdio.h>
int elab(int,int);

int main(){
    int base = 2, esp = 2;
    int elev = elab(base,esp);
    printf("\nelev:%d",&elev);
}

int elab(int base, int esp){
    if (esp == 0)
    {
        return 1;
    }
    else{
        return base * elab(base, esp - 1);
    }
    
}