
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

typedef struct {
	int pari_count;
  	int somma;
} Risultato;

int max(int a, int b) { return (a > b) ? a : b; }

Risultato AUXcammino_pari(TipoAlbero a) {
	if (estVuoto(a)) {
    	Risultato r = {0,0};
      	return r;
    }
  
  	int valore_corrente = radice(a);
  	int count = (valore_corrente % 2 == 0) ? 1:0;
  	
  	Risultato sx = AUXcammino_pari(sinistro(a));
  	Risultato dx = AUXcammino_pari(destro(a));
  
  	Risultato migliore;
  	if (sx.pari_count > dx.pari_count) {
    	migliore = sx;
    }
  	else if (sx.pari_count < dx.pari_count) {
    	migliore = dx;
    }
  	else { migliore = (sx.somma >= dx.somma) ? sx : dx; }
  
  	migliore.pari_count += count;
  	migliore.somma += valore_corrente;
  	
  	return migliore;    
}

int cammino_pari(TipoAlbero a) {
	Risultato r = AUXcammino_pari(a);
  	return r.somma;
}

/* IMPLEMENTAZIONE CORRETTA, MA TROPPO MACCHINOSA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int max(int a, int b) {
    return a > b ? a : b;
}

void cammino_pari_aux(TipoAlbero a, int somma, int num_pari, int *max_sum, int *max_num_pari) {
    if (estVuoto(a)) {
        if (num_pari > *max_num_pari || (num_pari == *max_num_pari && somma > *max_sum)) {
            *max_sum = somma;
            *max_num_pari = num_pari;
        }
        return;
    }
    
    somma += radice(a);
    num_pari += radice(a) % 2 == 0 ? 1 : 0;
    
    cammino_pari_aux(sinistro(a), somma, num_pari, max_sum, max_num_pari);
    cammino_pari_aux(destro(a), somma, num_pari, max_sum, max_num_pari);
}

int cammino_pari(TipoAlbero a) {
    int max_sum = 0;
    int max_num_pari = 0;
    
    cammino_pari_aux(a, 0, 0, &max_sum, &max_num_pari);
    
    return max_sum;
}
*/
