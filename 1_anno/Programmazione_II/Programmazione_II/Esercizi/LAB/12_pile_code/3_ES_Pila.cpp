#include <iostream>
#include "Pila.h"
using namespace std;
int main(int argc, char *argv[]) {
	Pila p;
	int x = 5, y = 3;
	p.Push(8); // x=? - y=? - p=[]
	p.Push(9); // x=? - y=? - p=[]
	p.Push(y); // x=? - y=? - p=[]
	x = p.Pop(); // x=? - y=? - p=[]
	p.Push(18); // x=? - y=? - p=[]
	x = p.Pop(); // x=? - y=? - p=[]
	p.Push(22); // x=? - y=? - p=[]
	while (!p.vuota()) {
		y = p.Pop();
		cout << y << endl;
	} 
	cout << "-------------" << endl; 
	cout << x << endl; // x=? - y=? - p=[]
}
