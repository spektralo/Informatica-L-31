#include<iostream>
using namespace std;

class Animale{
    public:
    virtual void emettiSuono() = 0;
    virtual ~Animale() = default;
};

class Cane:public Animale{
    public:

    void emettiSuono() override{
        std::cout << "Bau Bau" << std::endl;
    }

};

class Gatto:public Animale{
    public:

    void emettiSuono() override{
        std::cout << "Miao Miao" << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Animale *cane = new Cane;
    Animale *gatto = new Gatto;
    
    cane->emettiSuono();
    gatto->emettiSuono();

    return 0;
}
