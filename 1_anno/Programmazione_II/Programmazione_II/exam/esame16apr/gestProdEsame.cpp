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
    Cliente *cliente;
    Prodotto *prodotti[10]{};
    int numClienti = 0, numProdotti = 0;
    
    public:
    Ordine(string idOrdine, Cliente *cliente)
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
        float tot = 0;
        for (int i = 0; i < numProdotti && prodotti[i]!=nullptr; i++)
        {
           tot += prodotti[i]->getPrezzo();
        }
        return tot;
    }

    void stampaInfo(ostream &os){
        os << "ID ordine: " << getID() << "\n" << *cliente << "\nProdotti:\n";
        for (int i = 0; i < numProdotti && prodotti[i]!=nullptr; i++)
        {
            os << i+1 << ")" << *prodotti[i] << "\n";
        }
        os << "Totale ordine: " << calcoloTotale() << "\n" << endl;
    }

    friend ostream &operator <<(ostream &os, Ordine &ord){
        ord.stampaInfo(os);
        return os;
    }
};

class NegozioOnline{
    protected:
    string nomeNegozio;
    Prodotto *prodotti[200]{};
    Ordine *ordini[100]{};
    int numOrdini = 0, numProdotti = 0;

    public:
    NegozioOnline(string nomeNegozio):nomeNegozio(nomeNegozio){}
    ~NegozioOnline(){}

    string getNomeNegozio()const{return nomeNegozio;}

    void aggiungiOrdine(Ordine *ord){
        if(numOrdini < 100){
            ordini[numOrdini++] = ord;
        }
    }

    void aggiungiProdotto(Prodotto *p){
        if(numProdotti < 200){
            prodotti[numProdotti++] = p;
        }
    }

    float calcolaIncasso()const{
        float tot = 0;
        for (int i = 0; i < numOrdini && ordini[i]!=nullptr; i++)
        {
            tot += ordini[i]->calcoloTotale();
        }
        return tot;
    }

    void stampaInfo(ostream &os)const{
        os << "Negozio: " << getNomeNegozio() << ", ordini:\n ";
        for (int i = 0; i < numOrdini && ordini[i]!=nullptr; i++)
        {
            os << i + 1 << ")" << *ordini[i];
        }
        os << "Totale incasso complessivo: " << calcolaIncasso() << "\n" <<  endl;
    }

    friend ostream &operator<<(ostream &os, NegozioOnline &neg){
        neg.stampaInfo(os);
        return os;
    }
};

    int main(){
        // Creo clienti
        Cliente *clienteUno = new Cliente("Mario", "Rossi", "mariorossi89@gmail.com");
        Cliente *clienteDue = new Cliente("Giulia", "Verdi", "giuliaverdi@gmail.com");
        Cliente *clienteTre = new Cliente("Luca", "Bianchi", "lucabianchi@gmail.com");
    
        // Creo alcuni prodotti
        Prodotto *p1 = new ProdottoTecnologico("Laptop", "X120", 499.99, "HP", 2);
        Prodotto *p2 = new ProdottoTecnologico("Mouse", "X01", 69.99, "Dell", 1);
        Prodotto *p3 = new ProdottoAlimentare("Banana", "A01", 0.99, 6, 2026, true);
        Prodotto *p4 = new ProdottoAlimentare("Latte", "B02", 1.29, 5, 2025, true);
    
        // Creo il negozio online
        NegozioOnline negozio("SuperStore");
    
        // Aggiungo prodotti al negozio
        negozio.aggiungiProdotto(p1);
        negozio.aggiungiProdotto(p2);
        negozio.aggiungiProdotto(p3);
        negozio.aggiungiProdotto(p4);
    
        // Creo alcuni ordini per i clienti
        Ordine *ordineUno = new Ordine("0123", clienteUno);
        ordineUno->aggiungiProdotto(p1);
        ordineUno->aggiungiProdotto(p2);
    
        Ordine *ordineDue = new Ordine("0456", clienteDue);
        ordineDue->aggiungiProdotto(p3);
        ordineDue->aggiungiProdotto(p4);
    
        Ordine *ordineTre = new Ordine("0789", clienteTre);
        ordineTre->aggiungiProdotto(p1);
        ordineTre->aggiungiProdotto(p4);
    
        // Aggiungo gli ordini al negozio
        negozio.aggiungiOrdine(ordineUno);
        negozio.aggiungiOrdine(ordineDue);
        negozio.aggiungiOrdine(ordineTre);
    
        cout << negozio;
    
        return 0;
    }    
