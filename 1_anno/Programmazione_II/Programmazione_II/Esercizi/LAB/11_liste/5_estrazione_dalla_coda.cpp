bool estrai_dalla_coda(lista& inizio, Tipo_elem& e) {

 //punto "p" e "q" al primo nodo
 lista p, q = inizio;
 
 //se la lista è vuota return false
 if (inizio == NULL) return false;
 
 //identifica l'ultimo nodo ("q") mantenendo le info sul penultimo ("p")
 while (q->get_suc() != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 
 //ottengo le info dell'ultimo nodo
 e = q->get();
 
 //se q corrisponde al primo nodo setta la lista come vuota (inizio = NULL)
 //diversamente setta il successivo di p come null
 if (q == inizio) inizio = NULL; // se si estrae il primo elemento
     else p->put_suc(NULL);
     
//elimina il nodo
 delete q;
 return true;
}
