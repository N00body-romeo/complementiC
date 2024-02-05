#include "aux.h"

int aux(TipoSCL scl, int count) {
	if (scl==NULL) return count;
  	if (scl->next!=NULL)
  	if ((scl->info)>((scl->next)->info)) { count++; }
  	return aux((scl->next), count);
}

int contaDecrescenti(TipoSCL lis){
	int count = 0;
  	return aux(lis,count);
}

int length(TipoSCL lis) {
	if (lis == NULL) return 0;
  	return 1+length(lis->next);
}

void addSCLaux(TipoSCL* scl, TipoInfoSCL e) {
	TipoNodoSCL* nuovoNodo = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));
  	nuovoNodo->info = e;
  	nuovoNodo->next = NULL;
  
  	if (*scl == NULL) { *scl = nuovoNodo; }
  	else {
    	TipoNodoSCL* ultimoNodo = *scl;
      	while (ultimoNodo->next!=NULL) {
        	ultimoNodo = ultimoNodo->next;
        }
      	ultimoNodo->next = nuovoNodo;
    }
}
 
TipoSCL addSCL(TipoSCL ris, TipoInfoSCL e) {
  	addSCLaux(&ris,e);
  	return ris;
}

int mergeSequenziale(TipoSCL lis1, TipoSCL lis2) {
	if (lis1==NULL && lis2!=NULL) return contaDecrescenti(lis2);
  	if (lis1!=NULL && lis2==NULL) return contaDecrescenti(lis2);
  	if (lis1==NULL && lis2==NULL) return 0;
  	
  	int len1 = length(lis1);
  	int len2 = length(lis2);
  	int lenRIS = len1+len2;
  	TipoSCL ris = NULL;
  	
  	while (lenRIS!=0) {
    	if (length(lis1)!=0) {
        	ris=addSCL(ris,lis1->info);
          	lis1 = lis1->next;
        }
      	if (length(lis2)!=0) {
        	ris=addSCL(ris,lis2->info);
          	lis2 = lis2->next;
        }
      	lenRIS--;
    }
  	int decrescenti = contaDecrescenti(ris); printf("decrescenti: %d\n",decrescenti);
  	return decrescenti;
  	
}
