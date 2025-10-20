#include <iostream>   
using namespace std;

class punto {
	public:	
	int x, y;
	punto(int x1, int y1) {
		x = x1; y = y1; cout << "costruttore con doppio parametro " << x1 << " - " <<y1<< endl;
	}
	
	/*punto(int z) {
		punto (z, z); cout << "costruttore con singolo parametro "<< z << endl;
	}*/
	punto(int z) {x = z; y = z;}
};

int main() {
	//punto p(25);
	punto p(25,50);
	cout << "x = " << p.x << ", y = " << p.y <<
	endl;
}

//output?
//punto p(25); sta passando dal costruttore con singlo parametro?


