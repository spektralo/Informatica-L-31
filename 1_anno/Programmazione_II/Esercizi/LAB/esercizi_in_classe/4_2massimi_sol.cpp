/******************************************************************************
Leggere un Array di interi di 10 posizioni e stampare 
il valore del massimo valore contenuto nell'array e 
del secondo valore più grande.
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    
    int a[10];
    for(int i=0;i<10;i++)
    {cin>>a[i];}
   
    int massimo=a[0];
    int massimo2=a[1];
    
    if(massimo2>massimo)
    {
        int temp=massimo;
        massimo=massimo2;
        massimo=temp;
    }
    
    for(int i=2;i<10;i++)
    {
        if(a[i]>massimo)
        {
            massimo2=massimo;
            massimo=a[i];
        }
        else
        {
            if(a[i]>massimo2)
            {
                massimo2=a[i];
            }
        }
    }
    
    cout<<"massimo "<<massimo<<endl;
    cout<<"secondo massimo "<<massimo2;
    
}


