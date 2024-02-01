#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

double trovaMinimi(Mat* m) {
	if (m==NULL) { return 0.0; }
  	double minimo = (double)m->mat[0][0];
  	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	if ((double)m->mat[i][j] <= minimo) {
            	minimo = (double)m->mat[i][j];
            }
        }
    }
  	return minimo;
}

Mat* trasforma(Mat* m) {
	if (m==NULL) {return NULL;}
  	Mat* matrice = mat_alloc(m->rows, m->cols);
  	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	matrice->mat[i][j] = m->mat[i][j]-i+j;
        }
    }
  	return matrice;
}

Mat* trovaQuadrante1 (Mat* m) {
	if (m==NULL) {return NULL;}
  	int N = (m->rows-1)/2;
  	Mat* quadrante = mat_alloc(N,N);
  	for (int i=0; i<N; i++) {
    	for (int j=0; j<N; j++) {
        	quadrante->mat[i][j] = m->mat[i][j];
        }
    }
  	return quadrante;
}

Mat* trovaQuadrante2 (Mat* m) {
	if (m==NULL) {return NULL;}
  	int N = (m->rows-1)/2;
  	int M = N+1;
  	Mat* quadrante = mat_alloc(N,N);
  	for (int i=0; i<N; i++) {
    	for (int j=M; j<m->cols; j++) {
        	quadrante->mat[i][j-M] = m->mat[i][j];
        }
    }
  	return quadrante;
}

Mat* trovaQuadrante3 (Mat* m) {
	if (m==NULL) {return NULL;}
  	int N = (m->rows-1)/2;
  	int M = N+1;
  	Mat* quadrante = mat_alloc(N,N);
  	for (int i=M; i<m->rows; i++) {
    	for (int j=0; j<M; j++) {
        	quadrante->mat[i-M][j] = m->mat[i][j];
        }
    }
  	return quadrante;
}

Mat* trovaQuadrante4 (Mat* m) {
	if (m==NULL) {return NULL;}
  	int N = (m->rows-1)/2;
  	int M = N+1;
  	Mat* quadrante = mat_alloc(N,N);
  	for (int i=M; i<m->rows; i++) {
    	for (int j=M; j<m->cols; j++) {
        	quadrante->mat[i-M][j-M] = m->mat[i][j];
        }
    }
  	return quadrante;
}

double trasforma_e_min_quad(Mat* m) {
	if (m==NULL) {return 0.0;}
  	
  	Mat* trasformata = trasforma(m);
  	Mat* q1 = trovaQuadrante1(trasformata);
  	Mat* q2 = trovaQuadrante2(trasformata);
  	Mat* q3 = trovaQuadrante3(trasformata);
  	Mat* q4 = trovaQuadrante4(trasformata);
  
  	double minimo1 = trovaMinimi(q1);
  	double minimo2 = trovaMinimi(q2);
  	double minimo3 = trovaMinimi(q3);
  	double minimo4 = trovaMinimi(q4);
  
  	return minimo1 + minimo2 + minimo3 + minimo4;
}
