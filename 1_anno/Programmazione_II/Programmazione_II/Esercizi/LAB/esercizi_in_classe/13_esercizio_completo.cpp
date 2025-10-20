/*Si realizzi una classe  Classifica organizzata come una lista ordinata. 
Gli elementi della lista siano di tipo SortableElem, definto nel modo seguente:*/
const int NMAX = 50 ;
typedef char Nome [NMAX] ; //Nome delle squadre
typedef struct {
	Nome n ; 	unsigned int punteggio ;
} Squadra ;
typedef Squadra SortableElem;
/*Metodi pubblici da implementare per la classe Classifica.
1.Classifica(): costruttore.   
2. ~Classifica(): distruttore.
3. unsigned int Aggiungi (Nome, unsigned int): se la squadra non è presente, la aggiunge alla struttura 
e le assegna un punteggio. Nel caso di squadra già presente, aggiunge il punteggio a quello presente.
Restituisce il numero di punti correntemente totalizzati dalla squadra.
4. Svuota(): Svuota la struttura.
5. Stampa():Stampa la classifica delle squadre presenti nella struttura, in ordine 
decrescente di punteggio.
6. unsigned int Count() : conta gli elementi contenuti nella struttura.
7. Elimina (const Nome& n): elimina dalla struttura un eventuale elem. avente nome pari
  ad n. In caso di esistenza ne restituisce il punteggio , altrimenti restituisce 0

Consegne;
- (cout) può essere usato solo sul metodo Stampa(). 

- Si realizzi una funzione main() che permetta di effettuare il collaudo della
struttura dati realizzata.

- IMPORTANTE: il referimento al "successivo" non va inserito nella struct Squadra!

