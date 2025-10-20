#include<iostream>
using namespace std;

class Materiale{
    protected:
    int id;
    string titolo;

    public:
    Materiale(int id, string titolo):
    id(id),titolo(titolo){}
    virtual ~Materiale(){}

    int getID()const{return id;} string getTitolo()const{return titolo;}

    virtual void stampaInfo(ostream &os)const{
        os << "Id: " << getID() << ", titolo: " << getTitolo() << endl;
    }

    virtual bool prestabile()const = 0;

    friend ostream &operator <<(ostream &os, Materiale &m){
        m.stampaInfo(os);
        return os;
    }
};

class Libro:public Materiale{
    protected:
    string autore;
    int annoPub;

    public:
    Libro(int id, string titolo, string autore, int annoPub)
    :Materiale(id,titolo), autore(autore),annoPub(annoPub){}
    ~Libro(){}

    string getAutore()const{return autore;} int getAnnoPub()const{return annoPub;}

    bool prestabile()const override{
        if(getAnnoPub() > 1950){return true;}
        else return false;
    }

    void stampaInfo(ostream &os) const override{
        Materiale::stampaInfo(os);
        os << ", autore: " << getAutore() <<
        ", anno pubblicazione: " << getAnnoPub() << endl;
    }
};

class DVD:public Materiale{
    protected:
    int durataMin;

    public:
    DVD(int id, string titolo, int durataMin)
    :Materiale(id,titolo),durataMin(durataMin){}
    ~DVD(){}

    int getDurata()const{return durataMin;}

    bool prestabile()const override{
        if(getDurata() < 180){return true;}
        else return false;
    }

    void stampaInfo(ostream &os)const override{
        Materiale::stampaInfo(os);
        os << ", durata(min): " << getDurata() << endl;
    }
};

class Utente{
    protected:
    int codiceUtente;
    Materiale *prestiti[10]{};
    int numPrestiti = 0;

    public:
    Utente(int codiceUtente):codiceUtente(codiceUtente){}
    ~Utente(){}

    int getCodice()const{return codiceUtente;}

    void prestaMateriale(Materiale *mat){
        if(numPrestiti < 10 && mat->prestabile() == true){
            prestiti[numPrestiti++] = mat;
        }
        else{cout << "Limite di prestiti raggiunto o " << mat->getTitolo() << " non prestabile" << endl;}
    }

    void stampaUtente(ostream &os){
        os << "Utente: " << getCodice() << ", prestiti: " << endl;
        for (int i = 0; i < numPrestiti && prestiti[i]!=nullptr; i++)
        {
            os << i + 1 << ") " << *prestiti[i] << endl;
        }
    }

    friend ostream &operator<<(ostream &os, Utente &ut){
        ut.stampaUtente(os);
        return os;
    }
};

int main(){
    // Crea libri
    Libro* l1 = new Libro(1, "Il Nome della Rosa", "Umberto Eco", 1980);
    Libro* l2 = new Libro(2, "I Promessi Sposi", "Alessandro Manzoni", 1827);
    Libro* l3 = new Libro(3, "Harry Potter", "J.K. Rowling", 1998);

    // Crea DVD
    DVD* d1 = new DVD(4, "Interstellar", 169);
    DVD* d2 = new DVD(5, "Il Signore degli Anelli", 201);

    // Crea utenti
    Utente* u1 = new Utente(1001);
    Utente* u2 = new Utente(1002);

    // Assegna prestiti a u1
    u1->prestaMateriale(l1);  // Prestabile
    u1->prestaMateriale(l2);  // Non prestabile (anno < 1950)
    u1->prestaMateriale(d1);  // Prestabile
    u1->prestaMateriale(d2);  // Non prestabile (durata > 180)

    // Assegna prestiti a u2
    u2->prestaMateriale(l3);  // Prestabile
    u2->prestaMateriale(d1);  // Prestabile

    // Stampa informazioni utenti
    cout << *u1 << endl;
    cout << *u2 << endl;
}