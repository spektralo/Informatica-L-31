#include<iostream>
#include<time.h>
using namespace std;

class Prodotto{
    protected:
    int codice;
    string nome;
    float prezzo;
    string scadenza;

    public:
    Prodotto(int codice, string nome, float prezzo, string scadenza)
    :codice(codice),nome(nome),prezzo(prezzo),scadenza(scadenza){}
    virtual ~Prodotto(){}

    int getCodice() const{return codice;} string getNome() const{return nome;}
    float getPrezzo() const{return prezzo;} string getScadenza() const{return scadenza;}

    virtual void stampa() const{
        cout << "Codice: " << getCodice() << ", Nome: " << getNome
        << ", Prezzo: " << getPrezzo() << ", Scadenza: " << getScadenza() << endl;
    }

    friend std::ostream& operator <<(std::ostream &os, Prodotto *prod){
        prod->stampa();
        return os;
    }
};

class Sconto{
    protected:
    float percentuale;
    string scadenza;

    public:
    Sconto(float percentuale, string scadenza)
    : percentuale(percentuale), scadenza(scadenza){}
    virtual ~Sconto(){}
    float getPercentuale() const{return percentuale;}
    string getScadenza() const{return scadenza;}
};

class ProdottoScontato:public Prodotto{
    protected:
    Sconto* sconto;

    public:
    ProdottoScontato(int codice, string nome, float prezzo, string scadenza, Sconto *sconto)
    :Prodotto(codice, nome, prezzo, scadenza), sconto(sconto){}
    virtual ~ProdottoScontato(){}

    float getPrezzoScontato(){
        if(sconto->getScadenza() < "" )
        return (getPrezzo() * sconto->getPercentuale()) /100; 
    }
};

int main(){

}