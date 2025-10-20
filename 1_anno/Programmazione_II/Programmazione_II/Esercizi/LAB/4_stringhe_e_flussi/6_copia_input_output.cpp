#include <iostream>  
#include <fstream>
using namespace std;

int main() {
	char c;
	cout << "Scrivi il nome del file di input: ";
	char nome_file[20];
	cin >> nome_file;
	ifstream FileIn (nome_file); // apre un file di input
	cout << "Scriva il nome del file di output: ";
	cin >> nome_file;
	ofstream FileOut (nome_file); // apre un file di output
	//int contatore=0;	
	while (FileIn.get(c)) 
	{
		//contatore++;
		cout << c;
		//cout << contatore;
		cout << "\n";
		FileOut.put(c);
	}
	FileIn.close();
	FileOut.close();
	return 0;
}

//input: telefono.txt - output.txt
//quante volte viene eseguito il ciclo while (commenta prima solo la riga "cout << c;" e poi il resto)
