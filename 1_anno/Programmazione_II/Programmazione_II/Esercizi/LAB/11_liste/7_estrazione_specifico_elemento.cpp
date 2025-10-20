bool estrai_elem_dato(lista& inizio, Tipo_elem e) {
	//"p" e "q" settati a inizio
	lista p, q = inizio;
	
//identifico l'elemeneto uguale ad "e" ("q") ed il suo precedente "p"
while ((q != NULL) && (q->get() != e)) {
	 p = q;
	 q = q->get_suc();
 }		
 if (q == NULL) return false;   // l'elemento non è stato trovato
 if (q == inizio) inizio = q->get_suc();   // l'elemento cercato era il primo
     else p->put_suc(q->get_suc()); // aggiornamento successivo di p
 e = q->get();
 
//elimino q
 delete q;
 return true;
}
