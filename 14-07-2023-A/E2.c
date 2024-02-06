#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l),append(cdr(l),e));
}

TipoLista suffissiCrescentiAUX(TipoLista l, TipoLista suffissi) {
	if (estVuota(l)) return suffissi;	
  	if (!estVuota(cdr(l))) {
      if (car(l) <= car(cdr(l))) {
          suffissi = append(suffissi,car(l));
      }
      else {
      	suffissi = listaVuota();
      }
    }
  	else if (suffissi = append(suffissi,car(l)));
  	return suffissiCrescentiAUX(cdr(l),suffissi);
}

TipoLista suffissiCrescenti(TipoLista l) {
	TipoLista ris = listaVuota();
  	if (estVuota(l)) return ris;
  	return suffissiCrescentiAUX(l,ris);
}

TipoLista aux(TipoLista l, TipoLista output, int sommaSuff, int sommaPref) {
  	if (estVuota(l)) return output;
  	if (estVuota(output) && !estVuota(l)) {
      output = append(output,-sommaSuff);
    }
	if (!estVuota(cdr(l))) {  	
      sommaPref+=car(l);
      output = append(output,sommaPref-sommaSuff);
    }
  	return aux(cdr(l),output,sommaSuff,sommaPref); 
}

TipoLista precedentiMenoSuffisso(TipoLista l) {
  	TipoLista output = listaVuota();
	if (estVuota(l)) return output;
  	TipoLista suffissi = suffissiCrescenti(l);
  	int sommaSuffissi = sommaLista(suffissi);
  	int sommaPref = 0;
  	return aux(l,output,sommaSuffissi,sommaPref);
}


double* mediaPrecedentiMenoSuffisso(TipoLista* liste, int n){
	double* array = (double*)calloc(n,sizeof(double));
  	for (int i=0; i<n; i++) {
    	TipoLista l = precedentiMenoSuffisso(liste[i]);
      	array[i] = (double)sommaLista(l)/length(l);
    }
  	return array;
}

