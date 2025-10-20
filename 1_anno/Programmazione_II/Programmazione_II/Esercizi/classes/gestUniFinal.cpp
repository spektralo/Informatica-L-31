#include<iostream>
using namespace std;

class Persona{
    protected:
    string nome, cognome;
    int eta;

    public:
    Persona(string nome, string cognome, int eta)
    :nome(nome),cognome(cognome),eta(eta){}

    Persona(string nome, string cognome)
    :nome(nome),cognome(cognome){}

    virtual ~Persona(){}
    virtual float getMedia() const = 0;

    string getNome()const{return nome;}
    string getCognome()const{return cognome;}
    int getEta()const{return eta;}

    void setNome(string n){nome = n;} void setCognome(string c){cognome = c;}
    void setEta(int e){eta = e;}

    virtual void stampaInfo()const{
        cout << "Nome: " << getNome() << ", Cognome: " << getCognome() << endl;
    }

    friend std::ostream &operator <<(std::ostream &os, Persona &pers){
        pers.stampaInfo();
        return os;
    }
};

class Studente:public Persona{
    protected:
    long matricola;
    string corso;
    float mediaVoti;

    public:
    Studente(string nome, string cognome, long matricola, string corso, float mediaVoti)
    :Persona(nome,cognome), matricola(matricola), corso(corso), mediaVoti(mediaVoti){}
    virtual ~Studente(){}

    long getMatricola()const{return matricola;} string getCorso()const{return corso;}
    float getMedia()const override{return mediaVoti;}

    void stampaInfo()const override{
        Persona::stampaInfo();
        cout << ", Matricola: " << getMatricola() <<", Corso: " 
        << getCorso() << ", Media: " << getMedia() << endl;
    }
};

class Docente:public Persona{
    protected:
    string insegnamento;
    float stipendio;

    public:
    Docente(string nome, string cognome, string insegnamento, float stipendio)
    :Persona(nome,cognome,eta), insegnamento(insegnamento), stipendio(stipendio){}
    virtual ~Docente(){}

    string getInsegnamento()const{return insegnamento;} 
    float getStipendio()const{return stipendio;}
    float getMedia()const override{return 0;}

    void stampaInfo()const override{
        Persona::stampaInfo();
        cout << ", Insegnamento: " << getInsegnamento() << ", Stipendio: " << getStipendio() << endl;
    }
};

class Universita{
    protected:
    string nomeUniversita;
    Persona **persone;
    int numPersone;

    public:
    Universita(string nomeUniversita, Persona **persone, int numPersone)
    :nomeUniversita(nomeUniversita), persone(persone), numPersone(numPersone){}


    string getNomeUni()const{return nomeUniversita;}

    void aggiungiPersona(Persona*prs, int &index){
        if(index < numPersone){
            persone[index] = prs;
            index++;
        }
    }

    void calcolaMedia(int &index){
        float mediaTot = 0;
        int conta = 0;
        
        for (int i = 0; i < index; i++)
        {
            if(persone[i]->getMedia() > 0){
            mediaTot += persone[i]->getMedia();
            conta++;
            }
        }
        cout << "Media Totale: " << mediaTot/conta << endl;
    }

    friend std::ostream &operator <<(std::ostream &os, Universita &uni){
        os << "Nome universita: " << uni.getNomeUni() <<
        ", n.Persone: " << uni.numPersone << ", Persone: " << endl;

        for (int i = 0; i < uni.numPersone && uni.persone[i] != nullptr; i++){
            os << i << ")" << *uni.persone[i] << endl;
        }
        return os;
    }
};

int main(){
    Persona *studenteUno = new Studente("Mario", "Rossi", 1000059, "L-31", 27.5);
    Persona *studenteDue = new Studente("Luca", "Bianchi", 842112, "L-17", 21.3);
    Persona *docenteUno = new Docente("Indiano", "Zappala", "Algebra", 1200.00);

    const int dim = 100;
    int index = 0;
    Persona* persone[dim] = {nullptr};
    Universita universita("UNICT", persone, 100);
    universita.aggiungiPersona(studenteUno,index);
    universita.aggiungiPersona(studenteDue,index);
    universita.aggiungiPersona(docenteUno,index);
    universita.calcolaMedia(index);
    cout << universita;
    
}