#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *esq;
    struct cel *dir;
}No;

typedef No* Arvore; 

No* CriaNo(int k){
    No *novo;
    novo = malloc(sizeof(No));
    novo->chave=k;
    novo->esq=NULL;
    novo->dir=NULL;
    return novo;
}

Arvore Insere(Arvore r, No *novo){
    if(r==NULL){
        r=novo;
    }
    if(novo->chave>r->chave){
        r=Insere(r->dir,novo);
    }
    if(novo->chave<r->chave){
        r=Insere(r->esq,novo);
    }
    return r;
}

void Prefixo(Arvore r){
    printf(" %d",r->chave);
    Prefixo(r->esq);
    Prefixo(r->dir);
}

void Infixo(Arvore r){
    Infixo(r->esq);
    printf(" %d",r->chave);
    Infixo(r->dir);
}

void Posfixo(Arvore r){
    Posfixo(r->esq);
    Posfixo(r->dir);
    printf(" %d",r->chave);
}

Arvore Inicia(Arvore r){
    r=NULL;
    return r;
}

int main() {
    int c,i=0,j;
    scanf("%d",&c);
    if(c<=1000){
        Arvore ca[c];
        while(i<c){
            ca[i]=Inicia(ca[i]);
            int n;
            scanf("%d",&n);
            if(n>=1&&n<=500){
                int w;
                for(j=0;j<n-1;j++){
                    int v;
                    scanf("%d ",&v);
                    Insere(ca[i],CriaNo(v));
                }
                scanf("%d",&w);
                Insere(ca[i],CriaNo(w));
            }
            i++;
        }
        
        i=0;
        while(i<c){
            printf("Case %d:\n",i+1);
            printf("Pre.:");
            Prefixo(ca[i]);
            printf("\n");
            printf("In..:");
            Infixo(ca[i]);
            printf("\n");
            printf("Post:");
            Posfixo(ca[i]);
            printf("\n");
            i++;
        }
    
    }
    
    return 0;
}
