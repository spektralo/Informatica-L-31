
#include <iostream>
using namespace std;

int main() {
	int tabella[2][3];
	for (int i=0; i<2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tabella[i][j];
			cout << "Hai inserito il numero " << tabella[i][j] << "\n";
		}
		
	}
	cout << "OUTPUT:" << tabella[0][2] << endl;
	cout << "OUTPUT:" << tabella[2][3] << endl;
	return 0;
}

// 6 elementi (2*3) - inserisco valori da 1 a 6. Output?
