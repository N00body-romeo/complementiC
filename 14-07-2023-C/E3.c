
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoAlbero aux(TipoAlbero a, TipoAlbero ris, int antenato, int dist) {
	if (estVuoto(a)) return ris;
  	if (estVuoto(sinistro(a)) && estVuoto(destro(a)) && ris == NULL) { //solo un nodo
    	ris = creaAlbBin(a->info,NULL,NULL);
      	return ris;
    }
  	
  	//antenato
  	if (ris==NULL) {
  		ris = creaAlbBin(a->info,NULL,NULL);
    }
  	if (antenato > a->info) {antenato = radice(a); dist = 1;}
  	else {
    	dist++;
    }
  	
  	if (!estVuoto(sinistro(a))) {
    	ris->sinistro = creaAlbBin((sinistro(a)->info)+dist,NULL,NULL);
      	aux(sinistro(a),sinistro(ris),antenato,dist);
    }
  	else {
    	ris->sinistro = NULL;
    }
  	if (!estVuoto(destro(a))) {
    	ris->destro = creaAlbBin((destro(a)->info)+dist,NULL,NULL);
      	aux(destro(a),destro(ris),antenato,dist);
    }
  	else {
    	ris->destro = NULL;
    }
  	return ris;
    	 
}

TipoAlbero sommaDistMinAntenato(TipoAlbero a) {
	TipoAlbero ris = NULL;
	return aux(a,ris,9999,0);
}

