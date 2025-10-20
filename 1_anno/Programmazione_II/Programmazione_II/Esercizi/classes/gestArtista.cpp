#include <iostream>
using namespace std;

class PersonaleAcc {
protected:
    string matricola;
    int pagaBase;
    int gg, mm, yy;

public:
    PersonaleAcc(string matricola, int pagaBase, int gg, int mm, int yy)
        : matricola(matricola), pagaBase(pagaBase), gg(gg), mm(mm), yy(yy) {}
    virtual ~PersonaleAcc() {}

    string getMatricola() const { return matricola; }
    int getPagaBase() const { return pagaBase; }
    int getGG() const { return gg; }
    int getMM() const { return mm; }
    int getYY() const { return yy; }

    void setPagaBase(int p) { pagaBase = p; }
    void setGG(int giorno) { gg = giorno; }
    void setMM(int mese) { mm = mese; }
    void setYY(int anno) { yy = anno; }

    virtual long calcolaRetribuzione() const = 0;

    virtual void stampaInfo(ostream& os) const {
        os << "Matricola: " << getMatricola()
           << ", Paga base: " << getPagaBase()
           << ", Data di nascita: " << getGG() << "/" << getMM() << "/" << getYY() << endl;
    }

    friend ostream& operator<<(ostream& os, PersonaleAcc& pers) {
        pers.stampaInfo(os);
        return os;
    }
};

class Docente : public PersonaleAcc {
protected:
    int oreMensili;

public:
    Docente(string matricola, int pagaBase, int gg, int mm, int yy, int oreMensili)
        : PersonaleAcc(matricola, pagaBase, gg, mm, yy), oreMensili(oreMensili) {}

    virtual ~Docente() {}

    int getOreMensili() const { return oreMensili; }

    long calcolaRetribuzione() const override {
        return getPagaBase() + (30 * oreMensili);
    }

    void stampaInfo(ostream& os) const override {
        os << "[DOCENTE] ";
        PersonaleAcc::stampaInfo(os);
        os << "Ore mensili: " << getOreMensili()
           << ", Retribuzione: " << calcolaRetribuzione() << endl;
    }

    friend ostream& operator<<(ostream& os, Docente& d) {
        d.stampaInfo(os);
        return os;
    }
};

class Pubblicazione {
protected:
    string titolo;
    int anno;

public:
    Pubblicazione(string titolo, int anno)
        : titolo(titolo), anno(anno) {}

    ~Pubblicazione() {}

    string getTitolo() const { return titolo; }
    int getAnno() const { return anno; }

    void stampaPub(ostream& os) const {
        os << "Titolo: " << getTitolo() << ", Anno: " << getAnno() << endl;
    }
};

class Ricercatore : public PersonaleAcc {
protected:
    Pubblicazione* pubblicazioni[10]{};
    int numPubblicazioni = 0;

public:
    Ricercatore(string matricola, int pagaBase, int gg, int mm, int yy)
        : PersonaleAcc(matricola, pagaBase, gg, mm, yy) {}

    virtual ~Ricercatore() {
        for (int i = 0; i < numPubblicazioni; ++i) {
            delete pubblicazioni[i];
        }
    }

    void aggiungiPub(Pubblicazione* pub) {
        if (numPubblicazioni < 10) {
            pubblicazioni[numPubblicazioni++] = pub;
        } else {
            cout << "Numero massimo di pubblicazioni raggiunto!" << endl;
        }
    }

    long calcolaRetribuzione() const override {
        return getPagaBase() + (100 * numPubblicazioni);
    }

    void stampaInfo(ostream& os) const override {
        os << "[RICERCATORE] ";
        PersonaleAcc::stampaInfo(os);
        os << "Numero pubblicazioni: " << numPubblicazioni << endl;
        for (int i = 0; i < numPubblicazioni; ++i) {
            os << "   " << i + 1 << ") ";
            pubblicazioni[i]->stampaPub(os);
        }
        os << "Retribuzione: " << calcolaRetribuzione() << endl;
    }

    friend ostream& operator<<(ostream& os, Ricercatore& ric) {
        ric.stampaInfo(os);
        return os;
    }
};

class Ateneo {
protected:
    string nomeAteneo;
    PersonaleAcc* personale[50]{};
    int numPersonale = 0;

public:
    Ateneo(string nomeAteneo)
        : nomeAteneo(nomeAteneo) {}

    virtual ~Ateneo() {
        for (int i = 0; i < numPersonale; ++i) {
            delete personale[i];
        }
    }

    string getNomeAteneo() const { return nomeAteneo; }

    void aggiungiPersonale(PersonaleAcc* p) {
        if (numPersonale < 50) {
            personale[numPersonale++] = p;
        } else {
            cout << "Personale massimo raggiunto!" << endl;
        }
    }

    void eliminaPersonale(PersonaleAcc *p) {
        for (int i = 0; i < numPersonale; i++) {
            if (personale[i] == p) {
                // Deallocazione della memoria
                delete personale[i];
                // Spostamento degli altri elementi
                for (int j = i; j < numPersonale - 1; j++) {
                    personale[j] = personale[j + 1];
                }
                // Impostiamo l'ultimo elemento come nullptr (se si desidera evitare riferimenti errati)
                personale[numPersonale - 1] = nullptr;
                numPersonale--; // Decrementiamo il contatore
                cout << "Eliminato: " << p->getMatricola() << endl;
                return; // Non serve continuare la ricerca
            }
        }
        cout << "Personale non trovato!" << endl;
    }
    

    void calcolaTotMensile(int mese) {
        long totMensile = 0;
        for (int i = 0; i < numPersonale; ++i) {
            totMensile += personale[i]->calcolaRetribuzione();
        }
        cout << "Totale retribuzione mensile (" << mese << "): " << totMensile << " euro" << endl;
    }

    void calcolaPremio(int annoCurr) {
        cout << "\n--- Premi per anzianità (" << annoCurr << ") ---" << endl;
        for (int i = 0; i < numPersonale; ++i) {
            int eta = annoCurr - personale[i]->getYY();
            if (eta >= 30) {
                long premio = personale[i]->calcolaRetribuzione() + 300;
                cout << "Premio concesso a: " << personale[i]->getMatricola()
                     << ", Premio: " << premio << " euro" << endl;
            }
        }
    }

    friend ostream& operator<<(ostream& os, Ateneo& at) {
        os << "\n[Ateneo: " << at.getNomeAteneo() << "] Elenco personale:\n";
        for (int i = 0; i < at.numPersonale; ++i) {
            os << i + 1 << ") ";
            at.personale[i]->stampaInfo(os);
        }
        return os;
    }
};

// ------------------------- MAIN -------------------------

int main() {
    Ateneo* ateneo = new Ateneo("UNICT");

    Ricercatore* ric = new Ricercatore("1000059692", 1000, 27, 12, 1986);
    Docente* doc = new Docente("1000321", 1200, 31, 10, 1990, 40);

    Pubblicazione* pub1 = new Pubblicazione("Libro", 2012);
    Pubblicazione* pub2 = new Pubblicazione("Ricerca", 2013);
    ric->aggiungiPub(pub1);
    ric->aggiungiPub(pub2);


    ateneo->aggiungiPersonale(ric);
    ateneo->aggiungiPersonale(doc);

    cout << "\n--- Info Personale ---\n";
    cout << *ric;
    cout << *doc;

    cout << "\n--- Calcolo Totale Mensile ---\n";
    ateneo->calcolaTotMensile(3);
    ateneo->calcolaPremio(2023);

    cout << *ateneo;

    delete ateneo;  // Libera tutto
    return 0;
}
