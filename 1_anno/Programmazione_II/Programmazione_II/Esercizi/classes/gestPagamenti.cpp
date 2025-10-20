#include<iostream>
using namespace std;

class Pagamento{
    protected:
    double importo;
    string beneficiario;

    public:
    Pagamento(double importo, string beneficiario) : importo(importo), beneficiario(beneficiario){}
    ~Pagamento(){}

    virtual void effettuaPagamento() const = 0;
    void mostraDettagli() const{
        cout << importo << beneficiario << endl;
    }

    friend std::ostream& operator << (std::ostream& os, const Pagamento& p ){
        os <<"Pagamento in uscita:\n" <<  "Importo: " << p.importo << ", Beneficiario: " << p.beneficiario << endl;
        return os;
    }
};

class PagamentoBonifico : public Pagamento{
    protected:
    double IBAN;
    double commissione = (2/importo) * 100;

    public:
    PagamentoBonifico(double importo, string beneficiario, double IBAN) : Pagamento(importo,beneficiario), IBAN(IBAN){}
    ~PagamentoBonifico(){}

    virtual void effettuaPagamento() const override{
        double netto = this->importo - commissione;
        cout << "Importo netto: " << netto << endl;
    }
};

class PagamentoCarta: public Pagamento{
    protected:
    double numCarta;
    double commissione = (1.5/importo) * 100;

    public:
    PagamentoCarta(double importo, string beneficiario, double numCarta) : Pagamento(importo, beneficiario), numCarta(numCarta){}
    ~PagamentoCarta(){}

    virtual void effettuaPagamento() const override{
        double netto = this->importo - commissione;
        cout << "Importo netto: " << netto << endl;
    }
};


int main(){
    Pagamento* pagamentoUno = new PagamentoBonifico(1200, "Rossi", 10231391);
    cout << *pagamentoUno << endl;
    pagamentoUno->effettuaPagamento();
    cout <<"\n" << endl;

    Pagamento * pagamentoDue = new PagamentoCarta(1500, "Verdi", 53976800);
    cout << *pagamentoDue << endl;
    pagamentoDue->effettuaPagamento();
}