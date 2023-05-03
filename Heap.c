#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void MaxHeap(int n, int vet[]);
void SacodeHeap(int n, int vet[]);

int main() {
  double time_spent = 0.0;
  
  int n, i, aux;

  clock_t inicio = clock();
  
  scanf("%d",&n);

  if(n>0){
    int v[n];

    for (i=0;i<n;i++){
      v[i]=rand()%10000;
    }

    MaxHeap(n,v);
    
    for(i=n-1;i>0;i--){
      aux=v[i];
      v[i]=v[0];
      v[0]=aux;

      SacodeHeap(i,v);
    }

    printf("\n");
    
    for (i=0;i<n;i++){
      printf("%d ",v[i]);
    }
    
  }

  clock_t fim = clock();

  time_spent+= (double)(fim-inicio)/CLOCKS_PER_SEC;
  
  printf("\nO tempo gasto é: %f sec",time_spent);
  
  return 0;
}

void MaxHeap(int n, int vet[]){
  int i,p,aux;
  
  for(i=1;i<n;i++){
    p=i;
    while(p>0&&vet[(p-1)/2]<vet[p]){
      aux=vet[(p-1)/2];
      vet[(p-1)/2]=vet[p];
      vet[p]=aux;
      p=(p-1)/2;
    }
  }
}

void SacodeHeap(int n, int vet[]){
  int aux,f=1;

  while(f<n){
    if(f<n-1 && vet[f]<vet[f+1]){
      f++;
    }
    if(vet[f]<=vet[(f-1)/2]){
      break;
    }
    aux=vet[f];
    vet[f]=vet[(f-1)/2];
    vet[(f-1)/2]=aux;

    f=(f*2)+1;
  }
  
}