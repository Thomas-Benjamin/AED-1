#include <stdio.h>
#include <string.h>

void OrdenaString (int n, char nome[][25]);

int main() {
  int i,n,k;
  
  scanf("%d %d",&n,&k);
  
  if(k>=1&&k<=n&&n<=100){
    char nome[n][25];
  
    for(i=0;i<n;i++){
      scanf("%s",nome[i]);
    }
  
    OrdenaString(n,nome);
  
    printf("%s\n",nome[k-1]);
    
  }
  
  return 0;
}

void OrdenaString (int n, char nome[][25]){
  int j,i,r;
  char aux[25];

  for(j=0;j<(n-1);j++){
    for(i=j+1;i<n;i++){
      r=strcmp(nome[j],nome[i]);
      if(r>0){
        strcpy(aux,nome[j]);
        strcpy(nome[j],nome[i]);
        strcpy(nome[i],aux);
      }
    }
  }
}