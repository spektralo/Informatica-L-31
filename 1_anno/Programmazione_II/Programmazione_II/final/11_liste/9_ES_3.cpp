// Esercizio
/* Scrivere un programma che scambi due nodi di una lista concatenata. I nodi si
identificano per numeri e si passano come parametri. Per esempio, per scambiare i
nodi 5 e 8 si deve invocare scambio(5, 8) . Se lo scambio si realizza con successo, si
restituisce vero; se si produce un errore, come un numero di nodo non valido, si 
restituisce falso.
*/












bool scambia(lista& inizio, Tipo_elem a, Tipo_elem b) {
	lista p, pp, q = inizio, qq = inizio;
	while ((q != NULL) && (q->get() != a)) {
		p = q;
		q = q->get_suc();
	 }	
	 if (q == NULL) return false;   // l'elemento non è stato trovato
	 while ((qq != NULL) && (qq->get() != b)) {
		 pp = qq;
		 qq = qq->get_suc();
		 }		
	if (qq == NULL) return false;   // l'elemento non è stato trovato
	Tipo_elem aux = q->get();
	q->put(qq->get());
	qq->put(aux);
	return true;
}

