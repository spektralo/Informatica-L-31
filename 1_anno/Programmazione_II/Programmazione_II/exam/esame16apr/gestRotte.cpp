#include<iostream>
using namespace std;

class Veicolo{
    protected:
    int codice;
    int ritardo;

    public:
    Veicolo(int codice, int ritardo)
    :codice(codice),ritardo(ritardo){}
    virtual ~Veicolo(){}

    int getCodice()const{return codice;} 
    virtual int getRitardo()const = 0;

    virtual void stampaInfo(ostream &os){
        os << getCodice() << ", ritardo: " << getRitardo() << " min" << endl;
    }

    friend ostream &operator <<(ostream &os, Veicolo &v){
        v.stampaInfo(os);
        return os;
    }
};

class Treno:public Veicolo{

    public:
    Treno(int codice, int ritardo)
    :Veicolo(codice,ritardo){}
    virtual ~Treno(){}

    int getRitardo()const override{return 10;}

};

class Camion:public Veicolo{

    public:
    Camion(int codice, int ritardo)
    :Veicolo(codice,ritardo){}
    virtual ~Camion(){}

    int getRitardo()const override{return 20;}
    
};


class Aereo:public Veicolo{

    public:
    Aereo(int codice, int ritardo)
    :Veicolo(codice,ritardo){}
    virtual ~Aereo(){}

    int getRitardo()const override{return ritardo;}
    
};


class Citta{
    protected:
    string nomeCitta;
    int tStazionamento;

    public:
    Citta(string nomeCitta, int tStazionamento)
    :nomeCitta(nomeCitta),tStazionamento(tStazionamento){}
    virtual ~Citta(){}

    string getNomeCitta()const{return nomeCitta;} 

    int getStazionamento()const{return tStazionamento;}

    void stampaInfo(ostream &os)const{
        os << getNomeCitta() 
        << ", stazionamento: " << getStazionamento() ;
    }

    friend ostream &operator <<(ostream &os, Citta &c){
        c.stampaInfo(os);
        return os;
    }
};


class RottaCommerciale{
    protected:
    int codiceRotta;
    Citta *cittaPercorse[4]{};
    Veicolo *veicoloAssociato;
    int numCitta = 0;

    public:
    RottaCommerciale(int codiceRotta)
    :codiceRotta(codiceRotta){}
    ~RottaCommerciale(){}

    int getCodiceRotta()const{return codiceRotta;}

    void checkMezzo(){
        cout << "\nIl mezzo associato alla rotta " << getCodiceRotta()
        << " e' il numero " << veicoloAssociato->getCodice();
    }

    void aggiungiCitta(Citta *c){
        if(numCitta < 4){
            cittaPercorse[numCitta++] = c;
        }
        else {cout << "Città percorse sufficienti!";}
    }

    void aggiungiVeicolo(Veicolo *v){
        veicoloAssociato = v;
    }

    void stampaRotta(ostream &os){
        os << "\nCodice rotta: " << getCodiceRotta() << ", citta percorse: ";
        for (int i = 0; i < numCitta && cittaPercorse[i]!=nullptr; i++)
        {
            os << "\n" << i + 1 << ") " << *cittaPercorse[i] << " minuti";
        }
            os << "\nVeicolo associato: " << veicoloAssociato->getCodice() << endl;
    }

    int getTotPercorrenza(){
        int totale = 0;
        for (int i = 0; i < numCitta && cittaPercorse[i] != nullptr; i++)
        {
            totale += cittaPercorse[i]->getStazionamento() * (1 + veicoloAssociato->getRitardo() / 100.0);
        }
        cout << "\nTempo totale di percorrenza: " << totale << " minuti";
        return totale;
    }    

    friend ostream &operator <<(ostream &os, RottaCommerciale &rot){
        rot.stampaRotta(os);
        return os;
    }
};

int main(){
    Veicolo *aereo = new Aereo(123, 0);
    //Veicolo *camion = new Camion(456, 20);
    //Veicolo *treno = new Treno(789, 10);

    //Citta *roma = new Citta("Roma", 60);
    Citta *milano = new Citta("Milano", 30);
    Citta *catania = new Citta("Catania", 120);
    //Citta *bologna = new Citta("Bologna", 45);

    RottaCommerciale *rottaUno = new RottaCommerciale(886);
    rottaUno->aggiungiCitta(catania);
    rottaUno->aggiungiCitta(milano);
    rottaUno->aggiungiVeicolo(aereo);

    cout << *rottaUno;
    rottaUno->checkMezzo();
    rottaUno->getTotPercorrenza();
};