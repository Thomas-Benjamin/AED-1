#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void MergeSort (int inicio, int fim, int v[]);
void Intercala (int inicio, int meio, int fim, int v[]);

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

    MergeSort(0,n,v);

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

void MergeSort (int inicio, int fim, int v[]){
  if(inicio<fim-1){
    int meio=(inicio+fim)/2;
    MergeSort(inicio,meio,v);
    MergeSort(meio,fim,v);
    Intercala(inicio,meio,fim,v);
  }
}

void Intercala (int inicio, int meio, int fim, int v[]){
  int i=inicio,j=meio,k=0,w[fim-inicio];

  while(i<meio&&j<fim){
    if(v[i]<=v[j]){
      w[k++]=v[i++];
    }
    else{
      w[k++]=v[j++];
    }
  }

  while(j<fim){
    w[k++]=v[j++];
  }
  while(i<meio){
    w[k++]=v[i++];
  }

  for(k=inicio;k<fim;k++){
    v[k]=w[k-inicio];
  }
}