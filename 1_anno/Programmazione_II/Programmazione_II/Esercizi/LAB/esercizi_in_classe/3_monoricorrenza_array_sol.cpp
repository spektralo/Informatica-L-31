/******************************************************************************
Leggere un array di 10 interi e stampare solo i numeri che appaiono nell'array una volta soltanto.
Ad esempio se l'array contiene 1, 2, 3, 1, 2, 4 il programma stamperà 3, 4 .

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a[10];

    //memorizzo l'array
    cout<<"inserisci 10 numeri interi"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    
    //per ogni numero dell'array 
    for(int i=0;i<10;i++)
    {
        // voglio contare quante volte appare a[i]
        int volte=0;
        
        //controllo quante volte compare a[i]
        for(int j=0;j<10;j++)
        {
            if(a[j]==a[i])
            {volte++;}
        }
        if(volte==1)
        {cout<<a[i]<<" ";}
    }
    return 0;
}




