#include <iostream>
#include <typeinfo>
using namespace std;

int main( ) {
	int x;
	float y;
	x = 15/12;
	//x = 15.0/12.0;
	y = 15.0/12.0;
	//y = 24.0/12.0;
	cout << "x vale " << x << endl;
	cout << "tipo x: " << typeid(x).name() << endl;
	cout << "y vale " << y << endl;
	cout << "tipo y: " << typeid(y).name() << endl;
	cout << x % y << endl;
	return 0;
}

//valore e tipo di x e y?
// x % y?
