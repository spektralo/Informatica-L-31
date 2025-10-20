/* 
Progettare una classe vettore3d che permetta di manipolare vettori 3D (di tipo float ) 
e che contenga una funzione costruttore predefinita ed una con valori per default (0) 
Deve contenere:
- la funzione visualizza
- la funzione prodotto scalare che restituisce il prodotto scalare (flot) senza modificare il vettore. 
- la funzione somma ad un altro vettore che modifica il vettore stesso. 
Testare il tutto sul main.
*/

#include <iostream>  
using namespace std;

class vettore3d {
private:
	float x, y, z;
public:
	vettore3d() {x=0; y=0; z=0;};
	vettore3d(float a, float b, float c) {x=a; y=b; z=c;};
	
	float prodotto(vettore3d v) {
		return x * v.x + y * v.y + z * v.z;
	};
	
	void visualizza() {cout << x << ' ' << y << ' ' << z << endl;};
	
	void somma(vettore3d v) {
		x += v.x;
		y += v.y;
		z += v.z;
	};
};

int main() {
	vettore3d x;
	vettore3d y(1.1,2.2,3.3), z(4.4,5.5,6.6);
	x.visualizza();	
	y.visualizza(); 
	z.visualizza();
	cout << y.prodotto(z) << endl;
	y.visualizza(); 
	
	vettore3d a(1,2,3), b(4,5,6);
	a.visualizza();
	a.somma(b);
	a.visualizza();
	return 0;
}
