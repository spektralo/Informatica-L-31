/****************** Una stampante è caratterizzata dal livello di inchiostro (int) delle singole 
cartucce C M Y K; le cartucce non possono essere ricaricate ma sostituite (con valore come parametro);
la stampante permette di stampare singoli fogli o più copie di uno stesso foglio
(passando i livelli di inchiostro richiesti per la stampa di quel foglio);
si può sempre verificare il livello di inchiostro di una cartuccia.
Ragionare su quali attributi e metodi sono presenti e sul codice dei metodi 
(si ragioni su come gestire le stampe soprattutto nel caso non ci sia inchiostro sufficiente).
Creare la classe e un main.

*******************************************************************************/
#include <iostream>
using namespace std;

class Stampante
{
    int c;
    int m;
    int y;
    int k;
public:
    Stampante(int cc,int mm,int yy,int kk)
    {
        c=cc;
        m=mm;
        y=yy;
        k=kk;
    }
    // il metodo prova a stampare ncopie copie della pagina
    // con richieste di inchiostro cc,mm,yy,kk
    //restituisce il numero di copie effettivamente stampate
    int stampa(int cc,int mm,int yy,int kk,int ncopie=1)
    {
        int copie=0;
        while((cc<=c)&&(mm<=m)&&(yy<=y)&&(kk<=k)&&(copie<ncopie))
        {
            copie++;
            c=c-cc;
            m=m-mm;
            y=y-yy;
            k=k-kk;
        }
        return copie;
    }
    void cambiaCartuccia(char colore,int inchiostro)
    {
        switch(colore)
        {
            case ('c'):
                c=inchiostro;
                break;
            case ('m'):
                m=inchiostro;
                break;
            case ('y'):
                y=inchiostro;
                break;
            case ('k'):
                k=inchiostro;
                break;
            default:;
        }
    }
    
    void print()
    {
        cout<<"c: "<<c;
        cout<<" m: "<<m;
        cout<<" y: "<<y;
        cout<<" k: "<<k<<endl;
    }

};
    
int main()
{
    Stampante s(10,5,5,6);
    s.print();
    cout<< "Stampate " << s.stampa(2,1,1,2)  <<" copie"<<endl;
    s.print();
    cout<< "Stampate " << s.stampa(3,2,1,1,3) <<" copie"<<endl;
    s.print();
    s.cambiaCartuccia('m',20);
    s.print();
}


