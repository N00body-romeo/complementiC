#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

Mat* flipRiga(Mat *m) {
	if (m==NULL) {
    	return NULL;
    }
  	Mat* m2 = mat_alloc(m->rows, m->cols);
  	for (int i=0; i < m->rows; i++) {
    	for (int j=0; j < m->cols; j++) {
        	if (i%2==0) {
              	//printf("indice pari, i:%d, j:%d\n",i,j);
            	m2->mat[i][j] = m->mat[i][m->cols-j-1];
            }
          	else {
              	//printf("indice dispari, i:%d, j:%d\n",i,j);
            	m2->mat[i][j] = m->mat[i][j];
            }
        }
    }
  	return m2;
}

int somma(Mat *m) {
	int somma = 0;
  	for (int i=0; i<m->rows; i++) {
    	for (int j=0; j<m->cols; j++) {
        	somma += m->mat[i][j];
        }
    }
  	return somma;
}

Mat* trovaQuadrante1 (Mat *m) {
	if (m==NULL) {
    	return NULL;
    }
  	int N = m->rows/2;
  	Mat* sottomatrice = mat_alloc(N,N);
  	for (int i=0; i< N; i++) {
    	for (int j=0; j< N; j++) {
        	sottomatrice->mat[i][j] = m->mat[i][j];
        }
    }
  	return sottomatrice; 
}

Mat* trovaQuadrante2 (Mat *m) {
	if (m==NULL) {
    	return NULL;
    }
  	int N = m->rows/2;
  	Mat* sottomatrice = mat_alloc(N,N);
  	for (int i=0; i< N; i++) {
    	for (int j=N; j< m->cols; j++) {
        	sottomatrice->mat[i][j-N] = m->mat[i][j];
        }
    }
  	return sottomatrice; 
}

Mat* trovaQuadrante3 (Mat *m) {
	if (m==NULL) {
    	return NULL;
    }
  	int N = m->rows/2;
  	Mat* sottomatrice = mat_alloc(N,N);
  	for (int i=N; i< m->rows; i++) {
    	for (int j=0; j< N; j++) {
        	sottomatrice->mat[i-N][j] = m->mat[i][j];
        }
    }
  	return sottomatrice; 
}

Mat* trovaQuadrante4 (Mat *m) {
	if (m==NULL) {
    	return NULL;
    }
  	int N = m->rows/2;
  	Mat* sottomatrice = mat_alloc(N,N);
  	for (int i=N; i< m->rows; i++) {
    	for (int j=N; j< m->cols; j++) {
        	sottomatrice->mat[i-N][j-N] = m->mat[i][j];
        }
    }
  	return sottomatrice; 
}

int massimo_flip_riga(Mat *m){
	if (m==NULL) { return 0; }
  	Mat* mat2 = flipRiga(m);
 	Mat* m1 = trovaQuadrante1(mat2); int sum1 = somma(m1); printf("sum1: %d\n",sum1);
 	Mat* m2 = trovaQuadrante2(mat2); int sum2 = somma(m2); printf("sum2: %d\n",sum2);
 	Mat* m3 = trovaQuadrante3(mat2); int sum3 = somma(m3); printf("sum3: %d\n",sum3);
 	Mat* m4 = trovaQuadrante4(mat2); int sum4 = somma(m4); printf("sum4: %d\n",sum4);
  
  	mat_print(m1); mat_print(m2); mat_print(m3); mat_print(m4);
  	if (sum1 >= sum2 && sum1 >= sum3 && sum1 >= sum4) { return sum1; }
  	else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4) { return sum2; }
  	else if (sum3 >= sum1 && sum3 >= sum3 && sum3 >= sum2) { return sum3; }
  	else if (sum4 >= sum1 && sum4 >= sum3 && sum4 >= sum2) { return sum4; }
  	else {return 0;}
   	return 0;
  
}
