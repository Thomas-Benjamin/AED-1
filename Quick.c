#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void QuickSort (int p, int r, int v[]);
int Separa (int p, int r, int v[]);

int main() {
  double time_spent = 0.0;
  
  int n,i;

  clock_t inicio = clock();
  
  scanf("%d",&n);

  if(n>0){
    int v[n];

    for(i=0;i<n;i++){
      v[i]=rand()%10000;
    }

    QuickSort(0,n-1,v);

    printf("\n");
    
    for(i=0;i<n;i++){
      printf("%d ",v[i]);
    }
    
  }

  clock_t fim = clock();

  time_spent+= (double)(fim-inicio)/CLOCKS_PER_SEC;
  
  printf("\nO tempo gasto é: %f sec",time_spent);
  
  return 0;
}

void QuickSort (int p, int r, int v[]){
  int j;
  if(p<r){
    j=Separa(p,r,v);
    QuickSort(p,j-1,v);
    QuickSort(j+1,r,v);
  }
}

int Separa (int p, int r, int v[]){
  int c, j, k , t;
  c=v[r];
  j=p;
  for(k=p;k<r;k++){
    if(v[k]<=c){
      t=v[j];
      v[j]=v[k];
      v[k]=t;
      j++;
    }
  }
  v[r]=v[j];
  v[j]=c;
  return j;
}