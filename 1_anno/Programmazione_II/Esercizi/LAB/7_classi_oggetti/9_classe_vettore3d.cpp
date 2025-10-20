/* 
Si vuole realizzare una classe vettore 3d che permetta di manipolare vettori di
tre coordinate x , y , z secondo le seguenti regole:

- ci sarà  solo una funzione costruttore
- ci sarà  una funzione chiamata "uguale" che permette di sapere se due vettori hanno le
coordinate uguali, con la funzione realizzata:
		- a. per trasmissione di valore ("uguale1"); 
		- b. per trasmissione di indirizzo ("uguale2"); 
		- c. per trasmissione di riferimento ("uguale3");
- ci sarà una funzione denominata norma che permetta di ottenere la norma del
vettore 3d (Nota: La norma di un vettore v = x,y,z è x*x+y*y+z*z ).

- Testare nel main le funzioni create
*/

#include <iostream>  
using namespace std;

class vettore3d {
private:
	float x, y, z;
public:
	vettore3d(float a, float b, float c) {x=a; y=b; z=c;};
	
	bool uguale1(vettore3d v) {
		return (x == v.x && y == v.y && z == v.z);
	};
	
	bool uguale2(vettore3d& v) {
		return (x == v.x && y == v.y && z == v.z);
	};
	
	bool uguale3(vettore3d* pv) {
		return (x == pv->x && y == pv->y && z == pv->z);
	};
	
	float norma() {return x*x + y*y + z*z;};
};




int main() {
	vettore3d PRIMO(1,2,3);
	cout << "NORMA DEL VETTORE PRIMO: " << endl;
	cout << PRIMO.norma() << endl;
	
	vettore3d SECONDO(1,2,3);
	if(PRIMO.uguale1(SECONDO))
		cout << "I DUE VETTORI SONO UGUALI " << endl;
	else
		cout << "I DUE VETTORI NON SONO UGUALI " << endl;
		
		
	cout << "\n\n-----------------------\n" << endl;
	vettore3d &r=SECONDO;
	cout << "r.norma: " << r.norma() << endl;
	if(PRIMO.uguale2(r))
		cout << "I DUE VETTORI SONO UGUALI " << endl;
	else
		cout << "I DUE VETTORI NON SONO UGUALI " << endl;
	
	
	cout << "\n\n-----------------------\n" << endl;
	vettore3d *p;
	p=&SECONDO;
	cout << "p:" << p << endl;
	cout << "&SECONDO: " << &SECONDO << endl;
	cout << "p->norma: " << p->norma() << endl;
	if(PRIMO.uguale3(p))
		cout << "I DUE VETTORI SONO UGUALI " << endl;
	else
		cout << "I DUE VETTORI NON SONO UGUALI " << endl;
	
	
		
	
	return 0;
}



