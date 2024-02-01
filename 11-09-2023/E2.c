#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista append(TipoLista l, T e) {
  if (estVuota(l)) return cons(e,l);
  return cons(car(l),append(cdr(l),e));
}

TipoLista sommeDueADueAUX(TipoLista l, TipoLista temp, TipoLista output) {
	if (estVuota(l)) {return output;}
  
  	if (!estVuota(cdr(l))) {
    	T primo = car(l);
      	T secondo = car(cdr(l));
      
      	output = append(output,primo+secondo);
      
      return sommeDueADueAUX(cdr(cdr(l)),temp,output);
    }
  	if (!estVuota(output) && estVuota(cdr(l))) {
      	T primo = car(l);
      	output = append(output,car(temp)+primo);
    }
 	if (estVuota(cdr(l)) && estVuota(output)) { return cons(car(l)*2,l);}
 
	return output;
}

TipoLista sommeDueADue(TipoLista l) {
	TipoLista output = listaVuota();
  	TipoLista temp = l;
  	return sommeDueADueAUX(l,temp,output);
}

int lunghezzaAUX(TipoLista l, int n) {
	if (estVuota(l)) return n;
  	return lunghezzaAUX(cdr(l),n+1);
}

int lunghezza(TipoLista l) {
	int n = 0;
  	return lunghezzaAUX(l,n);
}

double media(TipoLista l) {
	if (estVuota(l)) return 0.0;
  	double lung = (double)lunghezza(l);
  	return (double)sommaLista(l)/lung;
}

double* mediaSommeDueADue(TipoLista* liste, int n){
  	double* array = (double*)malloc(n*sizeof(double));
	for (int i=0; i<n; i++) {
    	TipoLista l = sommeDueADue(liste[i]);
      	double m = media(l);
      	array[i] = m;
    }
  	return array;
}
