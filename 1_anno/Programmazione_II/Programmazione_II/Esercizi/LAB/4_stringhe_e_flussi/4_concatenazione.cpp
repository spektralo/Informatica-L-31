#include <iostream>  
#include <cstring>  
using namespace std;

int main() {
	char s1[81], s2[81];
	cout << "Introduca una stringa: ";
	cin.getline(s1,80);
	cout << "Introduca un'altra stringa: ";
	cin.getline(s2,80);
	cout << "Prima della concatenazione: \n";
	cout << "s1 = \"" << s1 << "\", lunghezza = " << strlen(s1) << "\n";
	cout << "s2 = \"" << s2 << "\", lunghezza = " << strlen(s2) << "\n";
	strcat(s1, s2);
	cout << "Dopo la concatenazione: \n";
	cout << "s1 = \"" << s1 << "\", lunghezza = " << strlen(s1) << "\n";
	cout << "s2 = \"" << s2 << "\", lunghezza = " << strlen(s2) << "\n";
	return 0;
}


