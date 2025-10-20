#include<iostream>
using namespace std;

class Persona{

    public:

    string nome;
    string cognome;
    int eta;

    void presentati(){ 
    std::cout << "Ciao sono " << nome <<  cognome <<" e ho " << eta << " anni"<< std::endl;
    }

    //COSTRUTTORE PRINCIPALE
    Persona(){
        nome = "nome";
        cognome = "cognome";
        eta = 0;
    }

    //COSTRUTTORI ALTERNATIVI

    Persona(string nome, string cognome, int eta){
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }

    Persona(string nome, string cognome){
        this->nome = nome;
        this->cognome = cognome;
        eta = 1;
    }

    Persona(string nome){
        this->nome = nome;
        cognome = ""; //stringa vuota (" ")
        eta = 0; //non si possono assegnare valori tipo "null" agli int o float ecc...
    }

};


int main(int argc, const char** argv) {

Persona generic;
Persona uno("Luca","Rossi", 25);
Persona bebe("Marco","Bianchi");
Persona null("Gianmarco");

generic.presentati();
uno.presentati();
bebe.presentati();
null.presentati();

return 0;
}