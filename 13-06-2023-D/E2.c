#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista append(TipoLista l, T e) {
    if (estVuota(l)) return cons(e, l);
    return cons(car(l), append(cdr(l), e));
}


TipoLista ultimiK(TipoLista l, int k) {
    if (k == 0 || estVuota(l)) return listaVuota();
    int len = length(l);
    if (len <= k) return l;
    return ultimiK(cdr(l), k);
}

TipoLista primiK(TipoLista l, int k) {
    if (k == 0 || estVuota(l)) {
        return listaVuota();
    } else {
        T primoElemento = car(l);
        TipoLista restoLista = primiK(cdr(l), k - 1);
        return cons(primoElemento, restoLista);
    }
}

TipoLista porzioneDiListe(TipoLista l1, TipoLista l2, int k) {
    if (k == 0) return listaVuota();
    TipoLista output = primiK(l1, k);
    TipoLista ultimi = ultimiK(l2, k);
    while (!estVuota(ultimi)) {
        output = append(output, car(ultimi));
        ultimi = cdr(ultimi);
    }
    return output;
}



TipoLista diffPorzioniDiListe(TipoLista* liste1, TipoLista* liste2, int n, int k) {
	TipoLista output = listaVuota();
  	if (n == 0) return output;
  	for (int i=0; i<n; i++) {
      	int somma1 = 0;
        int somma2 = 0;
      	if (k!=0) {
          TipoLista L1 = liste1[i];
          TipoLista lista1 = listaVuota(); 
          lista1 = primiK(L1,k);
          
          TipoLista L2 = liste2[i];
          TipoLista lista2 = listaVuota();
          lista2 = ultimiK(L2,k);
          
          somma1 = sommaLista(lista1);
          somma2 = sommaLista(lista2);
        }
      	int differenza = somma1-somma2;
      	output = append(output,differenza);
    }
  	return output;
}
