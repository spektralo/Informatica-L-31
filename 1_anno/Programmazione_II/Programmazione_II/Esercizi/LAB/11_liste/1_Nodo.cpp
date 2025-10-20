
typedef int Tipo_elem;

class Nodo
{
    protected:
        Tipo_elem info;
        Nodo* suc;

    public:
        Nodo(){}	                       // costruttore vuoto
        Nodo(Tipo_elem x);	                     // costruttore
        Nodo(Tipo_elem x, Nodo* s);	             // costruttore
        ~Nodo(){}	                             // distruttore
        Tipo_elem get();           // restituisce info elemento
        void put(Tipo_elem info);        // determina info elem
        Nodo* get_suc(); // restituisce puntatore al successivo
        void put_suc(Nodo *p);       // determina il successivo
 };
 
 
 //la lista concatenata � un puntatore ad un Nodo
 typedef Nodo* lista;
 
 Nodo::Nodo(Tipo_elem x) {	
  info = x;  // costruttore che inizializza e ad x e suc a NULL
  suc = nullptr;
}
Nodo::Nodo(Tipo_elem x, Nodo* s) {	
  info = x;    // costruttore che inizializza e ad x e suc ad s
  suc = s;
}
Tipo_elem Nodo::get() {	
  return info;//restituisce una copia del contenuto informativo
}
void Nodo::put(Tipo_elem x) {	
  info = x;      // determina il contenuto informativo del nodo
}
Nodo* Nodo::get_suc() {	
  return suc;   //  restituisce il puntatore al nodo successivo
}
void Nodo::put_suc(Nodo *p) {
  suc = p; 	       // determina il puntatore al nodo successore
}
