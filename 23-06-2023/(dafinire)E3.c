
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoAlbero aux(TipoAlbero a, int k, int somma, TipoAlbero ris) {
  	//controlla se vuoto
  	if (estVuoto(a)) return albBinVuoto();
  	//printf("nodo: %d\n",radice(a));
/*
         1 
       _/ \_   
      /     \  
     7       8 
     |       |   
    /       / \  
   1       8   2 
   
*/
	somma += radice(a);
  	if (somma<=k) {
      	//printf("somma<=k\n");
  		ris->info = a->info;
    }
  	else {
      	//printf("somma > k\n");
    	ris->info = 0;
    }
  	if (!estVuoto(sinistro(a))) {
  		aux(sinistro(a),k,somma,ris);
    }
  	if (!estVuoto(destro(a))) {
  		aux(destro(a),k,somma,ris);
    }
  	//printf("somma: %d\n",somma);
  	
  	
  	return ris;
  	
}

TipoAlbero limita_albero(TipoAlbero a, int k) {
	TipoAlbero ris = creaAlbBin(radice(a),sinistro(a),destro(a));
  	return aux(a,k,0,ris);
}
