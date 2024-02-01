#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* inverti(Mat* m) {
  	Mat* matrice = mat_alloc(m->rows, m->cols);
	if (m==NULL) {return NULL;}
  	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	if (i<j && m->mat[i][j]%2==0) {
            	matrice->mat[i][j] = -m->mat[i][j];
            }
          	else if (i>=j && m->mat[i][j]%2!=0) {
            	matrice->mat[i][j] = -m->mat[i][j];
            }
          	else {
            	matrice->mat[i][j] = m->mat[i][j];
            }
        }
    }
  	return matrice;
}

double trovaMedia(Mat *m) {
	double media = 0.0;
	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {	
          media += (double)m->mat[i][j];
        }
    }
  	return media/(double)m->rows;
}

Mat* trovaQuadrante1 (Mat *m) {
	if (m==NULL) {return NULL;}
  	int N = m->rows/2;
  	Mat* q = mat_alloc(N,N);
  	for (int i=0; i<N; i++) {
    	for (int j=0; j<N; j++) {
        	q->mat[i][j] = m->mat[i][j];
        }
    }
  	return q;
}

Mat* trovaQuadrante2 (Mat *m) {
	if (m==NULL) {return NULL;}
  	int N = m->rows/2;
  	Mat* q = mat_alloc(N,N);
  	for (int i=0; i<N; i++) {
    	for (int j=N; j<m->cols; j++) {
        	q->mat[i][j-N] = m->mat[i][j];
        }
    }
  	return q;
}

Mat* trovaQuadrante3 (Mat *m) {
	if (m==NULL) {return NULL;}
  	int N = m->rows/2;
  	Mat* q = mat_alloc(N,N);
  	for (int i=N; i<m->rows; i++) {
    	for (int j=0; j<N; j++) {
        	q->mat[i-N][j] = m->mat[i][j];
        }
    }
  	return q;
}

Mat* trovaQuadrante4 (Mat *m) {
	if (m==NULL) {return NULL;}
  	int N = m->rows/2;
  	Mat* q = mat_alloc(N,N);
  	for (int i=N; i<m->rows; i++) {
    	for (int j=N; j<m->cols; j++) {
        	q->mat[i-N][j-N] = m->mat[i][j];
        }
    }
  	return q;
}

Mat* inverti_e_max_quad(Mat* m) {
	Mat* inversa = inverti(m);
  	
  	Mat* q1 = trovaQuadrante1(inversa); 
  	Mat* q2 = trovaQuadrante2(inversa); 
  	Mat* q3 = trovaQuadrante3(inversa); 
  	Mat* q4 = trovaQuadrante4(inversa);
  
  	double media1 = trovaMedia(q1); 
  	double media2 = trovaMedia(q2); 
  	double media3 = trovaMedia(q3); 
  	double media4 = trovaMedia(q4);
  	
  	if (media1 >= media2 && media1 >= media2 && media1 >= media4) {return q1;}
  	if (media2 >= media1 && media2 >= media3 && media2 >= media4) {return q2;}
  	if (media3 >= media2 && media3 >= media1 && media3 >= media4) {return q3;}
  	if (media4 >= media2 && media4 >= media3 && media4 >= media1) {return q4;}
  
  
  	return NULL;
}
