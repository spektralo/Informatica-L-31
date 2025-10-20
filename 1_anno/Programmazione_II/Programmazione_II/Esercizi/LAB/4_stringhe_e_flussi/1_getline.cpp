#include <iostream>  
using namespace std;

unsigned lung_string(char* s) {
	unsigned i = 0;
	//scorro il riferimento all'array di carattteri
	while (*(s+i)!= '\0') i++;
	return i;
}

int main () {
	char stringa[10];
	cout << "Per favore, immetta una stringa: ";
	//legge tutti gli inputs fino alla prima occorrenza del carattere in terza posizione (\n se vuoto) 
	//e li assegna alla var stringa
	cin.getline(stringa,10);
	//cin.getline(stringa,100,'x');
	cout << "Ha immesso una stringa lunga " << lung_string(stringa)
	     << " caratteri\n";
	     
  return 0;
}

//sostituzione del carattere separatore "\n" con "x" (riga 17)


