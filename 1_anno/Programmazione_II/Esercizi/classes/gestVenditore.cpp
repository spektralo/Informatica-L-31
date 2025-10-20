#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

// Classe base Prodotto
class Prodotto {
protected:
    static int nextCodice;
    int codice;
    double prezzo;

public:
    Prodotto() : codice(nextCodice++), prezzo(0) {}
    Prodotto(double p) : codice(nextCodice++), prezzo(p) {}
    virtual ~Prodotto() {}

    int getCodice() const { return codice; }
    double getPrezzo() const { return prezzo; }
    void setPrezzo(double p) { prezzo = p; }

    virtual void leggi() {
        std::cout << "Prezzo: ";
        std::cin >> prezzo;
    }

    friend std::ostream& operator<<(std::ostream& os, const Prodotto& p) {
        p.stampaDettagli(os);
        return os;
    }

    virtual void stampaDettagli(std::ostream& os) const {
        os << "Codice: " << codice << ", Prezzo: " << prezzo << "€";
    }

    virtual bool isScaduto() const { return false; }
};
int Prodotto::nextCodice = 1;

// Classe ProdottoAlimentare
class ProdottoAlimentare : public Prodotto {
    std::string scadenza;

public:
    ProdottoAlimentare() : Prodotto() {}
    ProdottoAlimentare(double p, const std::string& s) : Prodotto(p), scadenza(s) {}

    void leggi() override {
        Prodotto::leggi();
        std::cout << "Scadenza (GG/MM/AAAA): ";
        std::cin >> scadenza;
    }

    bool isScaduto() const override {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentDay = ltm->tm_mday;
        int currentMonth = ltm->tm_mon + 1;
        int currentYear = ltm->tm_year + 1900;

        int giorno, mese, anno;
        sscanf(scadenza.c_str(), "%d/%d/%d", &giorno, &mese, &anno);

        return (anno < currentYear) || 
               (anno == currentYear && mese < currentMonth) ||
               (anno == currentYear && mese == currentMonth && giorno < currentDay);
    }

    void stampaDettagli(std::ostream& os) const override {
        os << "ALIMENTARE - ";
        Prodotto::stampaDettagli(os);
        os << ", Scadenza: " << scadenza;
    }
};

// Classe ProdottoPerBambini
class ProdottoPerBambini : public Prodotto {
    std::string fascia;

public:
    ProdottoPerBambini() : Prodotto() {}
    ProdottoPerBambini(double p, const std::string& f) : Prodotto(p), fascia(f) {}

    void leggi() override {
        Prodotto::leggi();
        std::cout << "Fascia (0-3, 3-6, 6-9, 9-12): ";
        std::cin >> fascia;
        while(fascia != "0-3" && fascia != "3-6" && fascia != "6-9" && fascia != "9-12") {
            std::cout << "Fascia non valida! Reinserisci: ";
            std::cin >> fascia;
        }
    }

    void stampaDettagli(std::ostream& os) const override {
        os << "BAMBINI - ";
        Prodotto::stampaDettagli(os);
        os << ", Fascia: " << fascia;
    }
};

// Classe Venditore
class Venditore {
    static int nextCodice;
    int codice;
    Prodotto** prodotti;
    int numProdotti;
    int capacita;

public:
    Venditore() : codice(nextCodice++), prodotti(nullptr), numProdotti(0), capacita(0) {}
    Venditore(int cod) : codice(cod), prodotti(nullptr), numProdotti(0), capacita(0) {}
    
    ~Venditore() {
        for(int i = 0; i < numProdotti; ++i)
            delete prodotti[i];
        delete[] prodotti;
    }

    void aggiungiProdotto(Prodotto* p) {
        if(numProdotti >= capacita) {
            capacita = (capacita == 0) ? 2 : capacita * 2;
            Prodotto** newArr = new Prodotto*[capacita];
            for(int i = 0; i < numProdotti; ++i)
                newArr[i] = prodotti[i];
            delete[] prodotti;
            prodotti = newArr;
        }
        prodotti[numProdotti++] = p;
    }

    double calcolaPrezzoTotale() const {
        double totale = 0;
        for(int i = 0; i < numProdotti; ++i)
            totale += prodotti[i]->getPrezzo();
        return totale;
    }

    double calcolaValoreMagazzino() const {
        double totale = 0;
        for(int i = 0; i < numProdotti; ++i)
            if(!prodotti[i]->isScaduto())
                totale += prodotti[i]->getPrezzo();
        return totale;
    }

    friend std::ostream& operator<<(std::ostream& os, const Venditore& v) {
        os << "Venditore " << v.codice << "\nProdotti:\n";
        for(int i = 0; i < v.numProdotti; ++i)
            os << *v.prodotti[i] << "\n";
        return os;
    }

    static bool compareCrescente(const Venditore* a, const Venditore* b) {
        return a->calcolaPrezzoTotale() < b->calcolaPrezzoTotale();
    }

    static bool compareDecrescente(const Venditore* a, const Venditore* b) {
        return a->calcolaPrezzoTotale() > b->calcolaPrezzoTotale();
    }
};
int Venditore::nextCodice = 1;

// Funzione main
int main() {
    std::vector<Venditore*> venditori;
    
    // Creazione 3 venditori
    for(int i = 0; i < 3; ++i) {
        Venditore* v = new Venditore();
        for(int j = 0; j < 5; ++j) {
            std::cout << "Tipo prodotto (1-Alimentare, 2-Bambini): ";
            int tipo;
            std::cin >> tipo;
            
            Prodotto* p;
            if(tipo == 1) p = new ProdottoAlimentare();
            else p = new ProdottoPerBambini();
            
            p->leggi();
            v->aggiungiProdotto(p);
        }
        venditori.push_back(v);
    }

    // Menu
    int scelta;
    do {
        std::cout << "\n1. Stampa venditori (crescente)\n"
                  << "2. Stampa venditori (decrescente)\n"
                  << "0. Esci\nScelta: ";
        std::cin >> scelta;

        if(scelta == 1 || scelta == 2) {
            std::vector<Venditore*> temp = venditori;
            if(scelta == 1)
                sort(temp.begin(), temp.end(), Venditore::compareCrescente);
            else
                sort(temp.begin(), temp.end(), Venditore::compareDecrescente);

            for(auto v : temp) {
                std::cout << *v << "Totale: " << v->calcolaPrezzoTotale() 
                          << "\nMagazzino: " << v->calcolaValoreMagazzino() 
                          << "\n\n";
            }
        }
    } while(scelta != 0);

    // Pulizia memoria
    for(auto v : venditori) delete v;
    return 0;
}