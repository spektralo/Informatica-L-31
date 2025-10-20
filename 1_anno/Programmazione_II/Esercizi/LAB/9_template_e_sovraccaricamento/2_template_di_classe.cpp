#include <iostream>  
using namespace std;

struct documento  {
	char titolo[20];
	char testo[100];
};

struct volantino{
	char titolo[10];
	char testo[200];
};
	

//TEMPLATE DI CLASSE
template <typename T> class Database {
private :
	T * pa;
	int lunghezza;
	
public:

	void sum(T a, T b){
		T sum;
		sum = a, b;
		return a + b;
	}

	Database(int n = 2) { 
		pa = new T[lunghezza = n];
		for (int i=0;i<lunghezza;i++) {
			cin.getline(pa[i].titolo,20);
			cin.getline(pa[i].testo,100);
		};
	}

	~Database() {delete[] pa;};

	void Visualizza (){
		for (int i=0;i<lunghezza;i++) {
			cout << endl << pa[i].titolo << endl;
			cout << pa[i].testo << endl;
			};
		};

		
};

int main() {
	Database <documento> db;
	Database <volantino> test;
	test.Visualizza();
	db.Visualizza();
	return 0;
}
	
