#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

float calcolaMedia(Mat *m) {
	if (m==NULL) {
    	return 0.0;
    }
  	float media = 0.0;
  	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	media += m->mat[i][j];
        }
    }
  	return media/m->rows;
}

Mat* massima_sottomatrice(Mat *m){
	if (m==NULL) {
    	return NULL;
    }
  	int N = m->rows/2;
  	float mediaMax = -1.0;
  	Mat* maxMatrice = NULL;
  	
  	for (int i=0; i<=N; i++) {
    	for (int j=0; j<=N; j++) {
          Mat* sottomatrice = mat_alloc(N,N);
         	for (int x=0; x<N; x++) {
          		for (int y=0; y<N; y++) {
             		sottomatrice->mat[x][y] = m->mat[i+x][j+y];   	
                }
            }
          	float media = calcolaMedia(sottomatrice);
          	if (media > mediaMax) {
              	if (maxMatrice != NULL) mat_free(maxMatrice);
            	mediaMax = media;
              	maxMatrice = mat_alloc(N,N);
          		for (int x=0; x<N; x++) {
          			for (int y=0; y<N; y++) {
             			maxMatrice->mat[x][y] = sottomatrice->mat[x][y];   	
                	}
            	}
            }
        	mat_free(sottomatrice);
        }
    }
  	return maxMatrice;
}
