#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char dado;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(char dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

struct No* construirArvore(char* emOrdem, char* preOrdem, int inicio, int fim, int* indicePre) {
    if (inicio > fim)
        return NULL;

    struct No* raiz = criarNo(preOrdem[*indicePre]);
    (*indicePre)++;

    if (inicio == fim)
        return raiz;

    int indiceEm = strchr(emOrdem, raiz->dado) - emOrdem;

    raiz->esquerda = construirArvore(emOrdem, preOrdem, inicio, indiceEm - 1, indicePre);
    raiz->direita = construirArvore(emOrdem, preOrdem, indiceEm + 1, fim, indicePre);

    return raiz;
}

void percorrerPosOrdem(struct No* raiz) {
    if (raiz == NULL)
        return;

    percorrerPosOrdem(raiz->esquerda);
    percorrerPosOrdem(raiz->direita);
    printf("%c", raiz->dado);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        int N;
        scanf("%d", &N);

        char S1[53];
        char S2[53];
        scanf("%s%s", S1, S2);

        int indicePre = 0;
        struct No* raiz = construirArvore(S2, S1, 0, N - 1, &indicePre);

        percorrerPosOrdem(raiz);
        printf("\n");

        free(raiz);
    }

    return 0;
}
