#include<iostream>
using namespace std;

class Dipendente {
protected:
    string codFiscale;
    int pagaBase;
    int gg, mm, yy;

public:
    Dipendente(string codFiscale, int gg, int mm, int yy, int pagaBase)
        : codFiscale(codFiscale), gg(gg), mm(mm), yy(yy), pagaBase(pagaBase) {}
    virtual ~Dipendente() {}

    virtual long calcolaPaga(int mese) const {
        return pagaBase;  // Il calcolo della paga base, se non ci sono extra per il mese specifico.
    }

    string getCodFiscale() const { return codFiscale; }
    int getPagaBase() const { return pagaBase; }
    int getGG() const { return gg; }
    int getMM() const { return mm; }
    int getYY() const { return yy; }

    void setFiscale(string f) { codFiscale = f; }
    void setPagaBase(int p) { pagaBase = p; }
    void setGG(int giorno) { gg = giorno; }
    void setMM(int mese) { mm = mese; }
    void setYY(int anno) { yy = anno; }

    virtual void stampaInfo(ostream &os) const {
        os << "Codice fiscale: " << getCodFiscale() << ", paga base: " << getPagaBase()
           << ", data nascita: " << getGG() << "/" << getMM() << "/" << getYY() << endl;
    }

    friend ostream &operator<<(ostream &os, Dipendente &dip) {
        dip.stampaInfo(os);
        return os;
    }
};

class DipendenteOcc : public Dipendente {
protected:
    int meseUno, meseDue, meseTre;
    int pagaExtra;

public:
    DipendenteOcc(string codFiscale, int gg, int mm, int yy, int meseUno, int meseDue, int meseTre, int pagaBase, int pagaExtra)
        : Dipendente(codFiscale, gg, mm, yy, pagaBase), meseUno(meseUno), meseDue(meseDue), meseTre(meseTre), pagaExtra(pagaExtra) {}
    virtual ~DipendenteOcc() {}

    long calcolaPaga(int mese) const override {
        long stipendio = getPagaBase();
        // Aggiungi paga extra solo se il mese è uno dei seguenti: marzo (3), giugno (6), settembre (9), dicembre (12)
        if (mese == 3 || mese == 6 || mese == 9 || mese == 12) {
            stipendio += pagaExtra;
        }
        return stipendio;
    }

    int getMeseUno() const { return meseUno; }
    int getMeseDue() const { return meseDue; }
    int getMeseTre() const { return meseTre; }
    int getPagaExtra() const { return pagaExtra; }

    void stampaInfo(ostream &os) const override {
        Dipendente::stampaInfo(os);
        os << ", trimestri extra: " << getMeseUno() << "-" << getMeseDue() << "-" << getMeseTre()
           << ", extra: " << getPagaExtra() << endl;
    }

    friend ostream &operator<<(ostream &os, DipendenteOcc &dipOcc) {
        dipOcc.stampaInfo(os);
        return os;
    }
};

class Azienda {
protected:
    string partitaIva, nomeAz;
    Dipendente* dipendenti[50]{};
    int numDipendenti = 0;

public:
    Azienda(string partitaIva, string nomeAz)
        : partitaIva(partitaIva), nomeAz(nomeAz) {}

    ~Azienda() {
        for (int i = 0; i < numDipendenti; i++) {
            delete dipendenti[i];
        }
    }

    string getPiva() const { return partitaIva; }
    string getNomeAz() const { return nomeAz; }

    void aggiungiDipendente(Dipendente* dip) {
        if (numDipendenti < 50) {
            dipendenti[numDipendenti++] = dip;
        } else {
            cout << "Capacità massima raggiunta!" << endl;
        }
    }

    void calcolaStipendio(int mese) {
        long stipendioTot = 0;
        for (int i = 0; i < numDipendenti; i++) {
            stipendioTot += dipendenti[i]->calcolaPaga(mese);
        }
        cout << "La paga totale per il mese " << mese << " è: " << stipendioTot << " euro" << endl;
    }

