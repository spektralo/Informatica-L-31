#include<iostream>
using namespace std;

class Dipendente{
    protected:
    string codFiscale, dataNascita;
    int pagaBase;

    public:
    Dipendente(string codFiscale, string dataNascita, int pagaBase) : codFiscale(codFiscale), dataNascita(dataNascita), pagaBase(pagaBase){}
    virtual ~Dipendente(){}

    string getCodice() const {return codFiscale;}
    void setCodice(string codice){ codFiscale = codice; }
    string getNascita() const{return dataNascita;}
    void setNascita(string nascita){ dataNascita = nascita;}
    int getPagaBase() const{return pagaBase;}

    virtual void stampa() const{cout << "Codice fiscale: " << getCodice() << ", Data di nascita" << getNascita() << ", Paga base: " << getPagaBase() << endl;} 

    friend std::ostream& operator <<(std::ostream& os, Dipendente& dip){
        dip.stampa();
        return os;
    }
};


class DipendenteOccasionale:public Dipendente{
    protected:
    string trimestre;
    int extra;      

    public:
    DipendenteOccasionale(string codFiscale, string dataNascita, int pagaBase, string trimestre, int extra) 
    : Dipendente(codFiscale, dataNascita, pagaBase), trimestre(trimestre), extra(extra){}
    virtual ~DipendenteOccasionale(){}

    string getTrimestre() const{return trimestre;}
    int getExtra() const{return extra;}

    void stampa() const override{
        Dipendente::stampa();
        cout << ", paga extra: " << getExtra() << ", trimestre: " << getTrimestre() << endl;
    }

};

class DipendenteIndeterminato:public Dipendente{
    protected:
    int bonusAnnuale;

    public:
    DipendenteIndeterminato(string codFiscale, string dataNascita, int pagaBase, int bonusAnnuale)
    :Dipendente(codFiscale, dataNascita, pagaBase), bonusAnnuale(bonusAnnuale){}
    virtual ~DipendenteIndeterminato(){}

    int getBonusAnnuale()const{return bonusAnnuale;}
    
};


class Azienda{
    protected:
    string p_iva, nomeAzienda;
    Dipendente** ptrDip;
    int dimAzienda = 10;

    public:
    Azienda(string p_iva, string nomeAzienda, Dipendente** ptrDip) : p_iva(p_iva), nomeAzienda(nomeAzienda), ptrDip(ptrDip){}
    ~Azienda(){}

    friend ostream &operator <<(ostream &os, const Azienda &azienda){
        os << "Nome Azienda: " << azienda.nomeAzienda << ", Partita Iva: " << azienda.p_iva << "\n Dipendenti: " << endl;
        for(int i = 0; i < azienda.dimAzienda && azienda.ptrDip[i] != nullptr; i++){
            os << i << ")" << *azienda.ptrDip[i] << endl;
        } 
        return os;
    }

    void aggiungiDipendenti(Dipendente* dip, int& index){
        if(index <  dimAzienda){
            ptrDip[index] = dip;
            index++;
        }
    }

    void calcolaStipendi(int &index){
        long stipendio = 0;
        for (int i = 0; i < index; i++)
        {
            stipendio += ptrDip[i]->getPagaBase();
        }
        cout << "Stipendio: " << stipendio << endl;
    }
};

int main(){
Dipendente*dip1= new Dipendente("AAABBB80T21C351Y", "02/02/1980", 1000);
Dipendente*dip2= new Dipendente("CCCDDD82C21C351Y", "21/04/1982", 1200);
Dipendente*dip3= new Dipendente("EEEFFF87C28C351Y", "29/8/1987", 1200);
Dipendente*occ1= new DipendenteOccasionale("HHH81R23C351Y", "29/8/1981", 800, "Gennaio-Febbraio-Marzo", 300);

const int dim= 10;
int index= 0;
Dipendente* arr[dim] = {nullptr};
Azienda az("AZIENDA A", "1234454545454", arr);
az.aggiungiDipendenti(dip1, index);
az.aggiungiDipendenti(dip2, index);
az.aggiungiDipendenti(dip3, index);
az.aggiungiDipendenti(occ1, index);
cout << az;
az.calcolaStipendi(index);
// Delete the dynamically allocated objects
for(int i= 0; i< index; ++i) {
delete arr[i];
    }
}   