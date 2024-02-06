#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* trasponi(Mat* m) {
  	Mat* ris = mat_alloc(m->rows, m->cols);
	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	ris->mat[i][j] = m->mat[j][i];
        }
    }
  	return ris;
}

int trovaDiagonale(Mat *m) {
	int diagonale = 0;
  	for (int i=0; i<m->rows; i++) {
   		for (int j=0; j<m->cols; j++) {
       		if (i==j) { diagonale += m->mat[i][j];}
        }
   	}
  	return diagonale;
}

Mat* trasponi_e_massima_diagonale(Mat* m) {
	int max = -1;
  	int N = m->rows/2;
  	Mat* trasposta = trasponi(m);
  	Mat* ris = NULL;
  	for (int i=0; i<=N; i++) {
   		for (int j=0; j<=N; j++) {
      		Mat* sottomatrice = mat_alloc(N,N);
          	for (int x=0; x<N; x++) {
            	for (int y=0; y<N; y++) {
       				sottomatrice->mat[x][y] = trasposta->mat[x+i][y+j];
                }
            }
      		int diagonale = trovaDiagonale(sottomatrice);
      		if (diagonale > max) {
              	max = diagonale;
          		if (ris != NULL) { 
              		mat_free(ris);
            	}
            	ris = mat_alloc(N,N);
              	
              	for (int i=0; i<N; i++) {
                	for (int j=0; j<N; j++) {
                    	ris->mat[i][j] = sottomatrice->mat[i][j];
                    }
                }
      			mat_free(sottomatrice);
            }
        }
   	}
  	return ris;
}
