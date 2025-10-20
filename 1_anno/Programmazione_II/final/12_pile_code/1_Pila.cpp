#include<iostream>
using namespace std;

typedef int Tipo_elem;

//classe Nodo
class Nodo {
protected:
	Tipo_elem e;
	Nodo *next;
public:
	Nodo(){}
	~Nodo(){}
	Nodo (Tipo_elem x){ e = x; next = NULL;} // costruttore
	Tipo_elem get(){ return e;} // Ottiene elemento
	void put(Tipo_elem x){ e = x;} // Assegna elemento
	Nodo * get_suc(){ return next;} // Ottiene successivo
	void put_suc( Nodo *p){ next = p;} // Assegna successivo
};

class Pila {
protected:
	Nodo *p;
public:
	Pila(){p = NULL;} // costruttore
	~Pila();//distruttore
	bool vuota(){ return !p;}//controllo Pila vuota
	Tipo_elem Top(){ if (p) return p->get();}//get elemento in testa
	void Push( Tipo_elem e);//push
	void Cancella();//funzione utilizzata su Pop
	Tipo_elem Pop();//pop
};


//distruttore
Pila:: ~Pila() {
	//paux puntatore a nodo
	Nodo *paux;
	
	//fin quando c'� un "p" nodo in testa allo stack
	//lo cancello spostando ogni volta la testa al successivo
	while(p != 0) {
		paux = p;
		p = p->get_suc();
		delete paux;
	}
}





//Cancella
void Pila::Cancella() {
	Nodo *paux;
	//se la Pila non � vuota
	if(p) {
		//assegno al testa della pila a paux
		paux = p;
		//sposto p all'elemento successivo 
		p = p->get_suc();
		//cancello il nodo
		delete paux;
		}
}


//POP
Tipo_elem Pila::Pop() {
	
	//ottengo elemento in testa
	Tipo_elem e;
	e = Top();
	
	//eseguo cancella: elimina l'elemento in testa della pila
	Cancella();
	return e;
}



//Push
void Pila::Push(Tipo_elem e) {
	
	//puntatore a Nodo
	Nodo *aux;
	//creo nodo
	aux = new Nodo(e);
	//se ho un elemento in testa alla pila lo pongo come successivo al nuovo nodo
	if( p )
		aux->put_suc(p);
	//setto il nuovo nodo come testa della pila
	p = aux;
}


