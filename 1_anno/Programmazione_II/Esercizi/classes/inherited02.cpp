#include<iostream>
using namespace std;

class Veicolo{

    public:
    Veicolo(){
        marca = "";
        annoProd = 0;
    }

    string setMarca(string newMarca){
        marca = newMarca;
        return marca;
    }

    protected:
    string marca;
    int annoProd;

};

class Automobile:public Veicolo{
    public:

    string setModello(string newModello){
        modello = newModello;
        return modello;
    }

    void getInfo(){
        std::cout << "Marca: " << marca  << "\nModello: " << modello << std::endl;
    }

    private:
    string modello;

};

int main(int argc, char const *argv[])
{
    Automobile macchina;
    macchina.setMarca("Nissan");
    macchina.setModello("350Z");
    macchina.getInfo();
    return 0;
}
