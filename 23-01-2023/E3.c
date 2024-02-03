/******************************
  IL PRIMO TEST NON FUNZIONA
******************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int conta_pari(TipoAlbero a){
  if (estVuoto(a)) return 0;
  if (a->info % 2==0)
    return 1+conta_pari(sinistro(a))+conta_pari(destro(a));
  return conta_pari(sinistro(a))+conta_pari(destro(a));
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int cammino_pari(TipoAlbero a) {
    if (estVuoto(a)) return 0;
    
    int nodiPari = conta_pari(a);
    int nodiPariSinistro = conta_pari(sinistro(a));
    int nodiPariDestro = conta_pari(destro(a));
    
    if (nodiPari == 0 || nodiPariSinistro == nodiPariDestro) {
        return a->info + max(cammino_pari(sinistro(a)), cammino_pari(destro(a)));
    }
    
    TipoAlbero percorso = (nodiPariSinistro > nodiPariDestro) ? sinistro(a) : destro(a);
    
    return a->info + cammino_pari(percorso);
}
