#include<iostream>
using namespace std;

class Veicolo{
    protected:
    string modello;
    string targa;
    float prezzoG;

    public:
    Veicolo(string modello, string targa, float prezzoG)
    :modello(modello),targa(targa),prezzoG(prezzoG){
        if(prezzoG < 0) { // Validazione prezzoG
            cout << "Errore: il prezzo giornaliero non puo' essere negativo!" << endl;
            prezzoG = 0;
        }
    }
    virtual ~Veicolo(){}

    string getModello()const{return modello;}
    string getTarga()const{return targa;}
    float getPrezzoG()const{return prezzoG;}

    void setModello(string m){modello = m;}
    void setTarga(string t){targa = t;} // Errore: Targa deve essere di tipo stringa
    void setPrezzoG(float p){ 
        if(p < 0) {
            cout << "Errore: il prezzo giornaliero non puo' essere negativo!" << endl;
            p = 0;
        }
        prezzoG = p;
    }

    virtual void stampaInfo(ostream &os)const{
        os << "Modello: " << getModello() << ", targa: " << getTarga()
        << ", prezzo giornaliero: " << getPrezzoG() << endl;
    }

    virtual float calcolaCosto(int giorni)const{
        return getPrezzoG() * giorni;
    }

    friend ostream &operator <<(ostream &os, Veicolo &v){
        v.stampaInfo(os);
        return os;
    }
};

class Auto: public Veicolo{
    protected:
    int numPorte;

    public:
    Auto(string modello, string targa, float prezzoG, int numPorte)
    :Veicolo(modello, targa, prezzoG), numPorte(numPorte){}

    int getNumPorte()const{return numPorte;}

    float calcolaCosto(int giorni)const override{
        float costo = getPrezzoG() * giorni;
        if (giorni >= 14) {
            costo -= 30; // Sconto di 30 se il noleggio è di 14 o più giorni
        }
        return costo;
    }

    void stampaInfo(ostream &os)const override{
        Veicolo::stampaInfo(os); // Chiamata alla stampaInfo della classe base
        os << ", numero porte: " << getNumPorte() << endl;
    }

    friend ostream &operator <<(ostream &os, Auto &aut){
        aut.stampaInfo(os);
        return os;
    }
};

class Camion: public Veicolo{
    protected:
    float maxCarico;

    public:
    Camion(string modello, string targa, float prezzoG, float maxCarico)
    :Veicolo(modello, targa, prezzoG), maxCarico(maxCarico){}

    float getMaxCarico()const{return maxCarico;}

    float calcolaCosto(int giorni)const override{
        float costo = getPrezzoG() * giorni;
        if (maxCarico > 2000) {
            costo += 200; // Aggiunta di un costo extra se il carico massimo supera 2000
        }
        return costo;
    }

    void stampaInfo(ostream &os)const override{
        Veicolo::stampaInfo(os); // Chiamata alla stampaInfo della classe base
        os << ", carico massimo: " << getMaxCarico() << " kg" << endl;
    }

    friend ostream &operator<<(ostream &os, Camion &cam){
        cam.stampaInfo(os);
        return os;
    }
};

class Cliente{
    protected:
    string cognome;
    Veicolo *noleggiato;

    public:
    Cliente(string cognome, Veicolo *noleggiato):cognome(cognome),noleggiato(noleggiato){}

    ~Cliente(){
        delete noleggiato;
    }


    string getCognome()const{return cognome;}

    float calcolaTot(int giorni){
        float tot = noleggiato->calcolaCosto(giorni);
        cout << "Prezzo totale per " << giorni << " giorni: " << tot << endl; 
        return tot;
    }

    void stampaInfo(ostream &os)const{
        os << "Cognome: " << getCognome() << "Veicolo noleggiato: " << *noleggiato;
    }
};

class ServizioNoleggio{
    protected:
    string nomeDitta;
    Veicolo *veicoli[50]{};
    Cliente *clienti[20]{};
    int numVeicoli = 0, numClienti = 0;

    public:
    ServizioNoleggio(string nomeDitta):nomeDitta(nomeDitta){}

    virtual ~ServizioNoleggio(){
        for (int i = 0; i < numVeicoli; i++){
            delete veicoli[i];
        }
    }

    string getDitta()const{return nomeDitta;}
        
    void aggiungiVeicolo(Veicolo *v){
        if(numVeicoli < 50){
            veicoli[numVeicoli++] = v; 
        }
        else {
            cout << "Parco veicoli pieno!" << endl;
        }
    }

    void aggiungiCliente(Cliente *cl){
        if(numClienti < 20){
            clienti[numClienti++] = cl;
        }
        else {
            cout << "Limite massimo di clienti raggiunto!" << endl;
        }
    }

    float calcolaTotNoleggio(int giorni) const {
        float totNoleggio = 0;
        for (int i = 0; i < numVeicoli; i++){
            if (veicoli[i] != nullptr) {
                totNoleggio += veicoli[i]->calcolaCosto(giorni);
            }
        }
        cout << "Totale costo noleggio del parco per " << giorni << " giorni: " << totNoleggio << endl;
        return totNoleggio;
    }

    friend ostream &operator<<(ostream &os, ServizioNoleggio *serv){
        os << "Ditta: " << serv->getDitta() << ", parco veicoli:" << endl;
        for (int i = 0; i < serv->numVeicoli; i++){
            if (serv->veicoli[i] != nullptr) {
                os << i + 1 << ") ";
                serv->veicoli[i]->stampaInfo(os);
            }
            /*
             os << "Clienti: " << endl;
            for (int i = 0; i < serv->numClienti; i++)
            {
                os << i +1 << ")";
                serv->clienti[i]->stampaInfo(os);
            }
            
            */
           
        }
        return os;
    }
};

int main(){
    ServizioNoleggio *ditta = new ServizioNoleggio("Calcagno");
    Auto *autoUno = new Auto("Fiat 500", "1234ABCD", 20, 5);
    Camion *camionUno = new Camion("Volvo", "98AD84A", 50, 3000); 
    Cliente *clienteUno = new Cliente("Jalo", autoUno);

    ditta->aggiungiVeicolo(autoUno);
    ditta->aggiungiVeicolo(camionUno);
    ditta->aggiungiCliente(clienteUno);

    cout << ditta;
    //cout << camionUno;
    //cout << autoUno;
    //clienteUno->calcolaTot(3);
    //ditta->calcolaTotNoleggio(5);
}
