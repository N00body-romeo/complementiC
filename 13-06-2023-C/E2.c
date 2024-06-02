#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l),append(cdr(l),e));
}

TipoLista AUX(TipoLista l, TipoLista output, int k, int len_output) {
    if (len_output == 0) return output;

    TipoLista somma = listaVuota();
    for (int i = 0; i < k; i++) {
        if (!estVuota(l)) {
            somma = cons(car(l), somma);
            l = cdr(l);
        } else {
            somma = cons(0, somma); // Aggiungiamo 0 se la lista è finita
        }
    }
    
    int sum = sommaLista(somma);
    output = append(output, sum);
    return AUX(l, output, k, len_output - 1);
}

TipoLista convoluzione(TipoLista l, int k) {
    if (estVuota(l)) return listaVuota();
    
    int len = length(l);
    int len_output = (len + k - 1) / k; // Parte intera superiore di len / k

    return AUX(l, listaVuota(), k, len_output);
}

int maxAUX(TipoLista l, int max) {
  	if (estVuota(l)) return max;
	int elem = car(l);
  	if (elem > max) {
    	max = elem;
    }
  	max = maxAUX(cdr(l),max);
  	return max;
}

int max(TipoLista l) {
	int m = 0;
  	return maxAUX(l,m);
}

int* maxPooling(TipoLista* liste, int* v, int n){
  int* output = (int*) malloc(sizeof(int)*n);
  for (int i=0; i<n; i++) {
  	int k = v[i];
    TipoLista l = liste[i];
    TipoLista result = convoluzione(l,k);
    int maximo = max(result);
    output[i] = maximo;
  }
  
  return output;
}
