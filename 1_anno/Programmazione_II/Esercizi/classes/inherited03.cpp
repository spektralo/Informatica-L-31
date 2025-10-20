#include<iostream>
using namespace std;

class Animale{
    public:

    Animale(){
        nome = "";
    }

    string setNome(string newNome){
        nome = newNome;
        return nome;
    }

    protected:
    string nome;
};

class Cane:public Animale{
    private:

    string razza;

    public:
    string setRazza(string newRazza){
        razza = newRazza;
        return razza;
    }

    void getInfo(){
        std::cout << "Nome: " << nome << "\nRazza: " << razza << std::endl;
    }

};

int main(int argc, char const *argv[]){
    Cane cane;
    cane.setNome("Alfredo");
    cane.setRazza("Bobboncino");
    cane.getInfo();

    return 0;
}