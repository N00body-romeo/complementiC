#include "aux.h"

TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) return cons(e,l);
	return cons(car(l),append(cdr(l),e));  	
}

TipoLista aux(TipoLista l, TipoLista temp, TipoLista ris) {
	if (estVuota(l)) return listaVuota();
  	if (!estVuota(cdr(l))) {
      ris = append(ris,car(cdr(l)));
  		return aux(cdr(l),temp,ris);
    }
	else ris = append(ris,car(temp));
  	return ris;
}

TipoLista ruota(TipoLista l) {
	if (estVuota(l)) return listaVuota();
  	TipoLista ris = listaVuota();
  	TipoLista temp = l;
  	return aux(l,temp,ris);
}

TipoLista copia(TipoLista l, TipoLista ris) {
	if (estVuota(l)) return ris;
  	return copia(cdr(l),append(ris,car(l)));
}

TipoLista combaux(TipoLista l, int p, TipoLista ris) {
	if (estVuota(l)) return ris;
 
      if (p!=car(ris)) {
      	ris = ruota(ris);
      }
      else {
      	return ris; //ritorna ris
      }
  
    return combaux(l,p,ris);
}

TipoLista combinazione(TipoLista lucchetto, int password) {
  TipoLista ris = copia(lucchetto,listaVuota());
  return combaux(lucchetto, password, ris);
}
