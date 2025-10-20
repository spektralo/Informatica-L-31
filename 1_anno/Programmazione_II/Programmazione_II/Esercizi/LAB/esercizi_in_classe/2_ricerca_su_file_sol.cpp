/******************************************************************************
Scrivere un programma che ricevuto in ingresso un file chiamato "testo.txt" 
e due caratteri digitati da tastiera crei un file "testo_sostituito.txt" con il testo di
"testo.txt" sostituendo il secondo carattere al primo per tutte le volte che compare il primo carattere.

Creare un file testo.txt con la seguente frase: "Per superare programmazione 2 è necessario studiare."

testo.txt="Per superare programmazione 2 è necessario studiare."
inserisco s ed X
testo_sostituito.txt="Per Xuperare programmazione 2 è neceXXario Xtudiare."

*******************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream fin("testo.txt");
    ofstream fout("testo_sostituito.txt");
    char a,c1,c2;
    cout<<"inserisci il carattere da sostituire ";
    cin>>c1;
    cout<<"inserisci il carattere con cui sostituirlo ";
    cin>>c2;
     //scorro tutti i caratteri del file
	while(fin.get(a))
    {
        if(a==c1)
        {
            fout<<c2;
        }
        else
        {
            fout<<a;
        }
    }
    fin.close();
    fout.close();
   
    
    
 
}


