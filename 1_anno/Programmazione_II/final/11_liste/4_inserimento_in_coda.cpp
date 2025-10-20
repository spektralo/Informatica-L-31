void inserisci_in_coda(lista& inizio, Tipo_elem e) {

 //punto "p" e "q" al primo nodo
 lista p, q = inizio;
 
 //identifica l'ultimo nodo ("p") utilizzando le informazioni sul nodo successivo (q != NULL) 
 while (q != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 
 q = new Nodo(e); // inizializza info ad e e suc a NULL
 
 //se ho una lista vuota pongo q come primo elemento,
 //diversamente lo pungo successivo a "p" (ultimo nodo)
 if (inizio == 0) inizio->put_suc(q);
     else p->put_suc(q);
}
