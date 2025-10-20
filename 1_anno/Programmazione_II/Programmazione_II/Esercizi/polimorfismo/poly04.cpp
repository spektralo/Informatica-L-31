#include<iostream>
using namespace std;

class Dispositivo{
    public:
    virtual void accendi() = 0;
    virtual void spegni() = 0;

    void getInfo(){
        std::cout << "Il nome del dispositivo e': " << std::endl;
    }

    protected:
    string nomeDispositivo;
};

class Smartphone:public Dispositivo{
    public:

    void accendi() override{
        std::cout << "Il telefono si sta accendendo..." << std::endl;
    }

    void spegni() override{
        std::cout << "Il telefono si sta spegnendo..." << std::endl;
    }
};

class Tv:public Dispositivo{
    public:

    void accendi() override{
        std::cout <<"La Tv si sta accendendo..." << std::endl;
    }

    void spegni() override{
        std::cout <<"La Tv si sta spegnendo..." << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Dispositivo *arr[2];
    arr[0] = new Smartphone;
    arr[1] = new Tv;

    arr[0]->getInfo();
    arr[0]->accendi();
    arr[0]->spegni();

    arr[1]->getInfo();
    arr[1]->accendi();
    arr[1]->spegni();
    

    return 0;
}
