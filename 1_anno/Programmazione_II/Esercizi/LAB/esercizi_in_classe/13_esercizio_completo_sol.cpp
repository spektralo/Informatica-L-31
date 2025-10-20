#include <iostream>
#include <string.h>

using namespace std ;

const int NMAX = 50 ;
typedef char Nome [NMAX] ;

//Squadra è l'elemento "sortable"
typedef struct {
	Nome n;
	unsigned int punteggio;
} Squadra ;
typedef Squadra SortableElem;


//Record è la classe "Nodo" che gestisce la lista (contiene un elemento ordinabile ed il successivo)
class Record
{
    protected:
        SortableElem el;
        Record* succ;
    public:
    	   Record();	                     // costruttore vuoto
        Record(SortableElem x);	                     // costruttore
        Record(SortableElem x, Record* s);	             // costruttore
        SortableElem get();           // restituisce  elemento SortableElem
        void put(SortableElem info);        // determina info elem
        Record* get_suc(); // restituisce puntatore al successivo
        void put_suc(Record *p);       // determina il successivo
 };

Record::Record(SortableElem x) {	
  el = x;  // costruttore che inizializza e ad x e succ a NULL
  succ = NULL;
}
Record::Record(SortableElem x, Record* s) {	
  el = x;    // costruttore che inizializza e ad x e sucs ad s
  succ = s;
}
SortableElem Record::get() {	
  return el;//restituisce una copia del contenuto informativo
}
void Record::put(SortableElem x) {	
  el = x;      // determina il contenuto informativo del record
}
Record* Record::get_suc() {	
  return succ;   //  restituisce il puntatore al record successivo
}
void Record::put_suc(Record *p) {
  succ = p; 	       // determina il puntatore al record successore
}

typedef Record *PuntatoreRec;



class Classifica{
private:
	PuntatoreRec first ;
	unsigned int nelem ;
	unsigned int Elimina (const Nome& n) ;
	void InserimentoOrdinato (const Nome& n, unsigned int punti);
public:
	Classifica() ;
	~Classifica() ;
	unsigned int Aggiungi (const Nome& n,unsigned int punti );
	void Svuota();
	void Stampa() const ;
	unsigned int Count () const ;
};

//costruttore con primo elemento NULL e numero elementi=0
Classifica::Classifica():first(NULL),nelem(0) {}

//distruttore
Classifica::~Classifica(){Svuota();}

//Questo metodo elimina dalla struttura un eventuale elem. avente nome pari
// ad n. In caso di esistenza ne restituisce il punteggio , altrimenti
// restituisce 0 .
unsigned int Classifica::Elimina(const Nome& n) {
	
	//E' il primo elemento ? ( Caso particolare )
	if (first && (strcmp(first->get().n ,n) == 0)) 
	{
		PuntatoreRec tbd = first ;
		first = first->get_suc();
		unsigned int punti = tbd->get().punteggio;
		delete tbd ;
		nelem--;
		return punti;
	}
	
	//E' un elemento successivo al primo ?
	PuntatoreRec p = first;
		//scorro gli elementi
		while(p && p->get_suc()) {
			// controllo se il successivo è quello che deve essere eliminato
			if(strcmp(p->get_suc()->get().n,n) == 0 ) 
			{
				//tbd è quello da eliminare
				PuntatoreRec tbd = p->get_suc();
				//aggiorno le referenze (precedente di tbd punta a successivo di tbd)
				p->put_suc(tbd->get_suc());
				
				//etrazione punteggio e cancellazione record
				unsigned int punti = tbd->get().punteggio;
				delete tbd ;
				nelem--;
				return punti ;
			}
				
			p = p->get_suc() ;
		}
	
		// Elemento non trovato
		return 0 ;
}


void Classifica::InserimentoOrdinato( const Nome& n , unsigned int punti ) {
	
	//creazione elemento da inserire
	SortableElem nuovo_elemento_ordinato;
	strcpy(nuovo_elemento_ordinato.n,n);
	nuovo_elemento_ordinato.punteggio=punti;
	
	//creo puntatore
	PuntatoreRec nuovo = new Record(nuovo_elemento_ordinato) ;
	
	nelem++;
	if (!first) { // Se la lista è vuota
		first = nuovo ; // Inserisco alla testa
		nuovo->put_suc(NULL) ;
	}
	else
	{
		// Se ilpunteggio della nuova squadra è maggiore della testa
		if(punti>= first->get().punteggio) {
			nuovo->put_suc(first); //Inserisco in testa
			first = nuovo ;
		} 
		else 
		{ //Devo cercare il punto di inserzione
			PuntatoreRec p = first;
			while (p && p->get_suc()) {
				//Devo inserire dopo l'elemento puntato da p?
				if(punti>= p->get_suc()->get().punteggio) {
					nuovo->put_suc(p->get_suc());
					p->put_suc(nuovo) ;
					return ;
				}
				p= p->get_suc();
			}
			// Se sono qui , non ho ancora inserito quindi
			// inserim.in coda , alla quale punta p
			p->put_suc(nuovo) ;
			nuovo->put_suc(NULL) ;
		}
	}
}


unsigned int Classifica::Aggiungi(const Nome& n, unsigned int punti) {
	unsigned int p = Elimina(n) ; // Elimina dalla lista l'elemento (se esiste)
	InserimentoOrdinato(n,punti+p); //Lo (re)inserisce al posto giusto
	return punti+p ; // Restituisce il giusto punteggio
}


void Classifica::Svuota() {
	while(first) {
		PuntatoreRec tbd = first;
		first = first->get_suc();
		delete tbd ;
	}
	nelem = 0 ;
}
void Classifica::Stampa() const {
	PuntatoreRec p = first ;
	while(p) {
		cout << p->get().n << " : " << p->get().punteggio<< endl ;
		p = p->get_suc();
	}
}
unsigned int Classifica::Count() const {
	return nelem ;
}

void stampa_menu ( ) {
	cout << "1 : Inserisci. \n" ;
	cout << "2 : Svuota. \n" ;
	cout << "3 : Stampa. \n" ;
	cout << "4 : Count. \n" ;
	cout << "5 : Esci. \n" ;
}

void Aggiungi(Classifica& l) ;
void Svuota(Classifica& l) ;
void Stampa(Classifica& l) ;
void Count(Classifica& l);


void Aggiungi (Classifica& l) {
	Nome n ;
	unsigned int punti;
	cout << "Inserici nome:" ;
	cin >> n ;
	cout << "Inserisci punti:" ;
	cin >> punti;
	cout << "La squadra " << n << " ora ha punti: " << l.Aggiungi(n, punti) << " . \n" ;
}

void Svuota(Classifica& l ) {
	l.Svuota();
	cout << " Classifica svuotata\n" ;
}

void Stampa(Classifica& l) {
	l.Stampa() ;
	cout << endl;
}

void Count(Classifica& l) {	
	cout << " Il numero di elementi e ' : " << l.Count() << endl;
}



int main()
{
	Classifica l;
	int scelta ;
	do {
		stampa_menu();
		cin >> scelta ;
		switch (scelta) {
			case 1 :
				Aggiungi(l);
				break;
			case 2:
				Svuota(l);
				break;
			case 3:
				Stampa(l);
				break;
			case 4:
				Count(l);
				break ;
			case 5:
				break;
			default:
				cout << "Scelta non valida.\n" ;
				break ;
		}
	} 
	while (scelta != 5);
	return 0 ;
}



