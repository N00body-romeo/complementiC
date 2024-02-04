#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

Mat* inversa(Mat*m){
  Mat*inv=mat_alloc(m->rows, m->cols);
  for(int i=0;i<m->rows;i++){
    for(int j=0;j<m->cols;j++){
      if((i+j)%2==0){
        inv->mat[i][j]=m->mat[i][j];
      }else{
        inv->mat[i][j]=-(m->mat[i][j]);
      }
    }
  }
  return inv;
}

int somma_quadn(Mat*m){
  int somma=0;
  int N=m->rows/2;
  for(int i=0;i<m->rows;i++){
    for(int j=0;j<m->cols;j++){
      if(i!=j){
        if(i+j!=m->cols-1){
          if((i<N)&&(i+j>=2*i && i+j<m->cols-1)){
            somma+=m->mat[i][j];
          }
        }
      }
    }
  }
  return somma;
}

int somma_quado(Mat*m){
  int somma=0;
  int N=m->rows/2;
  for(int i=0;i<m->rows;i++){
    for(int j=0;j<m->cols;j++){
      if(i!=j){
        if(i+j!=m->cols-1){
          if((j<N) && (i+j>=2*j && j+i<m->rows-1)){
            somma+=m->mat[i][j];
          }
        }
      }
    }
  }         
  return somma;
}

int somma_quads(Mat*m){
  int somma=0;
  int N=m->rows/2;
  for(int i=0;i<m->rows;i++){
    for(int j=0;j<m->cols;j++){
      if(i!=j){
        if(i+j!=m->cols-1){
          if((i>N) && (j+i<=2*i && j+i>m->rows-1)){
            somma+=m->mat[i][j];
          }
        }
      }
    }
  }         
  return somma;
}

int somma_quade(Mat*m){
  int somma=0;
  int N=m->rows/2;
  for(int i=0;i<m->rows;i++){
    for(int j=0;j<m->cols;j++){
      if(i!=j){
        if(i+j!=m->cols-1){
          if((j>N) && (i+j<=2*j && i+j>m->rows-1)){
            somma+=m->mat[i][j];
          }
        }
      }
    }
  }         
  return somma;
}
             
int cambia_segno_e_massima_somma(Mat* m) {
  Mat*inv=inversa(m);
  int sommaMax;

  if(qn>=qe && qn>=qo && qn>=qs){
    sommaMax=qn;}
  if(qe>=qn && qe>=qo && qe>=qs){
    sommaMax=qe;}
  if(qo>=qn && qo>=qe && qo>=qs){
    sommaMax=qo;}
  if(qs>=qn && qs>=qe && qs>=qo){
    sommaMax=qs;}
  return sommaMax;
}
