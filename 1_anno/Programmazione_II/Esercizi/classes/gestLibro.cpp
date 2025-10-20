#include<iostream>
using namespace std;

class Libro{
protected:
    string titolo, autore, anno;

public:
    Libro(string titolo, string autore, string anno)
    : titolo(titolo), autore(autore), anno(anno){}
    ~Libro(){}

    string getTitolo(){return titolo;}
    string getAutore(){return autore;}
    string getAnno(){return anno;}
    void stampa(){cout<<titolo<<autore<<anno<<endl;}
    virtual string genereLibro() const = 0;
};

class Romanzo

int main(){

}