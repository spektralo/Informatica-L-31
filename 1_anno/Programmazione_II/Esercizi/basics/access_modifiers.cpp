#include<iostream>
using namespace std;

class Persona{
    /*
    protected:
    PER LE CLASSI DERIVATE, POSSONO ACCEDERE AI METODI E ATTRIBUTI PUBLIC DELLA CLASSE CHE DERIVA
    */
    

    public:

    Persona(){
        nome = "nome";
        cognome = "cognome";
        eta = 0;
    }

    Persona(string nome, string cognome, int eta){
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }

    void presentati(){ 
    std::cout << "Ciao sono " << nome <<  cognome <<" e ho " << eta << " anni"<< std::endl;
    }

    private:    
    //gli attributi dell'oggetto devono essere sempre privati!
    string nome;
    string cognome;
    int eta;

};


int main(int argc, const char** argv) {

Persona generic;
Persona uno("Luca","Rossi", 25);

generic.presentati();
uno.presentati();

/*

std::cout << generic.nome <<std::endl; //poichè l'attributo nome è privato! importante
generic.nome = ""; //stesso principio, non possiamo modificarlo!
generic.cambiaNome(); se volessi modificare il valore dell'attributo (esempio); 

*/

return 0;
}