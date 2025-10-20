#include<iostream>
using namespace std;

class Macchina{
    private:
    string marca;
    string modello;
    int annoProd;

    public:
    Macchina(){
        marca = "";
        modello = "";
        annoProd = 0;
    }

    string setMarca(string newMarca){
        marca = newMarca;
        return marca;
    }

    string setModello(string newModello){
        modello = newModello;
        return modello;
    }

    int setAnno(int newAnno){
        annoProd = newAnno;
        return annoProd;
    }

    void getInfo(){
        std::cout << "Marca: " << marca << "\nModello: " << modello << "\nAnno produzione: " << annoProd << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Macchina macchina;
    macchina.setMarca("Alfa Romeo");
    macchina.setModello("Giulia");
    macchina.setAnno(2023);
    macchina.getInfo();
    return 0;
}
