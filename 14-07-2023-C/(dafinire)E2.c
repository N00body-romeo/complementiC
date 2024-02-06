#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) { //per creare output e prefisso
	if (estVuota(l)) return cons(e,l);
  	return cons(car(l),append(cdr(l),e));
}

T trovaMax(TipoLista l, T max) { //serve per il prefisso
	if (estVuota(l)) return max;
  	if (max < car(l)) { max = car(l); }
  	return trovaMax(cdr(l),max);
}

T somma(TipoLista l, T s) { //serve per la coda
	if (estVuota(l)) return s;
  	s+=car(l);
  	return somma(cdr(l),s);
}

TipoLista aux(TipoLista l, TipoLista output, TipoLista precedenti) {
	if (estVuota(l)) { return output; }
  	T massimo_precedenti = trovaMax(precedenti,0);
  	if (!estVuota(cdr(l))) {
    	precedenti = append(precedenti,car(l));
    }
  	int media = 0;
  	if (length(cdr(l)) != 0) {
  		media = (somma(cdr(l),0))/length(cdr(l));
    }
  	output = append(output,massimo_precedenti-media);
  	return aux(cdr(l),output,precedenti);
}

TipoLista mediaMenoMax(TipoLista l) {
  	TipoLista precedenti = listaVuota();
	TipoLista output = listaVuota();
  	return aux(l,output,precedenti);
}

int trovaCar(TipoLista l, int ind,int cont){
  if(ind==cont){return car(l);}
  return trovaCar(cdr(l),ind,cont+1);
}

int* massimiElementi(TipoLista* liste, int n) {
	int* array = (int*) calloc(n,sizeof(int));
  	for (int i=0; i<n; i++) {
    	TipoLista l = mediaMenoMax(liste[i]);
      	int len = length(l);
      	printf("lista i-esima: %d: ",i); printlist(l);
      	for (int j=0; j<len; j++) {	
          	int car = trovaCar(l,j,0);
          	
          	if (array[j] == 0 && car != 0) { array[j] = car; }
          	else if (array[j] == 0 && car <= 0) { array[j] = 0; }
        	else if (array[j]!=0 && car >= array[j]) { array[j] = car; }
        }
    }
  	return array;
}
