#include<iostream>
using namespace std;

class Rettangolo{

    public:

    Rettangolo(){
        base = 0;
        altezza = 0;
    }

    void set(){
        std::cout << "Inserisci la base: " << std::endl;
        std::cin >> base;
        std::cout << "Inserisci l'altezza: " << std::endl;
        std::cin >> altezza;
    }

    void calcolaArea(){
        area = base * altezza;
        std::cout << "L'area del rettangolo è: " << area << "cm" << std::endl;
    }

    void calcolaPerimetro(){
        perimetro = (base + altezza) * 2;
         std::cout << "Il perimetro del rettangolo è: " << perimetro << "cm" << std::endl;
    }

    private:
    float area;
    float perimetro;
    float base;
    float altezza;

};


int main(int argc, const char** argv) {

Rettangolo rettangolo;
rettangolo.set();
rettangolo.calcolaArea();
rettangolo.calcolaPerimetro();

return 0;
}