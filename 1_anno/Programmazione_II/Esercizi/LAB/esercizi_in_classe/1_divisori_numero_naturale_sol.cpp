/******************************************************************************

Creare una funzione che calcola quanti divisori ha un numero naturale. 
Creare poi un programma che ricevuto dall'utente un numero naturale n stampi il 
numero d che indica quanti divisori ha n e poi stampi quanti divisori 
ha il numero d.
*******************************************************************************/
#include <iostream>
using namespace std;

int nDivisori(int x)
{
    int nDiv=0;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0)
        {
            nDiv++;
        }
    }
    return nDiv;
}


int main()
{
    int n;
    cout<<"inserisci un numero "<<endl;
    cin>>n;
    int d=nDivisori(n);
    cout<<n<<" ha "<<nDivisori(n)<<" divisori"<<endl;
    
    cout<<d<<" ha "<<nDivisori(d)<<" divisori" <<endl;
    
}


