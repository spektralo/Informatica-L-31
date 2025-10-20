#include<iostream>
using namespace std;

class Persona{
    protected:
    string nome, cognome, dataNascita;

    public:
    Persona(string nome, string cognome)
    : nome(nome), cognome(cognome){}
    virtual ~Persona(){}

    string getNome()const{return nome;}
    string getCognome()const{return cognome;}

    virtual void stampa()const{
    cout <<"Nome: " << getNome() <<", Cognome: " << getCognome();}

     friend std::ostream &operator <<(std::ostream &os, Persona &pers){
        pers.stampa();
        return os;
     }  
};

class Dipendente:public Persona{
    protected:
    float salario;
    int annoAssunzione;

    public:
    Dipendente(float salario, int annoAssunzione)
    :salario(salario),annoAssunzione(annoAssunzione){}
    virtual ~Dipendente(){}

    float getSalario()const{return salario;} 
    int getAssunzione()const{return annoAssunzione;}

    float calcolaBonus(int annoCorrente){
    int bonus;
    for (int i = annoAssunzione; i < annoCorrente; i++){bonus+= 10;}
        bonus = (salario*bonus) / 100;
        return bonus;
    }

    void stampa()const override{
        Persona::stampa();
        cout << "Salario: " << getSalario() << "Data Assunzione" << getAssunzione;
    }
};

class Manager:public Dipendente{
    protected:
    string reparto;

    public:
    Manager(float salario, int annoAssunzione, string reparto)
    :Dipendente(salario,annoAssunzione),reparto(reparto){}
    virtual ~Manager(){}

    string getReparto()const{return reparto;}

    void stampa()const override{
        Persona::stampa();
        cout << "Salario: " << getSalario() << "Data Assunzione" << getAssunzione
         << ", Reparto: " << getReparto();
    }
};


int main(){

};