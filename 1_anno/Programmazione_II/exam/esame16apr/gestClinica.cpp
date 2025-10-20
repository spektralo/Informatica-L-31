#include<iostream>
using namespace std;

class Persona{
    protected:
    string nome, cognome, codiceFiscale;

    public:
    Persona(string nome, string cognome, string codiceFiscale)
    :nome(nome),cognome(cognome),codiceFiscale(codiceFiscale){}
    ~Persona(){}

    string getNome()const{return nome;} string getCognome()const{return cognome;}
    string getCodiceF()const{return codiceFiscale;}

    virtual string getRuolo()const = 0;
    virtual int getPriorita()const{return 0;}
    
    virtual void stampaInfo(ostream &os)const{
        os << "Nome: " << getNome() << ", cognome: " << getCognome() 
        << ", codice fiscale: " << getCodiceF() << endl;
    }

    friend ostream &operator<<(ostream &os, Persona &pers){
        pers.stampaInfo(os);
        return os;
    }
};

class Paziente:public Persona{
    protected:
    string patologia;
    int priorita;

    public:
    Paziente(string nome, string cognome, string codiceFiscale, string patologia, int priorita)
    :Persona(nome,cognome,codiceFiscale),patologia(patologia),priorita(priorita){}
    ~Paziente(){}

    string getRuolo()const override{return "Paziente";}
    string getPatologia()const{return patologia;} int getPriorita()const override{return priorita;}

    void stampaInfo(ostream &os) const override{
        Persona::stampaInfo(os);
        os << ", patologia: " << getPatologia() << ", priorita: " << getPriorita() << endl; 
    }

    friend ostream &operator <<(ostream &os, Paziente &p){
        p.stampaInfo(os);
        return os;
    }
};

class Medico:public Persona{
    protected:
    string specializzazione;
    int anniEsp;

    public:
    Medico(string nome, string cognome, string codFiscale, string specializzazione,  int anniEsp)
    :Persona(nome,cognome,codFiscale),specializzazione(specializzazione),anniEsp(anniEsp){}
    virtual ~Medico(){}

    string getRuolo()const override{return "Medico";}
    string getSpecial()const{return specializzazione;} int getEsp()const{return anniEsp;}
    int getPriorita()const override{return 0;}
 
    void stampaInfo(ostream &os)const override{
        Persona::stampaInfo(os);
        os << ", specializzazione: " << getSpecial() << ", anni esperienza: " << getEsp() << endl;
    }

    friend ostream &operator <<(ostream &os, Medico &med){
        med.stampaInfo(os);
        return os;
    }
};

class Clinica{
    protected:
    string nomeClinica;
    Persona *persone[100]{};
    int numPersone = 0 ;

    public:
    Clinica(string nomeClinica):nomeClinica(nomeClinica){}
    ~Clinica(){}

    string getClinica()const{return nomeClinica;}
    void aggiungiPersona(Persona *p){
        if(numPersone < 100){
            persone[numPersone++] = p;
        }
        else {cout << "Numero massimo di persone raggiunto!";}
    }

    int mediaPriorita(){
        int media = 0;
        for (int i = 0; i < numPersone && persone[i]!=nullptr; i++)
        {
            if(persone[i]->getPriorita() > 0){
                media += persone[i]->getPriorita();
            }
        }
         media /= numPersone;
         return media;
    }

    int contaRuolo(string ruolo){
        int count = 0;
        for (int i = 0; i < numPersone && persone[i]!=nullptr; i++)
        {
            if (persone[i]->getRuolo() == ruolo)
            {
                count++;
            }
        }
        return count;
    }

    void stampaPersonale(ostream &os){
        os << "Clinica: " << getClinica() << "\nPersone: " << endl;
        for (int i = 0; i < numPersone && persone[i]!=nullptr; i++)
        {
            os << i + 1 << ")" << *persone[i] << endl;
        }
    }

    friend ostream &operator <<(ostream &os, Clinica &cl){
        cl.stampaPersonale(os);
        return os;
    }
};


    int main() {
        // Creo alcuni pazienti
        Paziente* p1 = new Paziente("Mario", "Rossi", "RSSMRA80A01H501U", "Polmonite", 1);
        Paziente* p2 = new Paziente("Luca", "Verdi", "VRDLUC95C10H501B", "Influenza", 3);
        Paziente* p3 = new Paziente("Giulia", "Bianchi", "BNCGLI90D20H501C", "Frattura", 2);
    
        // Creo alcuni medici
        Medico* m1 = new Medico("Francesca", "Neri", "NREFRC75E30H501Z", "Ortopedia", 15);
        Medico* m2 = new Medico("Stefano", "Russo", "RSSSTF68G15H501X", "Medicina Generale", 20);
    
        // Creo la clinica
        Clinica *clinica = new Clinica(("Clinica San Marco"));
    
        // Aggiungo persone alla clinica
        clinica->aggiungiPersona(p1);
        clinica->aggiungiPersona(p2);
        clinica->aggiungiPersona(p3);
        clinica->aggiungiPersona(m1);
        clinica->aggiungiPersona(m2);
    
        // Stampo le informazioni
        cout << *clinica;
    
        // Mostro quante persone per ruolo
        cout << "Numero di Pazienti: " << clinica->contaRuolo("Paziente") << endl;
        cout << "Numero di Medici: " << clinica->contaRuolo("Medico") << endl;
    
        // Mostro la priorità media
        cout << "Priorita media dei pazienti: " << clinica->mediaPriorita() << endl;
    
        return 0;
    }