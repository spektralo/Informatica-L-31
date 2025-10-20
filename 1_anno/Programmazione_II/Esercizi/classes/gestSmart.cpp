#include<iostream>
using namespace std;

class DispositivoSmart{
    protected:
    string nome;
    bool stato;

    public:
    DispositivoSmart(string nome, bool stato) : nome(nome), stato(stato){}
    ~DispositivoSmart(){}

    virtual void eseguiAzione() = 0;
    void accendi(){stato = true;}
    void spegni(){stato = false;}
    void mostraStato() {
        if(stato == true){cout << "Stato corrente: acceso";}
            else{cout << "Stato corrente: spento ";
        }
    }

    virtual void stampaInfo() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const DispositivoSmart& d) {
        os << "Nome: " << d.nome << ", Stato: " << (d.stato ? "Acceso" : "Spento");
        return os;
    }    
};

class Lampada:public DispositivoSmart{
    protected:
    int luminosita;

    public:
    Lampada(string nome, bool stato, int luminosita) : DispositivoSmart(nome,stato), luminosita(luminosita){}
    ~Lampada(){}

    void cambiaLuminosita(int val){
        if(val < 0 || val > 100){throw runtime_error("Impossibile");}
        luminosita = val;
    }

    virtual void stampaInfo() const override{
        cout << nome << luminosita << endl;
    }

    virtual void eseguiAzione() override{
        int r;
        cout << "Inserisci luminosita: " << endl;
        cin >> r;

        if(r < 0 || r > 100){throw runtime_error("Impossibile");}

        luminosita = r;     
    }


};

class Termostato:public DispositivoSmart{
    protected:
    double temperatura;

    public:
    Termostato(string nome, bool stato, double temperatura) : DispositivoSmart(nome,stato), temperatura(temperatura){}
    ~Termostato(){}

    void cambiaTemperatura(int temp){
        if(temp < 0 || temp > 60){throw runtime_error("Impossibile");}
        temperatura = temp;
    }

    virtual void eseguiAzione() override{
        double r;
        cout << "Inserisci una temperatura: " << endl;
        cin >> r;
        temperatura = r;  
    }

    virtual void stampaInfo() const override{
        cout << nome << temperatura << endl;
    }
};

class Serratura:public DispositivoSmart{
    protected:
    bool bloccata;

    public:
    Serratura(string nome, bool stato, bool bloccata) : DispositivoSmart(nome, stato), bloccata(bloccata){}
    ~Serratura(){}

    void blocca(){bloccata = true;}
    void sblocca(){bloccata = false;}

    virtual void eseguiAzione() override{
        int r;
        cout << "Premi 1 per bloccare e 2 per sbloccare" << endl;
        cin >> r;
        if( r == 1){blocca();}
            else if(r == 2){sblocca();}
    }
    virtual void stampaInfo() const override{
        cout << nome << bloccata << endl;
    }
};

int main(){
    
    DispositivoSmart* lampada = new Lampada("lamp", true, 80);
    cout << *lampada;
    lampada->eseguiAzione();
    lampada->stampaInfo();
    
    DispositivoSmart* termostato = new Termostato("termos", true, 30.00);
    cout << *termostato;
    termostato->eseguiAzione();
    termostato->stampaInfo();


    return 0;
}