    void calcolaPremio(int annoCorr) {
        long premioTotale = 0;
        for (int i = 0; i < numDipendenti; i++) {
            int eta = annoCorr - dipendenti[i]->getYY();
            if (eta >= 40) {
                // Calcolare il premio (5% della paga base)
                long premio = dipendenti[i]->getPagaBase() + (dipendenti[i]->getPagaBase() * 5) / 100;
                premioTotale += premio;
            }
        }
        cout << "Premio totale per i dipendenti con almeno 40 anni nel 2023: " << premioTotale << " euro" << endl;
    }

    friend ostream &operator<<(ostream &os, Azienda &az) {
        os << "Partita IVA: " << az.getPiva() << ", Nome azienda: " << az.getNomeAz() << endl;
        for (int i = 0; i < az.numDipendenti; i++) {
            os << i + 1 << ")" << *az.dipendenti[i] << endl;
        }
        return os;
    }
};

int main() {
    Dipendente* dipendenteUno = new Dipendente("ABC123", 2, 2, 1980, 1000);
    Dipendente* dipendenteDue = new Dipendente("DEF456", 21, 4, 1982, 1200);
    Dipendente* dipendenteTre = new Dipendente("GHI789", 29, 8, 1987, 1200);
    Dipendente* dipendenteQuattro = new DipendenteOcc("JKL000", 29, 8, 1981, 2, 6, 12, 800, 300);

    Azienda* azienda = new Azienda("123456", "Il Cristo");
    azienda->aggiungiDipendente(dipendenteUno);
    azienda->aggiungiDipendente(dipendenteDue);
    azienda->aggiungiDipendente(dipendenteTre);
    azienda->aggiungiDipendente(dipendenteQuattro);
    
    cout << *azienda;
    azienda->calcolaStipendio(3);  // Calcola stipendio per marzo
    azienda->calcolaStipendio(6);  // Calcola stipendio per giugno
    azienda->calcolaStipendio(9);  // Calcola stipendio per settembre
    azienda->calcolaStipendio(12); // Calcola stipendio per dicembre
    azienda->calcolaPremio(2023);  // Calcola il premio per i dipendenti con almeno 40 anni nel 2023
}


