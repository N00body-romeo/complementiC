#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

float media(Mat *m) {
  	float somma = 0;
	for (int i=0; i<m->rows; i++) {
    		for (int j=0; j<m->cols; j++) {
        		somma+= m->mat[i][j];
        	}
    	}
  	float ris = somma/((m->rows)*(m->cols));
  	return ris;
}

Mat* massima_sottomatrice(Mat *m){
  	int rig = m->rows/2, col = m->cols/2;
  
	Mat* max_matrice = mat_alloc(rig, col);
  	float max_media = 0.0;
  	for (int i=0; i<=m->rows-rig; i++) {
    		for (int j=0; j<=m->cols-col; j++) {
        		Mat* sott = mat_alloc(rig, col);
          		for (int x = 0; x<rig; x++) {
            			for (int y=0; y<col; y++) {
                			sott->mat[x][y] = m->mat[i+x][j+y];
                		}
            		}
          		float media_sott = media(sott);
          		if (media_sott > max_media) {
            			max_media = media_sott;
              			for (int x=0; x<rig; x++) {
                			for (int y=0; y<col; y++) {
                    				max_matrice->mat[x][y] = sott->mat[x][y];
                    			}
                		}
          			mat_free(sott); 	
            		}          	
        	}
    	}
  	return max_matrice;
}
