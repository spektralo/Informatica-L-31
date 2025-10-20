#include<iostream>
using namespace std;

class Persona{
    
    public:

    Persona(){
        nome = "";
        cognome = "";
    }

    string setNome(){
        std::cout << "Inserisci il nome: ";
        std::cin >> nome;
        return nome;
    }

    protected:
    string nome;
    string cognome;
};

class Studente:public Persona{
    private:
    int matricola;

    public:
    int setMatricola(){
        std::cout << "Inserisci la matricola: ";
        std::cin >> matricola;
        return matricola;
    }

    void getInfo(){
        std::cout << "Nome: " << nome << "\nMatricola: " << matricola << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Studente studente;
    studente.setNome();
    studente.setMatricola();
    studente.getInfo();
    return 0;   
}
