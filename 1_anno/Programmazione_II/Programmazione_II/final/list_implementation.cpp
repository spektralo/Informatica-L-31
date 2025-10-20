#include<iostream>
using namespace std;

/*-------------------------------------------------------*/
typedef int elemType;
class Nodo{
protected:
    elemType info;
    Nodo*next;

public:
    Nodo(){};
    Nodo(elemType data);
    Nodo(elemType data, Nodo* next);
    ~Nodo(){}
    elemType get();
    void put(elemType info);
    Nodo* getNext();
    void putNext(Nodo *node);       
};

typedef Nodo* list;

Nodo::Nodo(elemType data){info = data; next = NULL;}

Nodo::Nodo(elemType data, Nodo*node){info = data; next = node;}

elemType Nodo::get(){return info;}

void Nodo::put(elemType data){info = data;}

Nodo* Nodo::getNext(){return next;}

void Nodo::putNext(Nodo*node){next = node;}

/*---------------------------------------------------------*/


void headIns(list& begin, elemType data){
    list newNode = new Nodo(data,begin);
    begin = newNode;
}



void backIns(list& begin, elemType data){
    list p, q = begin;
    while (q != NULL)
    {
        p = q;
        q = q->getNext();
    }
    q = new Nodo(data);

    if(begin == 0){
        begin->putNext(q);
    }
    else p->putNext(q);
}



void inOrderIns(list& begin, elemType data){
    list r, p = NULL, q = begin;
    while ((q !=NULL ) && ( q->get() < data)) 
    {
        p = q;
        q = q->getNext();
    }
    r = new Nodo(data,q);

    if( q == begin) begin = r;
    else p->putNext(r);
}

/*------------------------------------------------------------*/


bool headExtract(list& begin, elemType& data){
    list p = begin;
    if (begin == NULL) return false;

    data = p->get();
    begin = p->getNext();

    delete p;
    return true;
    
}



bool backExtract(list& begin, elemType data){
    list p, q = begin;
    if (begin == NULL) return false;

    while (q != NULL)
    {
        p = q;
        q = q->getNext();
    }

    if(q == begin) begin = NULL;
    else p->putNext(NULL);

    delete q;
    return true; 
    
}



bool searchExtract(list& begin, elemType& data){
    list p, q = begin;
    while ((q != NULL) && (q->get() != data))
    {
        p = q;
        q = q->getNext();
    }

    if (q == NULL) return false;
    if (q == begin) begin = q->getNext();
        else p->putNext(q->getNext());
        data = q->get();
        
        delete q;
        return true;
}

/*----------------------------------------------------------------*/

void printList(list p) {
	while (p != NULL) {
		cout << p->get() << ' ';
		p = p->getNext();
		}
}



int main(int argc, char const *argv[])
{
    char r;
    list newList = 0;
    elemType data;

    do {
		cout << "\ni: inserisci in testa\n" 
			 << "c: inserisci in coda\n" 
		     << "o: inserisci ordinatamente\n"
		     << "t: estrai dalla testa\n" 
		     << "e: estrai dalla coda\n"
		     << "f: estrai un particolare elemento\n"
		     << "s: stampa la lista\n";

		cin >> r;
		switch (r) {
			case 'i': cin >> data; headIns(newList, data); break;
			case 'c': cin >> data; backIns(newList, data); break;
			case 'o': cin >> data; inOrderIns(newList, data); break;
            case 't': headExtract(newList, data); cout << "Ho tolto " << data; break;
            case 'e': backExtract(newList, data); cout << "Ho tolto " << data; break;
            case 'f': cout << "Da togliere?  "; cin >> data; searchExtract(newList, data);  break;
            case 's': printList(newList); break;
            
    }
  }
 while (r == 'i' || r == 'c' || r== 'o' || r == 't' || r == 'e' || r== 'f' || r== 's');
 return 0;
    return 0;
}
