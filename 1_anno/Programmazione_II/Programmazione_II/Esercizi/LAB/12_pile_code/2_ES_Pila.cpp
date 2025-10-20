/* Copiare il contenuto di una pila in un'altra. 
*/

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

class Pila {
protected:
	Nodo *p;
public:
	Pila(){p = NULL;} // costruttore
	Pila (const Pila&); // costruttore di copia
	~Pila();
	bool vuota(){ return !p;}
	Tipo_elem Top(){ if (p) return p->get();}
	void Push( Tipo_elem e);
	void Cancella();
	Tipo_elem Pop();
};

Tipo_elem Pila::Pop() {
	Tipo_elem e;
	e = Top();
	Cancella();
	return e;
}

Pila:: ~Pila() {
	Nodo *paux;
	while(p != 0) {
		paux = p;
		p = p->get_suc();
		delete paux;
	}
}

void Pila::Cancella() {
	Nodo *paux;
	if(p) {
		paux = p;
		p = p->get_suc();
		delete paux;
		}
}

void Pila::Push(Tipo_elem e) {
	Nodo *aux;
	aux = new Nodo(e);
	if( p )
	aux->put_suc(p);
	p = aux;
}


int main(int argc, char *argv[]) {
	Tipo_elem aux;
	Pila pila, appoggio, altrapila;
	pila.Push(5);
	pila.Push(6);
	pila.Push(7);
	while (!pila.vuota()) appoggio.Push(pila.Pop());
	while (!appoggio.vuota()) {
		aux = appoggio.Pop();
		pila.Push(aux);
		altrapila.Push(aux);
	}
	cout << "ALTRAPILA\n";
	while (!altrapila.vuota()) {
		cout << altrapila.Top() << endl;
		altrapila.Cancella();
	}
	cout << "PILA\n";
	while (!pila.vuota()) {
		cout << pila.Top() << endl;
		pila.Cancella();
	}
	return 0;
}
