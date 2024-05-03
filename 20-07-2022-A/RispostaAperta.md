## *Domanda a risposta aperta*
Descrivere l'algoritmo di ordinamento merge-sort e discutere il suo costo asintotico. Discutere il costo dell'algoritmo rispetto alla configurazione dell'input e, se applicabile, qual è il caso peggiore per questo algoritmo. Fornire un esempio di esecuzione dell'algoritmo di ordinamento merge-sort, mostrando i passi eseguiti sul seguente array: [ 9 3 4 6 7 1 8 5 ]


## Algoritmo di ordinamento Merge Sort

Il **Merge Sort** è un algoritmo di ordinamento efficiente che utilizza il paradigma "divide et impera". Funziona dividendo ricorsivamente l'input in sottogruppi più piccoli, ordinandoli e poi fondendoli in un unico vettore ordinato. Il suo costo asintotico nel caso peggiore è di **O(n log n)**, dove n è la dimensione dell'input.

### Costo dell'algoritmo

Il costo del Merge Sort dipende dalla configurazione dell'input:

* **Caso migliore:** Se l'input è già ordinato, il costo è di **O(n)**, poiché l'algoritmo semplicemente verifica l'ordinamento e lo restituisce.
* **Caso medio:** Il costo medio è di **O(n log n)**, come già detto.
* **Caso peggiore:** Il caso peggiore si verifica quando l'input è ordinato in ordine inverso. In questo caso, il Merge Sort deve eseguire la massima quantità di confronti e fusioni, risultando in un costo di **O(n log n)**.

### Esempio di esecuzione

Consideriamo l'array di input: **[9 3 4 6 7 1 8 5]**.

**1. Dividere:** 
Dividiamo l'array a metà in due sottogruppi:

* Sinistro: [9 3 4]
* Destro: [6 7 1 8 5]

**2. Conquistare:** 
Applichiamo ricorsivamente il Merge Sort su entrambi i sottogruppi:

* Sinistro: [3 4 9] (ordinato)
* Destro: [1 5 6 7 8] (ordinato)

**3. Unire:** 
Fondiamo i due sottogruppi ordinati in un unico vettore ordinato:

* [1 3 4 5 6 7 8 9]

**Passaggi:**

1. Dividere l'array in due metà finché non si ottengono sottogruppi con un solo elemento.
2. Ordinare ogni sottogruppo ricorsivamente utilizzando il Merge Sort.
3. Fondere i sottogruppi ordinati in un unico vettore ordinato utilizzando il confronto e la fusione.
