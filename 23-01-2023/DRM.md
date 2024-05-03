**Domande a risposta multipla - 23/01/2023**

**Domanda 1**
Si consideri il seguente programma C:
```
#include <stdio.h>
#include <stdlib.h>

int* g(){
	int a = 10;
	return &a;
}

int main() {
	int* x = g();
	printf("%d\n",*x);
	free(x);
}
```

Una sola delle seguenti affermazioni è vera. Quale?

A. La funzione ```g()``` causa un errore a tempo di compilazione. \
B. La funzione ```main()``` causa un errore a tempo di esecuzione. \
C. L'esecuzione della funzione ```main()``` termina correttamente. \
D. La funzione ```g()``` viene compilata correttamente ma la funzione ```main()``` causa un errore a tempo di compilazione.

**Risposta:** B. La funzione ```main()``` causa un errore a tempo di esecuzione. \
**Spiegazione:** Sebbene la funzione ```g()``` venga eseguita correttamente e restituisca l'indirizzo di una variabile valida, la funzione ```main()``` tenta di liberare la memoria allocata da ```g()``` utilizzando la funzione ```free()```. Tuttavia, la memoria allocata da ```g()``` è allocata sulla pila, non sul heap. La funzione ```free()``` è progettata per liberare la memoria allocata sul heap, non sulla pila. Di conseguenza, la chiamata a ```free(x)``` nella funzione ```main()``` causa un errore a tempo di esecuzione noto come "errore di accesso alla memoria non valida" o "segfault".

-----------------------------------------------------------------------------------------------------

Si considerino la seguente definizione di SCL:
```
#include <stdlib.h>
typedef int TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL* next;
};
typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL* TipoSCL;
```
e la seguente funzione:
```
void addSCL(TipoSCL scl, TipoInfoSCL v){
	TipoSCL new_scl = (ElemSCL*) malloc(sizeof(struct ElemSCL));
	new_scl -> info = v;
	new_scl -> next = NULL;
	if (scl == NULL){
		scl = new_scl;
	}
	else{
		while (scl -> next != NULL){
			scl = scl -> next;
		}
		scl -> next = new_scl;
	}
}
```

Una sola delle seguenti affermazioni è vera. Quale?

A. La funzione addSCL effettua correttamente l'inserimento dell'elemento v in testa alla SCL di input.\
B. La funzione addSCL effettua correttamente l'inserimento dell'elemento v in coda alla SCL di input.\
C. La funzione addSCL effettua correttamente l'inserimento dell'elemento v in coda alla SCL di input, solo se questa è non vuota.\
D. La funzione addSCL non può modificare in alcun modo la SCL di input.

**Risposta:** B. La funzione addSCL effettua correttamente l'inserimento dell'elemento v in coda alla SCL di input.\
**Spiegazione:**\
La funzione addSCL prende due parametri:
- ```scl``` : Un puntatore a una struttura ElemSCL che rappresenta l'inizio della SCL di input.
- ```v``` : Il valore intero da inserire nella SCL.

**La funzione esegue i seguenti passaggi:**
1) Alloca memoria sulla heap per una nuova struttura ```ElemSCL``` utilizzando la funzione ```malloc()```.
2) Assegna il valore di ```v``` al campo info della nuova struttura.
3) Imposta il campo ```next``` della nuova struttura a NULL, indicando che è l'ultimo elemento della SCL.
4) Se la SCL di input è vuota (cioè ```scl == NULL``` ), la nuova struttura viene impostata come primo elemento della SCL e il puntatore scl viene aggiornato per puntare alla nuova struttura.
5) Se la SCL di input non è vuota, la funzione esegue un ciclo ```while``` che percorre la SCL fino a trovare l'ultimo elemento (cioè quello con ```next == NULL``` ). Una volta trovato l'ultimo elemento, il campo ```next``` di tale elemento viene aggiornato per puntare alla nuova struttura, inserendola in coda alla SCL.

-----------------------------------------------------------------------------------------------------

Si considerino la seguente rappresentazione collegata di alberi binari:

```#include <stdio.h>
#include <stdlib.h>
typedef int TipoInfoAlbero;
struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero *sinistro, *destro;
};
typedef struct StructAlbero TipoNodoAlbero;
typedef TipoNodoAlbero* TipoAlbero;
```
e la seguente funzione:
```
void stampaPari(TipoAlbero a){
	if (a == NULL){
		return;
	}
	if (a -> info % 2 == 0){
		printf("%d ", a -> info);
		return;
	}
	if (a -> sinistro != NULL){
		stampaPari(&(a.sinistro));
	}
	if (a -> destro != NULL){
		stampaPari(&(a.destro));
	}
}
```

Una sola delle seguenti affermazioni è vera. Quale?

A. La funzione stampaPari genera un errore a tempo di esecuzione.
B. La funzione stampaPari stampa correttamente il contenuto dei nodi di a aventi valore pari.
C. Se l'albero a è non vuoto ed il nodo radice contiene un valore pari, la funzione stampaPari stampa esclusivamente il contenuto del nodo radice.
D. La funzione stampaPari causa un errore a tempo di compilazione.

**Risposta:** B. La funzione stampaPari stampa correttamente il contenuto dei nodi di a aventi valore pari.
**Spiegazione:** La funzione ```stampaPari``` esegue una traversata ricorsiva in ordine simmetrico dell'albero binario rappresentato da ```a```. La funzione visita ogni nodo dell'albero e stampa il valore del nodo se questo è pari.\
Analisi del codice passo passo:
1) Se a è nullo, la funzione ritorna immediatamente. Ciò significa che il nodo corrente è nullo e non ci sono altri nodi da visitare.
2) Se il valore del nodo corrente (```a->info```) è pari, la funzione stampa il valore e ritorna. Questo stampa il valore del nodo corrente e termina la ricorsione per quel ramo dell'albero.
3) Se il nodo sinistro (```a->sinistro```) non è nullo, la funzione richiama ricorsivamente ```stampaPari``` sul nodo sinistro. Questo fa sì che la funzione visiti il sottoalbero sinistro dell'albero corrente.
4) Se il nodo destro (```a->destro```) non è nullo, la funzione richiama ricorsivamente ```stampaPari``` sul nodo destro. Questo fa sì che la funzione visiti il sottoalbero destro dell'albero corrente.
