#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Selecao (int n, int v[]);

int main() {
  double time_spent = 0.0;
  
  int n,i;

  clock_t inicio = clock();
  
  scanf("%d",&n);

  if(n>0){
    int v[n];

    for(i=0;i<n;i++){
      v[i] = rand()%10000;
    }

    Selecao(n,v);

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

void Selecao (int n, int v[]){
  int i, j, min, aux;

  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(v[j]<v[min]){
        min=j;
      }
    }
    aux=v[min];
    v[min]=v[i];
    v[i]=aux;
  }
  
}