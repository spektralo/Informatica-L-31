#include <iostream>
using namespace std;

int main() {
	cout << "con il while\n";
	int num = 10;
	while (num <= 100){
		cout << num << endl;
		num += 10;
	}
	
	cout << "con il for\n";
	for (num = 10; num <= 100; num += 10) 
		cout << num << endl;
	
	cout << "con il do-while\n";
	num = 10;
	do {
		cout << num << endl;
		num += 10;
	} while (num <= 100);
	return 0;
}

//for : esegue un'iterazione per ogni elemento di un iterabile
//while : itera fintanto che una condizione è vera
//do-while : while con condizione alla fine (esegue sempre un ciclo)




