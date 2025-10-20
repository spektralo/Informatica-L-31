#include<iostream>
using namespace std;

class Veicolo{
    protected:
    string nome;
    float max_s;

    public:
    Veicolo(string nome, float max_s) : nome(nome), max_s(max_s){};
    virtual void getInfo() = 0;
};

class Auto: public Veicolo{
    private:
    int posti;

    public:
    Auto(string nome, float max_s, int posti) : Veicolo(nome,max_s), posti(posti){};

    void getInfo() override{
        std::cout << "Nome: " << nome << "\nvelocita max: " << max_s << "\n posti: " << posti << std::endl;
    }
};


class Moto:public Veicolo{
    private:
    bool side;

    public:
    Moto(string nome, float max_s, bool side) : Veicolo(nome,max_s), side(side){};
     void getInfo() override{
        std::cout << "Nome: " << nome << "\nvelocita max: " << max_s << "\n sidecar: " << side << std::endl;
    }
};


class Camion:public Veicolo{
    private:
    float carico;

    public:
    Camion(string nome, float max_s, float carico) : Veicolo(nome,max_s), carico(carico){};

     void getInfo() override{
        std::cout << "Nome: " << nome << "\nvelocita max: " << max_s << "\n carico max: " << carico << std::endl;
    }
};


int main(int argc, char const *argv[])
{
    const int num_veicoli = 3;
    Veicolo *veicoli[num_veicoli];
    
    veicoli[0] = new Auto("Alfa Romeo",200,4);
    veicoli[1] = new Moto("Kawasaki",185,false);
    veicoli[2] = new Camion("Scania",130,2000);

    for (int i = 0; i < num_veicoli; i++)
    {
        veicoli[i]->getInfo();
         std::cout << "-----------------------------" << std::endl;
    }
    
    return 0;
}

































































/*
#include<iostream>
using namespace std;

class Persona{
    protected:
    string nome;
    int eta;

    public:
    Persona(string nome, int eta) : nome(nome), eta(eta){};

    virtual void getInfo(){
        std::cout <<"Nome: " << nome << "\neta: " << eta << std::endl;
    }
};

class Studente:public Persona{
    private:
    float media;

    public:
    Studente(string nome, int eta, float media) : Persona(nome, eta), media(media){};

    void getInfo() override{
        std::cout <<"Nome: " << nome << "\neta: " << eta  << "\nmedia: " << media << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Studente studente("Gianni",20,24.78);
    studente.getInfo();   
    return 0;
}
*/

















































/*
#include<iostream>
using namespace std;

class Employee{
    protected:
    string nome;
    float salario;

    public:

    Employee(string nome, float salario): nome(nome), salario(salario){};
    virtual void getInfo(){
        std::cout << nome << "\n" << salario << std::endl;
    }
};

class Developer: public Employee{
    protected:
    int exp;

    public:
    Developer(string nome, float salario, int exp) : Employee(nome,salario), exp(exp) {};
    
    void getInfo() override{
        std::cout << nome <<"\n"<< salario <<"\n" << exp << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Developer impiegato("Alberto",1399.99,2);
    impiegato.getInfo();
    return 0;
}

*/































/*
#include<iostream>
using namespace std;

template<typename tmpl>
class Shape{
    public:
    virtual tmpl calcArea() = 0;
};

template<typename tmpl>
class Rectangle:public Shape<tmpl> {

    private:
    tmpl width, height;

    public:
    Rectangle(tmpl width, tmpl height) : width(width), height(height) {};

    tmpl calcArea() override{
        std::cout << width * height << std::endl;
    }

};

template<typename tmpl>
class Circle: public Shape<tmpl>{
    private:
    tmpl raggio;

    public:
    Circle(tmpl raggio) : raggio(raggio){};

    tmpl calcArea() override{
        std::cout << 3.14 * raggio << std::endl;
    }
};

template<typename tmpl>
class Square: public Shape<tmpl>{
    private:
    tmpl lato,altezza;

    public:
    Square(tmpl lato, tmpl altezza) : lato(lato), altezza(altezza){};
    tmpl calcArea() override{
        std::cout << lato*lato << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Rectangle<int>rettangolo(2,3);
    Rectangle<float> rettangolo2(1.5,3.2);
    Circle<int> cerchio(3);
    Square<int> quadrato(2,4);

    rettangolo.calcArea();
    rettangolo2.calcArea();
    cerchio.calcArea();
    quadrato.calcArea();
    
    return 0;
}
*/





/*
#include<iostream>
using namespace std;

template <typename tmpl> 
class test{
    protected:
    tmpl x, y;

    public:
    test(){};

    tmpl sum(tmpl x, tmpl y){
        return x + y;
    }
};

int main(int argc, char const *argv[])
{
    test <int>integer;
    test <float>floats;

    integer.sum(10,20);
    floats.sum(10.32,8.92);
}
*/