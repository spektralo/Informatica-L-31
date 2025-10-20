/* Implementare una gerarchia di tipi di dato numerici che estenda i tipi di dato fondamentali 
come int e float , disponibili in C++. Le classi da progettare possono essere Complesso, 
Vettore , Vettore 3D , con i relativi metodi (operazioni su quei tipi).
*/

#include <iostream>  
using namespace std;

// tipo generico composto da 2 dimensioni
class NewType {
protected:
	float x,y;
public:
	NewType(float a=0, float b=0) : x(a),y(b) {};
	void Visualizza() {cout << "Dim1 = " << x << " Dim2 = " << y << endl;};
};

class Complesso : public NewType {
public:
	//nell'esempio precedente avveniva in automatico perchè Persona aveva costruttore senza parametri
	Complesso(float a, float b) : NewType(a,b){};
	//POLIMORFISMO!!!
	void Visualizza() {cout << "R = " << x << " I = " << y << endl;};
	void Somma(Complesso c1, Complesso c2) {
		x = c1.x + c2.x;
		y = c1.y + c2.y;
	};
	void Sottrazione(Complesso c1, Complesso c2) {
		x = c1.x - c2.x;
		y = c1.y - c2.y;
	};
	void Moltiplicazione(Complesso c1, Complesso c2) {
		x = c1.x * c2.x - c1.y * c2.y;
		y = c1.x * c2.y + c2.x * c1.y;
	};
	void MoltiplicaReale(Complesso c1, float r) {
		x = c1.x * r;
		y = c1.y * r;
	};
	void Coniugato(Complesso c1) {
		x = c1.x;
		y = -c1.y;
	};
};

class Vett2D : public NewType {
public:
	Vett2D(float a, float b) : NewType(a,b){};
	void Visualizza() {cout << "X = " << x << " Y = " << y << endl;};
	void Somma(Vett2D c1, Vett2D c2) {
		x = c1.x + c2.x;
		y = c1.y + c2.y;
	};
	void Sottrazione(Vett2D c1, Vett2D c2) {
		x = c1.x - c2.x;
		y = c1.y - c2.y;
	};
	void MoltiplicaScalare(Vett2D c, float s) {
		x = c.x * s;
		y = c.y * s;
	};
	void Coniugato(Vett2D c) {
		x = -c.x;
		y = -c.y;
	};
};

class Vett3D : public Vett2D {
protected:
	float z;
public:
	Vett3D(float a, float b, float c) : Vett2D(a,b){z = c;};
	void Visualizza() {cout << "X = " << x << " Y = " << y 
		                    << " Z = " << z << endl;};
	void Somma(Vett3D c1, Vett3D c2) {
		x = c1.x + c2.x;
		y = c1.y + c2.y;
		z = c1.z + c2.z;
	};
	void Sottrazione(Vett3D c1, Vett3D c2) {
		x = c1.x - c2.x;
		y = c1.y - c2.y;
		z = c1.z - c2.z;
	};
	void MoltiplicaScalare(Vett3D c, float s) {
		x = c.x * s;
		y = c.y * s;
		z = c.z * s;
	};
	void Coniugato(Vett3D c) {
		x = -c.x;
		y = -c.y;
		z = -c.z;
	};
};

int main() {
	//type generico
	NewType a(1.1,2.2); a.Visualizza();
	
	cout << "\n\n---------COMPLESSO--------------\n" << endl;
	// complesso
	Complesso b(2.2,3.3); b.Visualizza();	
	Complesso c(3.3,4.4); c.Visualizza();	
	c.Somma(b,c); c.Visualizza();	
	
	cout << "\n\n---------VETTORE 2D--------------\n" << endl;
	//vettore 2D
	Vett2D d(1.1,2.2); d.Visualizza();
	Vett2D e(3.3,4.4); e.Visualizza();
	e.Sottrazione(d,e); e.Visualizza();
	e.MoltiplicaScalare(e,4); e.Visualizza();
	
	cout << "\n\n----------VETTORE 3D-------------\n" << endl;
	//vettori 3D
	Vett3D f(5.5,6.6,7.7); f.Visualizza();
	Vett3D g(6.6,7.7,8.8); g.Visualizza();
	g.Coniugato(f); g.Visualizza();
	return 0;
}
