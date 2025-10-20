#include <iostream>  
#include <cstring>  
using namespace std;

int main() {
	unsigned lung;
	char stringa[81];
	char invertita[81];
	cout << "Introduca una stringa: ";
	cin.getline(stringa,80);
	//strlen dalla libreria csting
	lung=strlen(stringa);
	for (unsigned i=0; i<lung; i++) 
		invertita[i]=stringa[lung-1-i];
	
	invertita[lung]='\0';
	cout << "Stringa invertita: \n" << invertita << endl;
	return 0;
}


