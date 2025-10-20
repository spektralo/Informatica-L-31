#include<iostream>
using namespace std;

class Prodotto{
    protected:
    string nome, codice;
    float prezzo;

    public:
    Prodotto(string nome, string codice, float prezzo)
    :nome(nome),codice(codice),prezzo(prezzo){}
    ~Prodotto(){}

    string getNome()const{return nome;} string getCodice()const{return codice;}
    float getPrezzo()const{return prezzo;}

    virtual string getCategoria()const = 0;
    
    virtual void stampaInfo(ostream &os)const{
        os << "Nome: " << getNome() << ", codice: " << getCodice()
        << ", prezzo: " << getPrezzo() << endl;
    }

    friend ostream &operator<<(ostream &os, Prodotto &p){
        p.stampaInfo(os);
        return os;
    }
};

class ProdottoAlimentare:public Prodotto{
    protected:
    int mm, yy;
    bool biologico;

    public:
    ProdottoAlimentare(string nome, string codice, float prezzo, int mm, int yy, bool biologico = true)
    :Prodotto(nome,codice,prezzo),mm(mm),yy(yy),biologico(biologico){}
    ~ProdottoAlimentare(){}

    int getMM()const{return mm;} int getYY()const{return yy;} bool getBio()const{return biologico;}

    string getCategoria()const override{return "Prodotto Alimentare";}

    void stampaInfo(ostream &os)const override{
        Prodotto::stampaInfo(os);
        os << ", scadenza: " << getMM() << "/" << getYY() << ", biologico: " << getBio() << endl;
    }

    friend ostream &operator<<(ostream &os, ProdottoAlimentare &p){
        p.stampaInfo(os);
        return os;
    }
};

class ProdottoTecnologico:public Prodotto{
    protected:
    string marca;
    int garanziaY;

    public:
    ProdottoTecnologico(string nome, string codice, float prezzo, string marca, int garanziaY)
    :Prodotto(nome,codice,prezzo),marca(marca),garanziaY(garanziaY){}
    virtual ~ProdottoTecnologico(){}

    string getMarca()const{return marca;} int getGaranzia()const{return garanziaY;}
    string getCategoria()const override{return "Prodotto Tecnologico";}

    void stampaInfo(ostream &os)const override{
        Prodotto::stampaInfo(os);
        os << ", marca: " << getMarca() << ", anni di garanzia: " << getGaranzia() << endl;
    }

    friend ostream &operator <<(ostream &os, ProdottoTecnologico &p){
        p.stampaInfo(os);
        return os;
    }
};

class Cliente{
    protected:
    string nome, cognome, mail;

    public:
    Cliente(string nome, string cognome, string mail)
    :nome(nome),cognome(cognome),mail(mail){}
    ~Cliente(){}

    string getNome()const{return nome;} string getCognome()const{return cognome;}
    string getMail()const{return mail;}

    void stampaInfo(ostream &os)const{
        os << "Nome: " << getNome() << ", cognome: "  << getCognome()
        << ", mail: " << getMail() << endl; 
    }

    friend ostream &operator <<(ostream &os, Cliente &cl){
        cl.stampaInfo(os);
        return os;
    }
};

class Ordine{
    protected:
    string idOrdine;
    Cliente *cliente{};
    Prodotto *prodotti[10]{};
    int numClienti = 0, numProdotti = 0;
    
    public:
    Ordine(string idOrdine, Cliente *clienti, Prodotto *prodotti)
    :idOrdine(idOrdine),cliente(cliente){}
    virtual ~Ordine(){}

    string getID()const{return idOrdine;}

    void aggiungiProdotto(Prodotto *p){
        if (numProdotti < 10)
        {
            prodotti[numProdotti++] = p;
        }
    }

    float calcoloTotale()const{
        float totale;
        for (int i = 0; i < numProdotti && prodotti[i]!=nullptr; i++)
        {
           totale += prodotti[i]->getPrezzo();
        }
        return totale;
    }

    void stampaInfo(ostream &os){
        os << "ID: " << getID() << cliente << "prodotti:\n";
        for (int i = 0; i < numProdotti && prodotti[i]!=nullptr; i++)
        {
            os << i+1 << ")" << *prodotti[i];
        }
    }

    friend ostream &operator <<(ostream &os, Ordine &ord){
        ord.stampaInfo(os);
        return os;
    }
};



int main(){


};