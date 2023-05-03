#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Insertion (int n, int v[]);

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

    Insertion(n,v);

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

void Insertion (int n, int v[]) {
  int i,j,chave;

  for(j=1;j<n;j++){
    chave=v[j];
    for(i=j-1;i>=0&&v[i]>chave;--i){
      v[i+1]=v[i];
    }
    v[i+1]=chave;
  }
}