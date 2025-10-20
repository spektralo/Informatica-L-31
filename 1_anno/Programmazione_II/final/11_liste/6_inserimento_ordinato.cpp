void inserisci_ordinatamente(lista& inizio, Tipo_elem e) {
 lista r, p = NULL, q = inizio;
 
 //step che identifica (in un array già ordinato) l'elemento precedente "p" a quello
 // da inserire e quello sucessivo "q" se ci sono
 while ((q != NULL) && (q->get() < e)) {
	 p = q;
	 q = q->get_suc();
 }
 
 //creo il nodo inserendo "q" come il suo successivo
 r = new Nodo(e,q);
 
 
 if (q == inizio) inizio = r;  // se si deve inserire in testa
     else p->put_suc(r); //divesamente setto r come siccessivo a p
}
