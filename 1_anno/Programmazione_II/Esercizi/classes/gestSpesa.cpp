#include<iostream>
using namespace std;

class Prodotto{
    protected:
    string nome, categoria;
    int quantita;
    float prezzo;

    public:
    Prodotto(string nome, string categoria, int quantita, float prezzo)
     :nome(nome),categoria(categoria),quantita(quantita),prezzo(prezzo) {}
     virtual ~Prodotto(){}

     string getNome()const{return nome;} string getCategoria()const{return categoria;}
     int getQuantita()const{return quantita;} float getPrezzo()const{return prezzo;}

     float setPrezzo(float p){prezzo = p;}

     virtual void stampaInfo()const{
        cout << "Nome: " << getNome() << ", categoria" << getCategoria() << "quantita: " 
        << getQuantita() << ", prezzo: " << getPrezzo();
     }
};

class Spesa{
    protected:
    string nomeLista;
    Prodotto *prodotti[20]{};
    int numProdotti = 0;

    public:
    Spesa(string nomeLista, int numProdotti)
    :nomeLista(nomeLista),numProdotti(0){}
    ~Spesa(){}

    void aggiungiProdotto(Prodotto *prod){
        if(numProdotti < 20){
            prodotti[numProdotti++] = prod;
            numProdotti++;
        }
        cout << "capacità massima raggiunta";
    }

    void rimuoviProdotto(string nome){
        for(int i = 0; i < numProdotti; ++i){
            if(prodotti[i]->getNome() == nome){
                delete prodotti[i];
                for (int j = 1; j < numProdotti -1 ; ++j)
                {
                    prodotti[j] = prodotti[j+1];
                }
                prodotti[--numProdotti] = nullptr;
                cout << "Prodotto rimosso!";
            }
        }
    }
};