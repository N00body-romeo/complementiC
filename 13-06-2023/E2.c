/*****************************************************
DA FINIRE E' SENZA LOGICA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l),append(cdr(l),e));
}

void modificaListaAUX(TipoLista* l, int k) {
  	if (estVuota(*l)) return;
  	if (estVuota(cdr(*l)) || k==0) return;
	if (k>0) { 
      *l = append(cdr(*l),car(*l));
    }
  	modificaListaAUX(l,k-1);
}

void modificaLista(TipoLista* l, int k) {
      modificaListaAUX(l,k); }

int trovaElemAUX(TipoLista l, int n) {
	if (estVuota(l)) return n;
  	if (!estVuota(cdr(l))) trovaElemAUX(cdr(l),n+1);
  	return n;
}

int trovaElem(TipoLista l) {
  	int n = 0;
	return trovaElemAUX(l,n);
}

double sommaElemAUX (TipoLista l, int n, double somma) {
  	if (estVuota(l) || n==0) return somma;
  	somma+=car(l); printf("SOMMA: %f",somma);
  	return sommaElemAUX(cdr(l),n-1,somma);
}

double sommaElem (TipoLista l) {
	double somma = 0.0;
  	int n = trovaElem(l);
  	printf("sommaElem: %d x %d\n",car(l),n);
  	return sommaElemAUX(l,n,somma);
}

double mediaSommaPesataModificaListe(TipoLista* liste, int* v, int n){
  double somma = 0.0;
  for (int i=0; i<n; i++) {
    int k = v[i];
  	TipoLista l = liste[i];
    modificaLista(&l,v[i]);
    printf("l modificata:\n"); printlist(l);
    somma += sommaElem(l); printf("somma: %f\n",somma);
  }
  return somma/n;
}
