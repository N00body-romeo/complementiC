#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l), append(cdr(l),e));
}

TipoLista removeHead(TipoLista l) {
	if (estVuota(l)) return listaVuota();
  	l = cdr(l);
  	return l;
}

void modificaLista(TipoLista* l, int k) {  
  	if (estVuota(*l) || k==0) return;
  	T elem = car(*l);
  	*l = removeHead(*l);
  	*l = append(*l, elem);
  	return modificaLista(l,k-1);
}


double mediaSommaPesataModificaListe(TipoLista* liste, int* v, int n){
  double SUM = 0.0;
  for (int i=0; i < n; i++) {
  	TipoLista* l = &liste[i];
    int k = v[i];
    modificaLista(l,k);
    //printf("lista\n"); printlist(*l);
    double sum = 0.0;
    int indice = 1;
    while(*l) {
      sum += car(*l)*indice;
      *l = cdr(*l);
      indice++;
    //  printf("sum = %d\n", sum);
    }
    SUM += sum;
    //printf("SUM = %d\n\n", SUM);
  }
  double media = SUM/(double)n;
  return media;
}
