#include<iostream>
using namespace std;

class Dipendente{
    protected:
    string nome;
    double stipendioBase;

    public:
    Dipendente(string nome, double stipendioBase) : nome(nome), stipendioBase(stipendioBase){}
    ~Dipendente(){}

    void mostraDettagli() const {cout << nome << stipendioBase << endl;}
    virtual void calcolaStipendio() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Dipendente& dip){
        os << "Nome: " << dip.nome << ", Stipendio " << dip.stipendioBase << endl;
        return os;
    }
};

class Impiegato : public Dipendente{
    protected:
    double quotaExtra = (10/stipendioBase) * 100;

    public:
    Impiegato(string nome, double stipendioBase) : Dipendente(nome,stipendioBase){};
    ~Impiegato(){};

    virtual void calcolaStipendio() const override{
        cout << stipendioBase + quotaExtra << endl;
    }
};

class Manager: public Dipendente{
    protected:
    int numProgetti;

    public:
    Manager(string nome, double stipendioBase, int numProgetti) : Dipendente(nome, stipendioBase), numProgetti(numProgetti){};
    ~Manager(){}

    virtual void calcolaStipendio() const override{
        double extra = 0;
        for (int i = 0; i <= numProgetti; i++)
        {
            extra+=500;
        }
        cout << stipendioBase + extra << endl;
    }
};

int main(){
    Dipendente* impiegatoUno = new Impiegato("Marco", 1200); 
    cout << *impiegatoUno << endl;
    impiegatoUno->calcolaStipendio();

    Dipendente* managerUno = new Manager("Andrea", 1600, 3);
    cout << *managerUno << endl;
    managerUno->calcolaStipendio();
}