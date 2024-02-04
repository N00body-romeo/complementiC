
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int massimo(int a, int b) {
	return a > b ? a : b;
}

/*
           
         10 
       _/ \_   
      /     \  
     7       5 
     |           
    /            
   6 
*/
int discendenteMin(TipoAlbero a, TipoInfoAlbero* temp, int* dist, int distTemp) {
	if (estVuoto(a)) return *dist;
  	distTemp++;
  	if (a->info < *temp) {
      	printf("temp: %d\n",*temp);
      	printf("a->info: %d\n",a->info);
      	*temp = a->info;
      	*dist = distTemp;
    }
  	else if (a->info == *temp) {
      	if (distTemp > *dist) {
      		*dist = distTemp;
        }
    }
  	
	int sx = 0;
  	int dx = 0;
  
  	if (!estVuoto(sinistro(a))) {
    	sx = discendenteMin(sinistro(a),temp,dist,distTemp);
    }
  	if (!estVuoto(destro(a))) {
    	dx = discendenteMin(destro(a),temp,dist,distTemp);
    }
	printf("nodo: %d, discendenteMin: %d\n",a->info,*dist);
  	return *dist;
}

int discendente(TipoAlbero a) {
  	int temp = 99999;
  	int dist = -1;
	return discendenteMin(a,&temp,&dist,-1);
}

void aux(TipoAlbero a) {
  	
	//trovare ascendente max
  	//trovare discendente min
  	printf("discendenteMINIMO: %d\n",discendente(a));
  	
  	//modifica
  	return;
	
}	

void diffMinFogliaMaxAntenato(TipoAlbero a) {
	
  	aux(a);
}

