#include<iostream>
using namespace std;

class Persona {
protected:
    string nome, cognome, matricola;

public:
    Persona(string nome, string cognome, string matricola)
        : nome(nome), cognome(cognome), matricola(matricola) {}
    virtual ~Persona() {}

    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    string getMatricola() const { return matricola; }

    virtual string getRuolo() const = 0;

    virtual void stampaInfo(ostream& os) const {
        os << "Nome: " << getNome() << ", Cognome: " << getCognome()
           << ", Matricola: " << getMatricola();
    }

    friend ostream& operator<<(ostream& os, Persona& pers) {
        pers.stampaInfo(os);
        return os;
    }
};

class Studente : public Persona {
protected:
    string corsoLaurea;
    float mediaVoti;

public:
    Studente(string nome, string cognome, string matricola, string corsoLaurea, float mediaVoti)
        : Persona(nome, cognome, matricola), corsoLaurea(corsoLaurea), mediaVoti(mediaVoti) {}
    virtual ~Studente() {}

    string getCorso() const { return corsoLaurea; }
    float getMedia() const { return mediaVoti; }
    string getRuolo() const override { return "Studente"; }

    void stampaInfo(ostream& os) const override {
        os << "[Studente] ";
        Persona::stampaInfo(os);
        os << ", Corso di Laurea: " << getCorso()
           << ", Media: " << getMedia() << endl;
    }

    friend ostream& operator<<(ostream& os, Studente& stud) {
        stud.stampaInfo(os);
        return os;
    }
};

class Docente : public Persona {
protected:
    string settore;
    int anniServizio;

public:
    Docente(string nome, string cognome, string matricola, string settore, int anniServizio)
        : Persona(nome, cognome, matricola), settore(settore), anniServizio(anniServizio) {}
    virtual ~Docente() {}

    string getSettore() const { return settore; }
    int getAnniServizio() const { return anniServizio; }
    string getRuolo() const override { return "Docente"; }

    void stampaInfo(ostream& os) const override {
        os << "[Docente] ";
        Persona::stampaInfo(os);
        os << ", Settore: " << getSettore()
           << ", Anni di Servizio: " << getAnniServizio() << endl;
    }

    friend ostream& operator<<(ostream& os, Docente& doc) {
        doc.stampaInfo(os);
        return os;
    }
};

class Ateneo {
protected:
    string nomeAteneo;
    Persona* personale[100]{};
    int numPersonale = 0;

public:
    Ateneo(string nomeAteneo) : nomeAteneo(nomeAteneo) {}
    virtual ~Ateneo() {
        for (int i = 0; i < numPersonale; i++) {
            delete personale[i];
            numPersonale--;
        }
    }

    string getAteneo() const { return nomeAteneo; }

    void aggiungiPersona(Persona* p) {
        if (numPersonale < 100) {
            personale[numPersonale++] = p;
        }
        else {
            cout << "Personale massimo raggiunto!" << endl;
        }
    }

    int contaRuolo(string ruolo) {
        int conta = 0;
        for (int i = 0; i < numPersonale && personale[i] != nullptr; i++) {
            if (personale[i]->getRuolo() == ruolo) {
                conta++;
            }
        }
        cout << "entry for " << ruolo << " = " << conta << endl;
        return conta;
    }

    void stampaPersonale(ostream& os) {
        os << "=== Ateneo: " << getAteneo() << " ===" << endl;
        os << "Elenco del personale:" << endl;
        for (int i = 0; i < numPersonale && personale[i] != nullptr; i++) {
            os << "  " << i + 1 << ") ";
            personale[i]->stampaInfo(os);
        }
        os << "==============================" << endl;
    }

    friend ostream& operator<<(ostream& os, Ateneo& at) {
        at.stampaPersonale(os);
        return os;
    }
};



int main() {
    Ateneo* universita = new Ateneo("UniBO");

    Studente* studenteUno = new Studente("Andrea", "Rossi", "100192", "L-31", 28.2);
    Studente* studenteDue = new Studente("Marco", "Bianchi", "18122", "L-18", 24.1);
    Studente* studenteTre = new Studente("Luigi", "Neri", "103292", "L-11", 29.0);

    Docente* docenteUno = new Docente("Vincenzo", "Cutello", "X01234", "AI", 13);
    Docente* docenteDue = new Docente("Federico", "Santoro", "Z8412", "IoT", 6);

    universita->aggiungiPersona(studenteUno);
    universita->aggiungiPersona(studenteDue);
    universita->aggiungiPersona(studenteTre);

    universita->aggiungiPersona(docenteUno);
    universita->aggiungiPersona(docenteDue);

    cout << *universita;
    universita->contaRuolo("Studente");
    universita->contaRuolo("Docente");

    delete universita;
}
