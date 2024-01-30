#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l),append(cdr(l),e));
}

TipoLista minimiLocaliAUX(TipoLista l, TipoLista ris) {
  	if (estVuota(l) || estVuota(cdr(l)) || estVuota(cdr(cdr(l)))) {return ris;}
	if (!estVuota(l) && !estVuota(cdr(l)) && !estVuota(cdr(cdr(l)))) {
    	T primo = car(l);
      	T secondo = car(cdr(l));
      	T terzo = car(cdr(cdr(l)));
      	if (primo >= secondo && secondo <= terzo) {
        	ris = append(ris,secondo);
        }
      	return minimiLocaliAUX(cdr(l),ris);
    }
  	return ris;
}

TipoLista minimiLocali(TipoLista l) {
  TipoLista ris = listaVuota();
  if (estVuota(l)) return ris;
  return minimiLocaliAUX(l,ris);
}

int sommaLista(TipoLista l) {
	if (estVuota(l)) return 0;
  	else return car(l)+sommaLista(cdr(l));
}

int massimaSommaMinimi(TipoLista* liste, int n){
  if (n==0) return 0;
  int max = -1;
  for (int i=0; i<n; i++) {
    TipoLista l = minimiLocali(liste[i]);
    int sum = sommaLista(l);
  	if (sum > max) {
    	max = sum;
    }
  }

  return max;
}
