#include<iostream>
using namespace std;

class Libro{
    protected:
    static int nextCodice;
    int codice;
    string titolo;
    double prezzo;

    public:
    Libro(): codice(nextCodice++), titolo(""),prezzo(0){}
    Libro(int codice,string titolo,double prezzo) :codice(+nextCodice++), titolo(titolo), prezzo(prezzo){}
    virtual ~Libro(){}
    void setPrezzo(double p){prezzo = p;} void setTitolo(string t){titolo = t;}
    int getPrezzo() const {return prezzo;} string getTitolo() const {return titolo;}

    friend std::ostream& operator << (std::ostream& os, Libro& lib){
        os << "Codice: " << lib.codice << ", Titolo: " << lib.titolo << ", Prezzo: " << lib.prezzo; 
        return os;
    }

    virtual void leggiInput(){
        cout << "Inserisci il titolo: " << endl; cin >> titolo;
        cout << "Inserisci il prezzo: " << endl; cin >> prezzo;
    }

   virtual bool isDisponibile(){return true;}
};

int Libro::nextCodice = 1;

class LibroCartaceo:public Libro{
    protected:
    int pagine;
    bool inMagazzino = true;

    public:
    LibroCartaceo(int codice, string titolo, double prezzo, int pagine, bool inMagazzino)
    : Libro(codice,titolo,prezzo), pagine(pagine), inMagazzino(inMagazzino){}
    virtual ~LibroCartaceo(){}

    virtual void leggiInput() override{
        cout << "Inserisci il titolo: " << endl; cin >> titolo;
        cout << "Inserisci il prezzo: " << endl; cin >> prezzo;
        cout << "Inserisci numero pagine: " << endl; cin >> pagine;
    }

    virtual bool isDisponibile() override{
        return inMagazzino;
    }

    friend std::ostream& operator << (std::ostream& os, LibroCartaceo& lib){
        os << "Codice: " << lib.codice << ", Titolo: " << lib.titolo << ", Prezzo: " << lib.prezzo <<
        ", Pagine: " << lib.pagine << ", Disponibilita: " << lib.isDisponibile();
        return os;
    }
};

class LibroDigitale:public Libro{
    protected:
    string formato;

    public:
    LibroDigitale(int codice, string titolo, double prezzo, string formato)
    : Libro(codice,titolo,prezzo), formato(formato){}
    ~LibroDigitale(){}

    virtual void leggiInput() override{
        cout << "Inserisci il titolo: " << endl; cin >> titolo;
        cout << "Inserisci il prezzo: " << endl; cin >> prezzo;
        cout << "Inserisci formato: " << endl; cin >> formato;
    }

    friend std::ostream& operator << (std::ostream& os, LibroDigitale& lib){
        os << "Codice: " << lib.codice << ", Titolo: " << lib.titolo << ", Prezzo: " << lib.prezzo <<
        ", Formato: " << lib.formato;
        return os;
    }
};

class Libreria{
    protected:
    int codiceLib;
    Libro** libri;
    int numLibri;

    public:
    Libreria

};

int main(){
  
}