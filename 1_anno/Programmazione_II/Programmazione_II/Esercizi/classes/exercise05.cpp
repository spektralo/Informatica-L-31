#include<iostream>
using namespace std;

class Libro{
    private:
    string titolo;
    string autore;
    int anno_pub;

    public:
    Libro(){
        titolo = "";
        autore = "";
        anno_pub = 0;
    }

    string setTitolo(string newTitolo){
        titolo = newTitolo;
        return titolo;
    }

    string setAutore(string newAutore){
        autore = newAutore;
        return autore;
    }

    int setAnno(int newAnno){
        anno_pub = newAnno;
        return anno_pub;
    }

    void getInfo(){
        std::cout << "Titolo: " << titolo << "\nAutore: " << autore << "\nAnno pubblicazione: " << anno_pub << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Libro libro;
    libro.setTitolo("Harry Potter");
    libro.setAutore("J.K Rowling");
    libro.setAnno(2007);
    libro.getInfo();
    return 0;
}
