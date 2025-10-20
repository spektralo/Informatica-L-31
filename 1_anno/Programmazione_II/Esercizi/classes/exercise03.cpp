#include<iostream>
using namespace std;

class Studente{

    private:

    string nome;
    int matricola;
    int immatricolazione;

    public:

    Studente(){
        nome = "";
        matricola = 0;
        immatricolazione = 0;
    }

    void set(string newNome, int newMatricola, int newImmatricolazione){
        nome = newNome;
        matricola = newMatricola;
        immatricolazione = newImmatricolazione;
    }

   void getInfo(){
    std::cout << nome << matricola << immatricolazione << std::endl;
   }
   
};

int main(int argc, char const *argv[])
{
    Studente studente;
    studente.set("Luca",159692,2023);
    studente.getInfo();
    return 0;
}
