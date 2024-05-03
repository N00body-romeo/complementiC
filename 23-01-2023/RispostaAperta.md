## *Domanda a risposta aperta*
Descrivere il concetto di costo dei programmi asintotico nel caso peggiore, la notazione O-grande e il suo utilizzo per confrontare il costo di due diversi programmi. Descrivere l'algoritmo di ordinamento merge-sort e discutere il suo costo asintotico. Fornire un esempio di esecuzione dell'algoritmo merge-sort, mostrando tutti i passi eseguiti sul seguente vettore di input: ```3 5 1 8 2 9 6 4```

## Costo asintotico dei programmi nel caso peggiore e notazione O-grande

Il **costo asintotico di un programma** nel caso peggiore rappresenta il comportamento del tempo di esecuzione del programma all'aumentare della dimensione dell'input, trascurando i termini costanti e i fattori minori. Questo ci permette di confrontare l'efficienza di diversi algoritmi per lo stesso problema, indipendentemente dalla specifica implementazione o dall'hardware utilizzato.

La notazione **O-grande** è uno strumento matematico utilizzato per descrivere il costo asintotico di un algoritmo. Si scrive O(f(n)), dove f(n) è una funzione che cresce più lentamente di qualsiasi funzione polinomiale di n. In altre parole, il costo del programma è limitato superiormente da f(n) per valori di input sufficientemente grandi.

Per esempio, se il tempo di esecuzione di un algoritmo è 3n^2 + 5n + 1, possiamo dire che il suo costo asintotico è O(n^2). Questo perché, per valori di n sufficientemente grandi, il termine dominante è 3n^2, mentre gli altri termini diventano insignificanti.

## Confronto del costo di due programmi

Per confrontare il costo di due programmi utilizzando la notazione O-grande, si identificano i termini dominanti delle rispettive funzioni di costo. Il programma con la funzione di costo con crescita più lenta è considerato più efficiente.

Ad esempio, se un programma ha costo O(n log n) e un altro ha costo O(n^2), il primo programma è considerato più efficiente per input di grandi dimensioni.

## Algoritmo di ordinamento Merge Sort

Il **Merge Sort** è un algoritmo di ordinamento efficiente che divide ricorsivamente l'input in sottogruppi più piccoli, li ordina e li fonde in un unico vettore ordinato. Il suo costo asintotico nel caso peggiore è **O(n log n)**.

**Esempio di esecuzione del Merge Sort sul vettore [3 5 1 8 2 9 6 4]:**

1. **Dividere:** Dividere l'array in due sottogruppi: [3 5 1 4] e [8 2 9 6].
2. **Conquistare:** Ricorsivamente applicare il Merge Sort su ogni sottogruppo: [1 3 4 5] e [2 6 8 9].
3. **Unire:** Fondere i due sottogruppi ordinati in un unico vettore ordinato: [1 2 3 4 5 6 8 9].

**Passaggi:**

- Dividere l'array in due metà finché non si ottengono sottogruppi con un solo elemento.
- Ordinare ogni sottogruppo utilizzando l'ordinamento elementare (ad esempio, Insertion Sort) per sottogruppi piccoli.
- Fondere ricorsivamente i sottogruppi ordinati in un unico vettore ordinato.

Il Merge Sort è un algoritmo efficiente e versatile utilizzato in diverse applicazioni di ordinamento. La sua efficienza asintotica lo rende una scelta popolare per ordinare grandi insiemi di dati.
