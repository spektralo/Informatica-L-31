#include<iostream>
using namespace std;

typedef int Tipo_elem;

class Nodo {
protected:
	Tipo_elem e;
	Nodo *Seg;
public:
	Nodo(){}
	~Nodo(){}
	Nodo (Tipo_elem x){ e = x; Seg = NULL;} // costruttore
	Tipo_elem get(){ return e;} // Ottiene elemento
	void put(Tipo_elem x){ e = x;} // Assegna elemento
	Nodo * get_suc(){ return Seg;} // Ottiene successivo
	void put_suc( Nodo *p){ Seg = p;} // Assegna successivo
};


