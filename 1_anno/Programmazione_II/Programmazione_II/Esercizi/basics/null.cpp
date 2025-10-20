#include<iostream>
using namespace std;

class Persona{

    public:
    void presentati(string nome, int eta){  //premde paramtri passati alla funzione, ref 1;
    std::cout << "Ciao sono " << nome << " e ho " << eta << " anni"<< std::endl;  //OOP
    }

    /*
    void presentati(string nome,int eta){
    std::cout << "Ciao sono " << this->nome << " e ho " << this->eta << " anni"<< std::endl;  
    }
    prende attributi dell'oggetto (this->attributo) ref 2;
    */

    int eta;
    string nome;
    
};

int main(int argc, char *argv[]){
    
Persona generic;

generic.eta = 18;
generic.nome = "Alfonso Tame";
//generic.presentati(); ref 2
//generic.presentati("Marco",18); ref 1

// generic.presentati("Marco",22); PROCEDURALE

return 0;
}