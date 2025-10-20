#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nome, cognome;
    long codFiscale;

public:
    Persona(string nome, string cognome, long codFiscale)
        : nome(nome), cognome(cognome), codFiscale(codFiscale) {}

    Persona(string nome, string cognome)
        : nome(nome), cognome(cognome), codFiscale(0) {}

    virtual ~Persona() {}

    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    long getCod() const { return codFiscale; }

    void setNome(string n) { nome = n; }
    void setCognome(string c) { cognome = c; }
    void setCod(long c) { codFiscale = c; }

    virtual void stampaInfo() const {
        cout << "Nome: " << getNome() << ", Cognome: " << getCognome() << endl;
    }

    friend ostream &operator<<(ostream &os, Persona &pers) {
        pers.stampaInfo();
        return os;
    }
};

class Medico : public Persona {
protected:
    string special;
    float tariffa;
    bool disp;

public:
    Medico(string nome, string cognome, string special, float tariffa, bool disp = true)
        : Persona(nome, cognome), special(special), tariffa(tariffa), disp(disp) {}

    string getSpecial() const { return special; }
    float getTariffa() const { return tariffa; }
    bool isDisp() const { return disp; }

    void setSpecial(string s) { special = s; }
    void setTariffa(float t) { tariffa = t; }
    void setDisp(bool b) { disp = b; }

    void stampaInfo() const override {
        Persona::stampaInfo();
        cout << "Specializzazione: " << special << ", Tariffa: " << tariffa
             << ", Disponibile: " << (disp ? "S\u00ec" : "No") << endl;
    }
};

class Paziente : public Persona {
protected:
    string tSanitaria;
    Prenotazione *storico[5]{};

public:
    Paziente(string nome, string cognome, long codFiscale, string tSanitaria)
        : Persona(nome, cognome, codFiscale), tSanitaria(tSanitaria) {}

    string getSanitaria() const { return tSanitaria; }

    void stampaInfo() const override {
        Persona::stampaInfo();
        cout << "Tessera Sanitaria: " << tSanitaria << endl;
    }

    void aggiungiPrenotazioneStorico(Prenotazione *p) {
        for (int i = 0; i < 5; i++) {
            if (storico[i] == nullptr) {
                storico[i] = p;
                break;
            }
        }
    }
};

class Prenotazione {
protected:
    int gg, mm, yy;
    float orario;
    Medico *medicoAss;
    Paziente *pazienteAss;

public:
    Prenotazione(int gg, int mm, int yy, float orario, Medico *medicoAss, Paziente *pazienteAss)
        : gg(gg), mm(mm), yy(yy), orario(orario), medicoAss(medicoAss), pazienteAss(pazienteAss) {}

    void stampaDettagli() const {
        cout << "Data: " << gg << "/" << mm << "/" << yy << ", Orario: " << orario << endl;
        cout << "Medico: " << medicoAss->getNome() << " " << medicoAss->getCognome() << endl;
        cout << "Paziente: " << pazienteAss->getNome() << " " << pazienteAss->getCognome() << endl;
    }

    friend ostream &operator<<(ostream &os, Prenotazione &pr) {
        pr.stampaDettagli();
        return os;
    }

    void conferma() {
        if (medicoAss->isDisp()) {
            medicoAss->setDisp(false);
            pazienteAss->aggiungiPrenotazioneStorico(this);
            cout << "Prenotazione confermata!\n";
        }
    }

    void elimina() {
        if (!medicoAss->isDisp()) {
            medicoAss->setDisp(true);
            cout << "Prenotazione eliminata!\n";
        }
    }
};

class Clinica {
protected:
    string nomeC;
    Medico *medici[100]{};
    Paziente *pazienti[100]{};
    Prenotazione *prenotazioni[100]{};
    int numMedici = 0, numPazienti = 0, numPrenotazioni = 0;

public:
    Clinica(string nomeC) : nomeC(nomeC) {}

    void aggiungiMedico(Medico *med) {
        if (numMedici < 100) medici[numMedici++] = med;
    }

    void aggiungiPaziente(Paziente *p) {
        if (numPazienti < 100) pazienti[numPazienti++] = p;
    }

    void aggiungiPrenotazione(Prenotazione *pr) {
        if (numPrenotazioni < 100) prenotazioni[numPrenotazioni++] = pr;
    }

    void stampaClinica() const {
        cout << "Clinica: " << nomeC << endl;
        cout << "-- Medici --" << endl;
        for (int i = 0; i < numMedici; i++) medici[i]->stampaInfo();
        cout << "-- Pazienti --" << endl;
        for (int i = 0; i < numPazienti; i++) pazienti[i]->stampaInfo();
        cout << "-- Prenotazioni --" << endl;
        for (int i = 0; i < numPrenotazioni; i++) prenotazioni[i]->stampaDettagli();
    }
};

int main() {
    Clinica clinica("Clinica Salute");

    Medico *m1 = new Medico("Mario", "Rossi", "Cardiologo", 120.0);
    Medico *m2 = new Medico("Laura", "Verdi", "Dermatologo", 100.0);

    Paziente *p1 = new Paziente("Giulia", "Bianchi", 1234567890, "TS001");
    Paziente *p2 = new Paziente("Marco", "Neri", 9876543210, "TS002");

    Prenotazione *pr1 = new Prenotazione(7, 4, 2025, 10.30, m1, p1);
    Prenotazione *pr2 = new Prenotazione(8, 4, 2025, 11.00, m2, p2);

    clinica.aggiungiMedico(m1);
    clinica.aggiungiMedico(m2);
    clinica.aggiungiPaziente(p1);
    clinica.aggiungiPaziente(p2);
    clinica.aggiungiPrenotazione(pr1);
    clinica.aggiungiPrenotazione(pr2);

    pr1->conferma();
    pr2->conferma();

    clinica.stampaClinica();

    delete m1;
    delete m2;
    delete p1;
    delete p2;
    delete pr1;
    delete pr2;

    return 0;
}
