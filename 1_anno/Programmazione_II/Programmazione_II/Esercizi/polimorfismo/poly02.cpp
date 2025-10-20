#include <iostream>
#include <string>
using namespace std;

class Veicolo {
public:
    virtual void stampaInfo() const = 0;
    virtual void setCilindri(int cilindri) = 0;

    void setMarca(const string& newMarca) {
        marca = newMarca;
    }

    void setModello(const string& newModello) {
        modello = newModello;
    }

    virtual ~Veicolo() = default; // Distruttore virtuale

protected:
    string marca;
    string modello;
    int cilindri = 0; // Valore predefinito
};

class Automobile : public Veicolo {
public:
    void stampaInfo() const override {
        cout << "Marca: " << marca << "\nModello: " << modello 
             << "\nCilindri: " << cilindri << endl;
    }

    void setCilindri(int newCilindri) override {
        cilindri = newCilindri;
    }
};

class Moto : public Veicolo {
public:
    void setTipo(const string& newTipo) {
        tipo = newTipo;
    }

    void stampaInfo() const override {
        cout << "Marca: " << marca << "\nModello: " << modello
             << "\nTipo: " << tipo << "\nCilindri: " << cilindri << endl;
    }

    void setCilindri(int newCilindri) override {
        cilindri = newCilindri;
    }

private:
    string tipo;
};

int main() {
    Automobile macchina;
    macchina.setMarca("Citroen");
    macchina.setModello("C1");
    macchina.setCilindri(3);
    macchina.stampaInfo();

    cout << "\n" << endl;

    Moto motocicletta;
    motocicletta.setMarca("Kawasaki");
    motocicletta.setModello("Z800");
    motocicletta.setTipo("Naked");
    motocicletta.setCilindri(4);
    motocicletta.stampaInfo();

    return 0;
}
