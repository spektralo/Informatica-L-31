#include<iostream>
using namespace std;

template<typename tmpl>

class Nodo {
protected:
	tmpl info;
	Nodo *next;
public:
	Nodo(){}
	~Nodo(){}
	Nodo ((tmpl data)){ info = data; next = NULL;} // costruttore
	tmpl getInfo(){ return info;} // Ottiene elemento
	void putInfo(tmpl data){ info = data;} // Assegna elemento
	Nodo *getNext(){ return next;} // Ottiene successivo
	void putNext( Nodo *p){ Seg = p;} // Assegna successivo
};


