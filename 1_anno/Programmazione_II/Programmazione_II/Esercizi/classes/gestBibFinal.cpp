#include <iostream>
using namespace std;

class ElementoBiblioteca {
protected:
    long ID;
    string titolo;
    int numPagine;
    bool disponibile;

public:
    ElementoBiblioteca(long ID, string titolo, int numPagine, bool disponibile = true)
        : ID(ID), titolo(titolo), numPagine(numPagine), disponibile(disponibile) {}

    long getID() const { return ID; }
    string getTitolo() const { return titolo; }
    int getPagine() const { return numPagine; }
    
    bool isDisponibile() const { return disponibile; }
    void setDisponibile(bool stato) { disponibile = stato; }

    virtual void stampaInfo() {
        cout << "ID: " << getID() << ", Titolo: " << getTitolo()
             << ", Pagine: " << getPagine() 
             << ", Stato: " << (isDisponibile() ? "Disponibile" : "Non disponibile") << endl;
    }

    friend ostream &operator<<(ostream &os, ElementoBiblioteca &elem) {
        elem.stampaInfo();
        return os;
    }
};

class Libro : public ElementoBiblioteca {
protected:
    string autore;

public:
    Libro(int ID, string titolo, int numPagine, string autore, bool disponibile = true)
        : ElementoBiblioteca(ID, titolo, numPagine, disponibile), autore(autore) {}

    string getAutore() const { return autore; }

    void stampaInfo() override {
        ElementoBiblioteca::stampaInfo();
        cout << ", Autore: " << getAutore() << endl;
    }
};

class Rivista : public ElementoBiblioteca {
protected:
    int numEdizione;

public:
    Rivista(int ID, string titolo, int numPagine, int numEdizione, bool disponibile = true)
        : ElementoBiblioteca(ID, titolo, numPagine, disponibile), numEdizione(numEdizione) {}

    int getEdizione() const { return numEdizione; }

    void stampaInfo() override {
        ElementoBiblioteca::stampaInfo();
        cout << ", Edizione: " << getEdizione() << endl;
    }
};

class Utente {
protected:
    string nome, cognome;
    int nTessera;
    ElementoBiblioteca* prestiti[10];
    int sizeP;

public:
    Utente(string nome, string cognome, int nTessera)
        : nome(nome), cognome(cognome), nTessera(nTessera), sizeP(0) {}

    string getCognome() const { return cognome; }
    int getNumTessera() const { return nTessera; }

    void aggiungiPrestato(ElementoBiblioteca* elem) {
        if (sizeP < 10) {
            prestiti[sizeP] = elem;
            sizeP++;
        } else {
            cout << "Errore: numero massimo di prestiti raggiunto!" << endl;
        }
    }

    void restituisci(ElementoBiblioteca* lib) {
        for (int i = 0; i < sizeP; i++) {
            if (prestiti[i] == lib) {
                lib->setDisponibile(true);
                cout << "Il libro '" << lib->getTitolo() << "' è stato restituito." << endl;
                prestiti[i] = prestiti[sizeP - 1]; // Spostiamo l'ultimo elemento qui
                sizeP--; // Riduciamo la dimensione
                return;
            }
        }
        cout << "Errore: il libro non è tra i prestiti dell'utente!" << endl;
    }

    friend ostream &operator<<(ostream &os, Utente &u) {
        os << "Libri presi in prestito da " << u.getCognome() << " (Tessera: " 
           << u.getNumTessera() << "): ";
        if (u.sizeP == 0) {
            os << "Nessun libro in prestito." << endl;
        } else {
            for (int i = 0; i < u.sizeP; i++) {
                os << u.prestiti[i]->getTitolo() << " ";
            }
            os << endl;
        }
        return os;
    }
};

class Biblioteca {
protected:
    ElementoBiblioteca* libri[10];
    int capacita;
    int numLibri;

public:
    Biblioteca() : capacita(10), numLibri(0) {}

    void aggiungiLibro(ElementoBiblioteca* libro) {
        if (numLibri < capacita) {
            libri[numLibri] = libro;
            numLibri++;
        } else {
            cout << "Errore: biblioteca piena!" << endl;
        }
    }

    void contaPagine() {
        int pagineTot = 0;
        for (int i = 0; i < numLibri; i++) {
            pagineTot += libri[i]->getPagine();
        }
        cout << "\nPagine totali in archivio: " << pagineTot << endl;
    }

    void prestaLibro(Utente& u, long ID) {
        for (int i = 0; i < numLibri; i++) {
            if (libri[i]->getID() == ID && libri[i]->isDisponibile()) {
                libri[i]->setDisponibile(false);
                u.aggiungiPrestato(libri[i]);
                cout << "Libro '" << libri[i]->getTitolo() << "' prestato a " << u.getCognome() << "!" << endl;
                return;
            }
        }
        cout << "Errore: libro non disponibile o non trovato." << endl;
    }

    friend ostream &operator<<(ostream &os, Biblioteca &archivio) {
        os << "Biblioteca - Capienza: " << archivio.capacita 
           << "\nElementi in archivio:" << endl;
        for (int i = 0; i < archivio.numLibri; i++) {
            os << i + 1 << ") " << *archivio.libri[i] << endl;
        }
        return os;
    }
};

// --- MAIN ---
int main() {
    Biblioteca archivio;

    // Creazione libri
    ElementoBiblioteca* libroUno = new Libro(1, "Harry Potter", 256, "J.K. Rowling");
    ElementoBiblioteca* libroDue = new Rivista(2, "Vogue", 144, 27);

    // Aggiunta libri all'archivio
    archivio.aggiungiLibro(libroUno);
    archivio.aggiungiLibro(libroDue);
    
    cout << archivio << endl;
    archivio.contaPagine();

    // Creazione utente
    Utente user("Mario", "Rossi", 102);
    
    // Prestito di un libro
    archivio.prestaLibro(user, 1);
    cout << user << endl;

    // Restituzione del libro
    user.restituisci(libroUno);
    cout << user << endl;

    cout << archivio << endl;

    // Pulizia della memoria
    delete libroUno;
    delete libroDue;

    return 0;
}
