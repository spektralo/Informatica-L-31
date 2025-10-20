#include<iostream>
using namespace std;

class Persona{

    public:

    void presentati(){ 
    std::cout << "Ciao sono " << nome <<  cognome <<" e ho " << eta << " anni"<< std::endl;
    }

     Persona(){
        nome = "Luca";
        cognome = "Argento";
        eta = 20;
    }

        Persona(string nome, string cognome){
        this->nome = nome;
        this->cognome = cognome;
    }
    
    string nome;
    string cognome;
    int eta;

    private:
    /*
    quando si hanno classi derivate, bisogna tenere a mente che esse non possono
    accedere alla sezione private della classe da cui derivano
    */

};


class Studente: public Persona{
    //troviamo attributi e metodi ereditati da Persona nella sezione Public, in questo caso
    
    //altri dati della classe:
    public:

    /*nel caso si abbia un costruttore che non sia quello di default, dobbiamo
    aggiungerlo nella classe derivata: */
    Studente(string nome,string cognome, string classe) : Persona(nome, cognome){
        this->classe = classe;
    }

    //OverRide del metodo "presentati"
    void presentati(){
        std::cout << "Ciao sono "<< nome  << " della classe " << classe << std::endl;
    }

    private:
    string classe = "5^A";

};

int main(int argc, const char** argv) {

Studente studente_uno("Luca","Rossi","3^B"); //costruttore con nome ereditato e classe aggiunta
studente_uno.presentati();//overRide del metodo derivato

return 0;
}
