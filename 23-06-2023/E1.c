#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

float somma_diag(Mat *mat, int row, int col) {
	if (mat==NULL) return -1;
  	float somma = 0.0;
  	for (int i=0; i<mat->rows; i++) {
    	for (int j=0; j<mat->cols; j++) {
        	if (i-j == row-col) {
                somma += mat->mat[i][j];
              	printf("i: %d, j: %d\n",i,j);
            }
        }
    }
  	return somma;
}
