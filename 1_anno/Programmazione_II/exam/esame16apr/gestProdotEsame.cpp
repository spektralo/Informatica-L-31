#include<iostream>
using namespace std;

class Prodotto{
    protected:
    int codice;
    double prezzo;

    public:
    Prodotto(){codice = 0; prezzo = 0;}
    Prodotto(int codice, double prezzo)
    :codice(codice),prezzo(prezzo){}
    virtual ~Prodotto(){}

    virtual bool checkScadenza(int mm, int yy)const = 0;
    int getCodice()const{return codice;} double getPrezzo()const{return prezzo;}
    void setCodice(int cod){codice = cod;} void setPrezzo(double p){prezzo = p;}

    virtual void stampaInfo(ostream &os)const{
        os << "Codice: " << getCodice() << ", prezzo: " << getPrezzo() << endl;
    }

    friend ostream &operator <<(ostream &os, Prodotto &prod){
        prod.stampaInfo(os);
        return os;
    }
};

class ProdottoAlimentare:public Prodotto{
    protected:
    int mm,yy;

    public:
    ProdottoAlimentare(int codice, double prezzo, int mm, int yy)
    :Prodotto(codice,prezzo),mm(mm),yy(yy){}
    ~ProdottoAlimentare(){}

    int getMM()const{return mm;} int getYY()const{return yy;}

    bool checkScadenza(int mm, int yy)const override{
        if(mm > getMM() && yy > getYY()){
            return true;
        }
        else {return false;}
    }

    void stampaInfo(ostream &os)const override{
        Prodotto::stampaInfo(os);
        os << ", scadenza: " << getMM() << "/" << getYY() << endl;
    }

    friend ostream &operator<<(ostream &os, ProdottoAlimentare &p){
        p.stampaInfo(os);
        return os;
    }
};

class ProdottoBambini:public Prodotto{
    protected:
    string fasciaEta;

    public:
    ProdottoBambini(int codice, double prezzo, string fasciaEta)
    :Prodotto(codice,prezzo),fasciaEta(fasciaEta){}
    virtual ~ProdottoBambini(){}

    string getFasciaEta()const{return fasciaEta;}

    bool checkScadenza(int mm, int yy)const override{return false;}

    void stampaInfo(ostream &os)const override{
        Prodotto::stampaInfo(os);
        os << ", fascia eta: " << getFasciaEta() << endl;
    }

    friend ostream &operator<<(ostream &os, ProdottoBambini &p){
        p.stampaInfo(os);
        return os;
    }
};


class Venditore{
    int codice;
    Prodotto *venduti[50]{};
    int numProdotti = 0;

    public:
    Venditore(){codice = 0; *venduti = 0, numProdotti = 0;}
    Venditore(int codice):codice(codice){}
    ~Venditore(){}

    int getCodice()const{return codice;}

    void aggiungiProdotto(Prodotto *p){
        if(numProdotti < 50){
            venduti[numProdotti++] = p;
        }
        else {cout << "Limite di prodotti raggiunto!";}
    }

    double calcolaTotale(){
        double totale = 0;
        for (int i = 0; i < numProdotti && venduti[i]!=nullptr; i++)
        {
            totale += venduti[i]->getPrezzo();
        }
        return totale;
    }

    double calcolaMagazzino(int mm, int yy){
        double totMag = 0;
        for (int i = 0; i < numProdotti && venduti[i]!=nullptr; i++)
        {
            if(venduti[i]->checkScadenza(mm,yy) == true)
            totMag += venduti[i]->getPrezzo();
        }
        return totMag;
    }

    void stampaVenditore(ostream &os)const{
        os << "Codice: " << getCodice() << ", prodotti venduti:\n" << endl;
        for (int i = 0; i < numProdotti && venduti[i]!=nullptr; i++)
        {
            os << i + 1 << ")" << *venduti[i] << endl;
        }
    }

    friend ostream &operator <<(ostream &os, Venditore &vend){
        vend.stampaVenditore(os);
        return os;
    }
};

int main() {
    // Creo alcuni prodotti
    Prodotto* p1 = new ProdottoAlimentare(101, 3.50, 4, 2025);
    Prodotto* p2 = new ProdottoAlimentare(102, 2.10, 12, 2024);
    Prodotto* p3 = new ProdottoBambini(103, 5.99, "3-5 anni");
    Prodotto* p4 = new ProdottoBambini(104, 4.75, "6-8 anni");
    Prodotto* p5 = new ProdottoAlimentare(105, 6.30, 6, 2023);

    Prodotto* p6 = new ProdottoAlimentare(201, 2.99, 11, 2025);
    Prodotto* p7 = new ProdottoBambini(202, 3.99, "1-3 anni");
    Prodotto* p8 = new ProdottoAlimentare(203, 7.50, 7, 2024);
    Prodotto* p9 = new ProdottoBambini(204, 2.50, "0-1 anni");
    Prodotto* p10 = new ProdottoAlimentare(205, 4.20, 5, 2023);

    Prodotto* p11 = new ProdottoBambini(301, 6.80, "3-6 anni");
    Prodotto* p12 = new ProdottoAlimentare(302, 1.99, 10, 2024);
    Prodotto* p13 = new ProdottoAlimentare(303, 3.49, 1, 2026);
    Prodotto* p14 = new ProdottoBambini(304, 5.00, "6-10 anni");
    Prodotto* p15 = new ProdottoAlimentare(305, 8.70, 9, 2025);

    // Creo venditori
    Venditore v1(1);
    Venditore v2(2);
    Venditore v3(3);

    // Assegno 5 prodotti ciascuno
    v1.aggiungiProdotto(p1);
    v1.aggiungiProdotto(p2);
    v1.aggiungiProdotto(p3);
    v1.aggiungiProdotto(p4);
    v1.aggiungiProdotto(p5);

    v2.aggiungiProdotto(p6);
    v2.aggiungiProdotto(p7);
    v2.aggiungiProdotto(p8);
    v2.aggiungiProdotto(p9);
    v2.aggiungiProdotto(p10);

    v3.aggiungiProdotto(p11);
    v3.aggiungiProdotto(p12);
    v3.aggiungiProdotto(p13);
    v3.aggiungiProdotto(p14);
    v3.aggiungiProdotto(p15);

    // Stampo le informazioni
    cout << v1 << endl;
    cout << "Totale vendite: " << v1.calcolaTotale() << endl;
    cout << "Totale magazzino (prodotti scaduti al 6/2024): " << v1.calcolaMagazzino(6, 2024) << "\n" << endl;

    cout << v2 << endl;
    cout << "Totale vendite: " << v2.calcolaTotale() << endl;
    cout << "Totale magazzino (prodotti scaduti al 6/2024): " << v2.calcolaMagazzino(6, 2024) << "\n" << endl;

    cout << v3 << endl;
    cout << "Totale vendite: " << v3.calcolaTotale() << endl;
    cout << "Totale magazzino (prodotti scaduti al 6/2024): " << v3.calcolaMagazzino(6, 2024) << "\n" << endl;

    return 0;
}
