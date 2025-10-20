#include<iostream>
#include<math.h>
using namespace std;

class Figura{
    public:

    Figura(){
        colore = "";
    }

    string setColore(string newColore){
        colore = newColore;
        return colore;
    }

    protected:
    string colore;
};

class Cerchio:public Figura{
    public:

        float setRaggio(float newRaggio){
            std::cout << "Raggio: " << newRaggio << std::endl;
            raggio = newRaggio;
            return raggio;
        }

        float calcolaArea(){
            area = 3.14 * pow(raggio,2);
            return area;
        }

    void getArea(){
        std::cout << "L'area del cerchio e': " << area << std::endl;
    }

    private:
        float area;
        float raggio;

};


int main(int argc, char const *argv[])
{
    Cerchio cerchio;
    cerchio.setColore("Rosso");
    cerchio.setRaggio(7);
    cerchio.calcolaArea();
    cerchio.getArea();
    return 0;
}
