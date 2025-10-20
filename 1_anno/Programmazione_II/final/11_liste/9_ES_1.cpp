/* Scrivere una funzione che conti il numero di volte che una determinata
chiave si ripete in una lista sequenziale 
*/














int conta_elem_dato(lista& inizio, Tipo_elem& e) {
	int cont=0;
	lista q = inizio;
    while (q != NULL) {
	  if (e==q->get()) cont++;
	  q = q->get_suc();
    }
    return cont;
}

