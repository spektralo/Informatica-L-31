#include<iostream>
using namespace std;

class Volo{
    protected:
    string codVolo, partenza, destinazione, tPartenza;

    public:
    Volo(string codVolo, string partenza, string destinazione, string tPartenza)
    :codVolo(codVolo),partenza(partenza),destinazione(destinazione),tPartenza(tPartenza){}
    ~Volo(){}

    string getCodVolo()const{return codVolo;} string getTpartenza()const{return tPartenza;}
    string getPartenza()const{return partenza;} string getDestinazione()const{return destinazione;}


    friend std::ostream &operator <<(std::ostream &os, Volo &v){
        os << "Codice: " << v.getCodVolo() << ", partenza: " << v.getPartenza() <<
        ", destinazione: " << v.getDestinazione() << ", orario partenza: " << v.getTpartenza();
        return os;
    }
};

class Passeggero{
    protected:
    string nome, cognome, passaporto;

    public:
    Passeggero(string nome, string cognome, string passaporto)
    :nome(nome), cognome(cognome), passaporto(passaporto){}
    ~Passeggero(){}

    string getNome()const{return nome;} string getCognome()const{return cognome;}
    string getPass()const{return passaporto;}

    

    friend std::ostream &operator <<(std::ostream &os, Passeggero &p){
        os << "Nome: " << p.getNome() << ", cognome: " << p.getCognome() 
        << ", passaporto: " << p.getPass(); 
        return os;
    }
};

class Prenotazione{
    protected:
    Volo *volo;
    Passeggero *passeggero;
    string dataPrenotazione, posto;

    public:
    Prenotazione(Volo *volo, Passeggero *passeggero, string dataPrenotazione, string posto)
    :volo(volo),passeggero(passeggero),dataPrenotazione(dataPrenotazione),posto(posto){}
    ~Prenotazione(){}

    friend std::ostream &operator <<(std::ostream &os, Prenotazione &p){
        os << "---- Prenotazione ----" << endl;
        cout << "Data: " << p.dataPrenotazione << ", Posto: " << p.posto << endl;
        cout << "Passeggero: " << *p.passeggero << endl;
        cout << "Volo: " << *p.volo << endl;
        return os;
    }
};

class Compagnia{
    protected:
    string nomeC;
    Volo *voli[100]{};
    Passeggero *passeggeri[150]{};
    Prenotazione *prenotazioni[150]{};
    int numVoli=0, numPasseggeri=0, numPrenotazioni=0;

    public:
    Compagnia(string nomeC):nomeC(nomeC){}
    ~Compagnia(){}

    void aggiungiVolo(Volo *volo) {
        if (numVoli < 100) {
            voli[numVoli] = volo;
            numVoli++;
        } else {
            cout << "Impossibile aggiungere altro volo: limite raggiunto." << endl;
        }
    }

    void aggiungiPasseggero(Passeggero *pass) {
        if (numPasseggeri < 150) {
            passeggeri[numPasseggeri] = pass;
            numPasseggeri++;
        } else {
            cout << "Impossibile aggiungere altro passeggero: limite raggiunto." << endl;
        }
    }
    
    void aggiungiPrenotazione(Prenotazione *prenot) {
        if (numPrenotazioni < 100) {
            prenotazioni[numPrenotazioni] = prenot;
            numPrenotazioni++;
        } else {
            cout << "Impossibile aggiungere altra prenotazione: limite raggiunto." << endl;
        }
    }
    
    friend std::ostream &operator<<(std::ostream &os, const Compagnia &comp) {
        os << "=== Compagnia Aerea: " << comp.nomeC << " ===\n";
        os << "\n--- Voli ---\n";
        for (int i = 0; i < comp.numVoli; i++) {
            if (comp.voli[i] != nullptr)
                os << i + 1 << ") " << *comp.voli[i] << endl;
        }
        os << "\n--- Passeggeri ---\n";
        for (int i = 0; i < comp.numPasseggeri; i++) {
            if (comp.passeggeri[i] != nullptr)
                os << i + 1 << ") " << *comp.passeggeri[i] << endl;
        }
        os << "\n--- Prenotazioni ---\n";
        for (int i = 0; i < comp.numPrenotazioni; i++) {
            if (comp.prenotazioni[i] != nullptr)
                os << i + 1 << ") " << *comp.prenotazioni[i] << endl;
        }
        return os;
    }
    
};

int main(){
    Compagnia compagnia("SkyWings");

    Volo *volo_uno = new Volo("1", "Roma", "Parigi", "10/01/2025");
    Volo *volo_due = new Volo("2","Milano", "Londra", "10/03/2025");

    Passeggero *passeggero_uno = new Passeggero("Mario","Rossi","1210");
    Passeggero *passeggero_due = new Passeggero("Luca","Gialli","8192");

    Prenotazione *prenotazione_uno = new Prenotazione(volo_uno, passeggero_uno, "3/10/2025", "12");
    Prenotazione *prenotazione_due = new Prenotazione(volo_due, passeggero_due, "3/03/2025", "81");

    compagnia.aggiungiVolo(volo_uno); compagnia.aggiungiVolo(volo_due);
    compagnia.aggiungiPasseggero(passeggero_uno); compagnia.aggiungiPasseggero(passeggero_due);
    compagnia.aggiungiPrenotazione(prenotazione_uno); compagnia.aggiungiPrenotazione(prenotazione_due);

    cout << compagnia;
    
}