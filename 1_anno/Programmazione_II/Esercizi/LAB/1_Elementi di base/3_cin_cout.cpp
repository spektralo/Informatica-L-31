#include <iostream>
using namespace std;

int main() {
	//2bytes 0 to 65.535
	unsigned short giorno, mese, anno;
	cout << "Data di oggi? (gg mm aaaa)\n";
	cin >> giorno >> mese >> anno;
	cout << "Data odierna: " << giorno 
	     << '/' << mese
	     << '/' << anno << endl;
	return 0;
}

//cosa succede se non inserisco uno short unsigned?
