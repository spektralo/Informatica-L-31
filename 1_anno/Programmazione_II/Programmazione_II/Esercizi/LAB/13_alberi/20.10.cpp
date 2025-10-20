
/* Scrivere una funzione booleana che prende in input due alberi e restituisce true
se e solo se essi sono identici
*/


#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo *sx;
  nodo *dx;
};

int somma;

class btree {
public:
    nodo *radice;	
	btree() {radice = NULL;};
	~btree() {distruggi(radice);};
	void I(int chiave) {I(chiave, radice);};
	void E(int chiave) {E(chiave, radice);};
	void In(){In(radice);};
	void Pr(){Pr(radice);};
	void Po(){Po(radice);};
private:
    void distruggi(nodo* &);
    void I(int, nodo* &);
    void E(int, nodo* &);
	void In(nodo*);
	void Pr(nodo*);
	void Po(nodo*);
};

bool identici(nodo* a, nodo* b) {
	if(a == NULL && b == NULL) return true;
	if (a != NULL && b != NULL)
		return (a->info == b->info && 
				identici(a->sx, b->sx) && 
				identici(a->dx, b->dx));
	return false;
}

void btree::distruggi(nodo* &p) {
  if(p) {
    distruggi(p->sx);
    distruggi(p->dx);
    delete p;
  }
}

void btree::I(int chiave, nodo* &p) {
	if (p) {
		if(chiave < p->info) {
			if(p->sx != NULL) I(chiave, p->sx);
			else {
				p->sx = new nodo;
				p->sx->info = chiave;
				p->sx->sx = NULL; // il figlio sx del nuovo nodo è NULL
				p->sx->dx = NULL; // il figlio dx del nuovo nodo è NULL
			}  
		}
	else if(p->dx != NULL) I(chiave, p->dx);
		 else {
				p->dx = new nodo;
				p->dx->info = chiave;
				p->dx->sx = NULL; // il figlio sx del nuovo nodo è NULL
				p->dx->dx = NULL; // il figlio dx del nuovo nodo è NULL
			}
	}
	else {
		p = new nodo;
		p->info = chiave;
		p->sx = NULL;
		p->dx = NULL;
	}	
}

void btree::E(int chiave, nodo* &p) {
	nodo* temp;
	if (p) {
		if(chiave < p->info) E(chiave, p->sx);
		else if(chiave > p->info) E(chiave, p->dx);
		     else {
		     if (p->sx==NULL && p->dx==NULL) {
				 temp = p;
				 p = NULL;
				 delete temp;
			 }
			 else if (p->sx == NULL) {
				temp = p;
				p = p->dx;
				delete temp;
				}
				else if (p->dx == NULL) {
					temp = p;
					p = p->sx;
					delete temp;
					}
				else {
					temp = p->dx;
					while (temp->sx != NULL) temp = temp->sx;
					p->info = temp->info;
            		E(temp->info, p->dx);
				}
		}	
	}
}

void btree:: In(nodo* p) {
	if (p) {
		In(p -> sx);
		cout << p->info << ' ';
		In(p -> dx);
		}
}

void btree:: Pr(nodo* p) {
	if (p) {
		cout << p->info << ' ';
		Pr(p -> sx);
		Pr(p -> dx);
		}
}

void btree:: Po(nodo* p) {
	if (p) {
		Po(p -> sx);
		Po(p -> dx);
		cout << p->info << ' ';
		}
}

int main() {
	btree a, b;                           
	a.I(1);
	a.I(4);
	a.I(3);
	b.I(1);
	b.I(4);
	b.I(5);

	if (identici(a.radice, b.radice)) cout << "Identici\n";
	else cout << "NON Identici\n";
}
