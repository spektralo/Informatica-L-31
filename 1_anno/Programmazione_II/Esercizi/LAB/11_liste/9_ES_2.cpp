/* Scrivere un algoritmo che accetti una lista concatenata, la attraversi
 * e restituisca il dato del nodo con il valore minore
* 
* void minore(lista& inizio, Tipo_elem& e)
* il minore è restituito in e
*/













void minore(lista& inizio, Tipo_elem e) {
	Tipo_elem minore;
	lista q = inizio;
	if (q) minore=q->get();
    while (q->succ != NULL) {
	  q = q->get_suc()
	  if (minore > q->get()) minore = q->get();
    }
    e = minore;
}


