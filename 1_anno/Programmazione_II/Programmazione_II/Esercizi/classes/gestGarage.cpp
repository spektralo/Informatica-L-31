#include<iostream>
using namespace std;

class Veicolo{
    protected:
    string modello;
    int anno;

    public:
    Veicolo(string modello, int anno) : modello(modello), anno(anno){};
    ~Veicolo(){};

    virtual void mostraDettagli() const = 0;
    virtual void calcolaImmatricolazione() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Veicolo& v) {
        os << "Modello: " << v.modello << ", Anno: " << v.anno;
        return os;
    }
};

class Auto : public Veicolo{
    protected:
    int porte;

    public:
    Auto(string modello, int anno, int porte) : Veicolo(modello, anno), porte(porte){};
    ~Auto(){};
    
    virtual void mostraDettagli() const override{
        cout << modello << anno << porte << endl;
    }

    virtual void calcolaImmatricolazione() const override{
        int costoBase = 200;
        for (int i = 0; i <= porte; i++)
        {
            costoBase+= 50;
        }

        cout << costoBase << endl;
    }
};

class Moto : public Veicolo{
    protected:
    bool carenata;

    public:
    Moto(string modello, int anno, bool carenata) : Veicolo(modello, anno), carenata(carenata){}
    ~Moto(){};

    virtual void mostraDettagli() const override{
        cout << modello << anno << carenata << endl;
    }

    virtual void calcolaImmatricolazione() const override{
        int costoBase = 150;
        if (carenata == true)
        {
            cout << costoBase + 100 << endl;

        }
        else cout << costoBase << endl;
        
    }
};



int main(){

    Moto motoUno("Kawasaki", 2012, false);
   //motoUno.calcolaImmatricolazione();

    Veicolo* autoDue = new Auto("Fiat Tipo", 2020, 3);
    cout << *autoDue  << endl;

    Auto autoUno("Fiat 500", 2012, 5);
    autoUno.mostraDettagli();
    autoUno.calcolaImmatricolazione();
    return 0;
}