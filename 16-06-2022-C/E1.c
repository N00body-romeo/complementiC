#include "aux.h"

void bombardamentoNavale(Mat *src, int r, int c){
  //printMatrix(src);
  if(r<src->rows && c<src->cols){
    if (src->row_ptrs[r][c]==1){
      src->row_ptrs[r][c]=0;
      //sale
      if (r-1>=0){
        int i=r;
      while(i-1>=0){
        i--;
        if(src->row_ptrs[i][c]==1){
          src->row_ptrs[i][c]=0;
        }else{ break;}
      }
      }
      //scende
      if(r+1<src->rows){
        int i=r;
      while(i+1<src->rows){
        i++;
        if(src->row_ptrs[i][c]==1){
          src->row_ptrs[i][c]=0;
        }else{ break;}
      }
      }
      //des
      if(c+1<src->cols){
        int j=c;
      while(j+1<src->cols){
        j++;
        if(src->row_ptrs[r][j]==1){
          src->row_ptrs[r][j]=0;
        }else{ break;}
      }
      }
      //sin
       if(c-1>=0){
        int j=c;
      while(j-1>=0){
        j--;
        if(src->row_ptrs[r][j]==1){
          src->row_ptrs[r][j]=0;
        }else{ break;}
      }
       }
        
    }
  }
  return;
}
