/*
Le righe che iniziano con il simbolo di cancelletto (# )
sono direttive per il preprocessore del compilatore.
Esse non sono istruzioni eseguibili ma soltanto indicazioni per il compilatore. 
Nel nostro caso la frase  #include <iostream> dice al preprocessore del compilatore 
di includere il file della libreria standard iostream.h.
Questo particolare file contiene le dichiarazioni delle operazioni basilari
di input-output definite nella libreria standard del C++ e viene incluso
perché tali operazioni serviranno in seguito nel programma.
 */
#include <iostream>

/* 
In C++ il main() è una funzione che deve restituire il tipo int
*/
int main()
{
	//std::cout controlla il buffer di output
	std::cout << "Ciao mondo!\n";
	
	//all'interno del main è una convenzione che significa che tutto è andato a buon fine
	return 0;
	
	// un errore durante l'esecuzione produrrà un return 1 del main
}

