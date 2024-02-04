
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

void aux(TipoAlbero a, int k, TipoAlbero b, int* somma) {
	
  	if (estVuoto(sinistro(a)) && estVuoto(destro(a))) {
      	printf("nodo: %d, somma: %d\n",a->info, *somma);
      	if ((*somma)%k==0) {
  			a->info += k;
  		}  
  		else {
    		a->info -= k;
    	}
    	return;	
    }
  
  	*somma += a->info;

  	if (!estVuoto(sinistro(a))) {
  		aux(a->sinistro, k, b,somma);
    }
  	if (!estVuoto(destro(a))) {
    	aux(a->destro,k,b,somma);
    }
  	*somma -= a->info;
  	printf("nodo: %d, somma: %d\n",a->info, *somma);
  	
  	  	
  	if ((*somma)%k==0) {
  		a->info += k;
  	}  
  	else {
    	a->info -= k;
    }
  
  	
}

void cambiaNodoDalCammino(TipoAlbero a, int k) {
	if (!estVuoto(a)) {
      	TipoAlbero b = albBinVuoto();
      	int somma = 0;
  		aux(a,k,b,&somma);
    }
  	return;
}
