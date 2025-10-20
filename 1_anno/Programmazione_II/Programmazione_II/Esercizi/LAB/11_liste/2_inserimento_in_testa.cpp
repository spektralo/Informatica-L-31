


void inserisci_in_testa(lista& inizio, Tipo_elem e) {
   lista nuovo = new Nodo(e, inizio);   // genera nuovo Nodo
   inizio = nuovo ;               // inizio punta il nuovo Nodo
}
