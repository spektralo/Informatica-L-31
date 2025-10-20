// Esercizio
/* Scrivere un programma che scambi due nodi di una lista concatenata. I nodi si
identificano per numeri e si passano come parametri. Per esempio, per scambiare i
nodi 5 e 8 si deve invocare scambio(5, 8) . Se lo scambio si realizza con successo, si
restituisce vero; se si produce un errore, come un numero di nodo non valido, si 
restituisce falso.
*/

#include <iostream>
using namespace std;

typedef int Tipo_elem;

class Nodo
{
    protected:
        Tipo_elem info;
        Nodo* suc;
    public:
        Nodo(){}	                       // costruttore vuoto
        Nodo(Tipo_elem x);	                     // costruttore
        Nodo(Tipo_elem x, Nodo* s);	             // costruttore
        ~Nodo(){}	                             // distruttore
        Tipo_elem get();           // restituisce info elemento
        void put(Tipo_elem info);        // determina info elem
        Nodo* get_suc(); // restituisce puntatore al successivo
        void put_suc(Nodo *p);       // determina il successivo
 };
 
typedef Nodo* lista;
 
Nodo::Nodo(Tipo_elem x) {	
  info = x;  // costruttore che inizializza e ad x e suc a NULL
  suc = NULL;
}
Nodo::Nodo(Tipo_elem x, Nodo* s) {	
  info = x;    // costruttore che inizializza e ad x e suc ad s
  suc = s;
}
Tipo_elem Nodo::get() {	
  return info;//restituisce una copia del contenuto informativo
}
void Nodo::put(Tipo_elem x) {	
  info = x;      // determina il contenuto informativo del nodo
}
Nodo* Nodo::get_suc() {	
  return suc;   //  restituisce il puntatore al nodo successivo
}
void Nodo::put_suc(Nodo *p) {
  suc = p; 	       // determina il puntatore al nodo successore
}


void inserisci_in_testa(lista& inizio, Tipo_elem e) {
   lista nuovo = new Nodo(e, inizio);   // genera nuovo Nodo
   inizio = nuovo ;               // inizio punta il nuovo Nodo
}

void inserisci_in_coda(lista& inizio, Tipo_elem e) {
 lista p, q = inizio;
 while (q != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 q = new Nodo(e); // inizializza info ad e e suc a NULL
 if (inizio == 0) inizio->put_suc(q);
     else p->put_suc(q);
}

void inserisci_ordinatamente(lista& inizio, Tipo_elem e) {
 lista r, p = NULL, q = inizio;
 while ((q != NULL) && (q->get() < e)) {
	 p = q;
	 q = q->get_suc();
 }
 r = new Nodo(e,q);
 if (q == inizio) inizio = r;  // se si deve inserire in testa
     else p->put_suc(r);
}

bool estrai_dalla_testa(lista& inizio, Tipo_elem& e) {
 lista p = inizio;
 if (inizio == NULL) return false;
 e = p->get();
 inizio = p->get_suc();
 delete p;
 return true;
}

bool estrai_dalla_coda(lista& inizio, Tipo_elem& e) {
 lista p, q = inizio;
 if (inizio == NULL) return false;
  while (q->get_suc() != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 e = q->get();
 if (q == inizio) inizio = NULL; // se si estrae il primo elemento
     else p->put_suc(NULL);
 delete q;
 return true;
}

bool estrai_elem_dato(lista& inizio, Tipo_elem& e) {
	lista p, q = inizio;
	while ((q != NULL) && (q->get() != e)) {
	 p = q;
	 q = q->get_suc();
 }		
 if (q == NULL) return false;   // l'elemento non � stato trovato
 if (q == inizio) inizio = q->get_suc();   // l'elemento cercato era il primo
     else p->put_suc(q->get_suc());
 e = q->get();
 delete q;
 return true;
}

/*   FUNZIONE DI SUPPORTO */
void stampaLista(lista p) {
	while (p != NULL) {
		cout << p->get() << ' ';
		p = p->get_suc();
		}
}

int conta_elem_dato(lista& inizio, Tipo_elem& e) {
	int cont=0;
	lista q = inizio;
    while (q != NULL) {
	  if (e==q->get()) cont++;
	  q = q->get_suc();
    }
    return cont;
}

int sommatoria(lista& inizio) {
	int somma=0;
	lista q = inizio;
    while (q != NULL) {
		somma += q->get();
	    q = q->get_suc();
    }
    return somma;
}

void minore(lista& inizio, Tipo_elem& e) {
	Tipo_elem minore;
	lista q = inizio;
	if (q) minore=q->get();
    while (q->get_suc() != NULL) {
	  q = q->get_suc();
	  if (minore > q->get()) minore = q->get();
    }
    e = minore;
}

bool scambia(lista& inizio, Tipo_elem& a, Tipo_elem& b) {
	lista p, pp, q = inizio, qq = inizio;
	while ((q != NULL) && (q->get() != a)) {
		p = q;
		q = q->get_suc();
	 }	
	 if (q == NULL) return false;   // l'elemento non è stato trovato
	 while ((qq != NULL) && (qq->get() != b)) {
		 pp = qq;
		 qq = qq->get_suc();
		 }		
	if (qq == NULL) return false;   // l'elemento non è stato trovato
	Tipo_elem aux = q->get();
	q->put(qq->get());
	qq->put(aux);
	return true;
}

int main() {
	char r;
	lista scritto = 0;
	Tipo_elem el, el2;
	do {
		cout << "\ni: inserisci in testa\n" 
			 << "c: inserisci in coda\n" 
		     << "o: inserisci ordinatamente\n"
		     << "t: estrai dalla testa\n" 
		     << "e: estrai dalla coda\n"
		     << "f: estrai un particolare elemento\n"
		     << "s: stampa la lista\n"
		     << "r: conta occorenze elemento dato\n"
		     << "b: scambia due elementi\n";
		cin >> r;
		switch (r) {
			case 'i': cin >> el; inserisci_in_testa(scritto, el); break;
			case 'c': cin >> el; inserisci_in_coda(scritto, el); break;
			case 'o': cin >> el; inserisci_ordinatamente(scritto, el); break;
            case 't': estrai_dalla_testa(scritto, el); cout << "Ho tolto " << el; break;
            case 'e': estrai_dalla_coda(scritto, el); cout << "Ho tolto " << el; break;
            case 'f': cout << "Da togliere?  "; cin >> el;estrai_elem_dato(scritto, el);  break;
            case 's': stampaLista(scritto); break;
            case 'r': cin >> el; cout << conta_elem_dato(scritto, el) << endl; break;
            case 'b': cin >> el >> el2; scambia(scritto, el, el2); break;
    }
  }
 while (r == 'i' || r == 'c' || r== 'o' || r == 't' || r == 'e' || r== 'f' || r== 's' || r== 'r'|| r== 'b');
 return 0;
}
