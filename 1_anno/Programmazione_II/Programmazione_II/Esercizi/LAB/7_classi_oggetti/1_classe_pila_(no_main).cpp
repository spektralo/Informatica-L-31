#define MaxElementi 100

class Pila {
public:
	Pila();
	bool immettere(char);
	char estrarre(char&);
private :
	char elementi[MaxElementi]; 
	int cima;
};

// costruttore della Pila
Pila::Pila() {
	cima = -1;
}

// funzione metodo immettere (Push)
bool Pila::immettere(char elem) {
	if(cima < MaxElementi -1) {
		elementi[++cima] = elem;
		return true;
	}
	else return false;
}

// funzione metodo estrarre (Pop)
char Pila::estrarre() {
	if (cima < 0) 
		return '0';
	else 
		 return elementi[cima--];
	
}

