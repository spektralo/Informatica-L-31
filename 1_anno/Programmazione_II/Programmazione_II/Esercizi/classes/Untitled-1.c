







/* inv [] = 
la funzione inv su input di forma [], ossia stringa vuota, 
ricordando che una string in Haskell è una list di caratteri*/

e : l
/*argomento e, lista di elementi l 
4 : [2,5] e restituisce [4,2,5] dominio -> codominio

inv (a : y) = (inv y), ossia inverso di lista y concatenato con carattere "a"
inv (a : y)++[a], dove [a] è la lista di caratteri, mentre ++ è l'operatore
di concatenazione per stringhe. notiamo anche la natura ricorsiva della funzione.
*/

/*funzione fattoriale (fact):
fact 0 = 1
fact n = n*(fact (n-1))
*/

/*funzione somma
somma [] = 0
somma (n:ns) = n + (somma ns)
*/
