#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 1000

typedef struct {
    int cidade;
    struct Rota* prox;
} Rota;

int bfs(int n, int rotas[][MAX_CIDADES + 1], int curytiba, int riacho, int estadunido) {
    bool visited[MAX_CIDADES + 1] = { false };
    visited[curytiba] = true;

    int queue[MAX_CIDADES];
    int front = 0;
    int rear = 0;

    queue[rear++] = curytiba;

    int horas[MAX_CIDADES + 1] = { 0 };

    while (front < rear) {
        int cidade = queue[front++];
        if (cidade == riacho) {
            return horas[cidade];
        }

        for (int vizinha = 1; vizinha <= n; vizinha++) {
            if (rotas[cidade][vizinha] && !visited[vizinha] && vizinha != estadunido) {
                visited[vizinha] = true;
                queue[rear++] = vizinha;
                horas[vizinha] = horas[cidade] + 1;
            }
        }
    }

    return -1;
}

void adicionarRota(int rotas[][MAX_CIDADES + 1], int cidade1, int cidade2) {
    rotas[cidade1][cidade2] = 1;
    rotas[cidade2][cidade1] = 1;
}

void liberarRotas(int rotas[][MAX_CIDADES + 1], int n) {
    // Não é necessário liberar a matriz de adjacências
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        int rotas[MAX_CIDADES + 1][MAX_CIDADES + 1] = { 0 };

        for (int i = 0; i < m; i++) {
            int cidade1, cidade2;
            scanf("%d %d", &cidade1, &cidade2);
            adicionarRota(rotas, cidade1, cidade2);
        }

        int curytiba, riacho, estadunido;
        scanf("%d %d %d", &curytiba, &riacho, &estadunido);

        int resultado = bfs(n, rotas, curytiba, riacho, estadunido);
        printf("%d\n", resultado);
    }

    return 0;
}
