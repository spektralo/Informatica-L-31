
bool estrai_dalla_testa(lista& inizio, Tipo_elem& e) {
 

 if (inizio == NULL) return false;
 
  //lista è un puntatore ad un nodo (come definito nella classe Nodo)
 lista p = inizio;
 
 //restituisce una copia del contenuto di p
 e = p->get();
 
 //setto il nuovo inizio (primo nodo della lista)
 inizio = p->get_suc();
 
 //elimino il nodo
 delete p;
 return true;
}