//Mia versione
/*
#include<iostream>
using namespace std;

class Dipendente{
    protected:
    string codFiscale;
    int pagaBase;
    int gg, mm,yy;

    public:
    Dipendente(string codFiscale ,int gg, int mm, int yy, int pagaBase)
    :codFiscale(codFiscale),gg(gg),mm(mm),yy(yy),pagaBase(pagaBase){}
    virtual ~Dipendente(){}

    virtual long calcolaPaga(int mese) const {
        return pagaBase;  
    }

    string getCodFiscale()const{return codFiscale;} int getPagaBase()const{return pagaBase;}
    int getGG()const{return gg;} int getMM()const{return mm;} int getYY()const{return yy;}

    void setFiscale(string f){codFiscale = f;} void setPagaBase(int p){pagaBase = p;}
    void setGG(int giorno){gg = giorno;} void setMM(int mese){mm = mese;} 
    void setYY(int anno){yy = anno;}

    virtual void stampaInfo(ostream &os)const{
        os <<  "Codice fiscale:" << getCodFiscale() <<", paga base: " << getPagaBase()  
        << ", data nascita: " << getGG() << "/" << getMM() << "/" << getYY() << endl;
    }

    friend ostream &operator <<(ostream &os, Dipendente &dip){
        os << "Codice fiscale:" << dip.getCodFiscale() <<", paga base: " << dip.getPagaBase()  
        << ", data nascita: " << dip.getGG() << "/" << dip.getMM() << "/" << dip.getYY() << endl;
        return os;   
    }
};

class DipendenteOcc:public Dipendente{
    protected:
    int meseUno, meseDue, meseTre;
    int pagaExtra;

    public:
    DipendenteOcc(string codFiscale ,int gg, int mm, int yy, int meseUno, int meseDue, int meseTre, int pagaBase, int pagaExtra)
    :Dipendente(codFiscale, pagaBase, gg, mm, yy), meseUno(meseUno), meseDue(meseDue), meseTre(meseTre), pagaExtra(pagaExtra){}
    virtual ~DipendenteOcc(){}

     long calcolaPaga(int mese) const override {
        long stipendio = getPagaBase();
        if(mese == 3 || mese == 6 || mese == 12 || mese == 9 ){
            stipendio += pagaExtra;
        }
        return stipendio;
    }

    int getMeseUno()const{return meseUno;} int getMeseDue()const{return meseDue;}
    int getMeseTre()const{return meseTre;} int getPagaExtra()const{return pagaExtra;}


    void stampaInfo(ostream &os)const override{
        Dipendente::stampaInfo(os);
        os << ", trimestri extra: "<< getMeseUno() << "-" << getMeseDue()
        << "-" << getMeseTre() << ", extra: " << getPagaExtra() << endl;
    }
    
    friend ostream &operator <<(ostream &os, DipendenteOcc &dipOcc){
        dipOcc.stampaInfo(os);
        return os;
    }
};

class Azienda {
    protected:
        string partitaIva, nomeAz;
        Dipendente* dipendenti[50]{};
        int numDipendenti = 0;
    
    public:
        Azienda(string partitaIva, string nomeAz)
            : partitaIva(partitaIva), nomeAz(nomeAz) {}
    
        ~Azienda() {
            for (int i = 0; i < numDipendenti; i++) {
                delete dipendenti[i];
            }
        }

        string getPiva()const{return partitaIva;} string getNomeAz()const{return nomeAz;}
    
        void aggiungiDipendente(Dipendente* dip) {
            if (numDipendenti < 50) {
                dipendenti[numDipendenti++] = dip;
            } else {
                cout << "Capacità massima raggiunta!" << endl;
            }
        }
    
        void calcolaStipendio(int mese) {
            long stipendioTot = 0;
            for (int i = 0; i < numDipendenti; i++) {
                stipendioTot += dipendenti[i]->calcolaPaga(mese);
            }
            cout << "La paga totale per il mese " << mese << " è: " << stipendioTot << " euro" << endl; 
        }

        void calcolaPremio(int annoCorr){
            int premio = 0;
            for (int i = 0; i < numDipendenti; i++)
            {
                if( (annoCorr - dipendenti[i]->getYY()) < 40){
                premio = (dipendenti[i]->getPagaBase()) + (dipendenti[i]->getPagaBase() * 5) / 100;
                }
            }
            cout << "Premio di: " << premio << endl;
        }

        friend ostream &operator <<(ostream &os, Azienda &az){
            os  << "Partita IVA: " << az.getPiva() << "Nome azienda: " << az.getNomeAz();
            for (int i = 0; az.numDipendenti; i++)
            {
                os << i << ")" << *az.dipendenti[i] << endl;
            }
            return os;
        }
};

int main(){

    Dipendente *dipendenteUno = new Dipendente("ABC123",2,2,1980,1000);
    Dipendente *dipendenteDue = new Dipendente("DEF456",21,4,1982,1200);
    Dipendente *dipendenteTre = new Dipendente("GHI789",29,8,1987,1200);
    Dipendente *dipendenteQuattro = new DipendenteOcc("JKL000",29,8,1981,2,6,12,800,300);

    Azienda *azienda = new Azienda("123456", "Il cristo");
    azienda->aggiungiDipendente(dipendenteUno);
    azienda->aggiungiDipendente(dipendenteDue);
    azienda->aggiungiDipendente(dipendenteTre);
    azienda->aggiungiDipendente(dipendenteQuattro);
    cout << *azienda;
    azienda->calcolaPremio(2023);
}
*/