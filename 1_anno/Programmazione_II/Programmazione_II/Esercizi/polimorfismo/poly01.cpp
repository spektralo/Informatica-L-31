#include <iostream>
using namespace std;

class Figura {
public:
    virtual float calcolaArea() = 0; // Pure virtual function
    virtual void getInfo() = 0;      // Pure virtual function
    virtual ~Figura() {}             // Virtual destructor
};

class Quadrato : public Figura {
private:
    float lato;

public:
    void setLato(float newLato) {
        lato = newLato;
    }

    float calcolaArea() override {
        return lato * lato;
    }

    void getInfo() override {
        cout << "L'area del quadrato e': " << calcolaArea() << endl;
    }
};

class Cerchio : public Figura {
private:
    float raggio;

public:
    void setRaggio(float newRaggio) {
        raggio = newRaggio;
    }

    float calcolaArea() override {
        return 3.14f * raggio * raggio;
    }

    void getInfo() override {
        cout << "L'area del cerchio e': " << calcolaArea() << endl;
    }
};

int main() {
    Quadrato quadrato;
    Cerchio cerchio;

    quadrato.setLato(5);
    quadrato.getInfo();

    cerchio.setRaggio(3);
    cerchio.getInfo();

    return 0;
}

