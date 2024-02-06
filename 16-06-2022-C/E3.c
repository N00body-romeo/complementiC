#include "aux.h"

void nodoDivisibile(TipoAlbero a) {
  /*
         4 
       _/ \_   
      /     \  
     2       3 
     |       |   
    /       /    
   6       1 
   
   */
  
    if (estVuoto(a)) return;
  	if (!estVuoto(sinistro(a))) {
      	printf("nodo: %d, nodo_sx: %d\n",radice(a),radice(sinistro(a)));
      	
      	if (radice(sinistro(a))!=0) {
        	if (radice(a)%radice(sinistro(a))==0) {
          		printf("divisibile eheheh\n");
    			    a->info = 1;
    		  }
        }
      	nodoDivisibile(sinistro(a));
    }
  	if (!estVuoto(destro(a))) {
      	printf("nodo: %d, nodo_dx: %d\n",radice(a),radice(destro(a)));
      	
      	if (radice(destro(a))!=0) {
        	if (radice(a)%radice(destro(a))==0) {
          		printf("divisibile eheheh\n");
    			    a->info = 1;
    		  }
        }
      	nodoDivisibile(destro(a));
    }
    return;
}


