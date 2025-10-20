#include <iostream>
#include <cstring>
using namespace std;

struct data {
	int g,m,a;
	char mese[10];
};

void scrivi(data dt){

	cout << dt.g << '/' << dt.m << '/' << dt.a << '\n';
	cout << dt.g << ' ' << dt.mese << ' ' << dt.a << '\n';
}


int main() {
	data prima = {1,1,2000,"gennaio"};
	scrivi(prima);
	
	data date[2];
	
	date[0].g=2;
	date[0].m=3;
	date[0].a=2022;
	strcpy(date[0].mese,"febbraio");
	//date[0].mese="febbraio"; //!errore: non possiamo assegnare una stringa
	//cout << *prima.mese << '\n'; 
	//cout << *date[0].mese << '\n'; 
	
	date[1].g=5;
	date[1].m=10;
	date[1].a=2012;
	strcpy(date[1].mese,"ottobre");
	
	
	for (int i=0; i<2; i++) {
	scrivi(date[i]);
	}
	
	
	return 0;
}
