#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"


int* controlla_colonne(Mat *m, double w, double v){
  int* result = (int*) malloc(m->cols * sizeof(int));
  int* medie = (int*) malloc(m->cols * sizeof(int));
  
  for (int i=0; i < m->rows; i++) {
  	for (int j=0; j < m->cols; j++) {
    	medie[j] += m->mat[i][j];
    }
  }
  for (int i=0; i < m->cols; i++) {
  	medie[i] = medie[i]/m->rows;
  }
  
  for (int i=0; i < m->cols; i++) {
  	if (medie[i] >= w && medie[i] <= v) {
    	result[i] = 1;
    }
    else { result[i] = 0; }
  }
  return result;
}
