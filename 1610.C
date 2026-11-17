/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : Descobrir se existe alguma dependência circular que torne impossível concluir o serviço.
Dificuldade : Identificar ciclos em um grafo direcionado usando DFS e como utilizar DFS corretamente.
Uso de IA   : Usei para auxiliar em como utilizar DFS e qual a sintaxe.
-------------------------------------------------------------------------- */

#include <stdio.h>

int inicio[10005], destino[30005], prox[30005];
int cor[10005];
int aresta;

// Verifica se existe ciclo
int dfs(int u) {
    cor[u] = 1;

    int i;
    for (i = inicio[u]; i != -1; i = prox[i]) {
        int v = destino[i];

        if (cor[v] == 1) {
            return 1;
        }

        if (cor[v] == 0) {
            if (dfs(v)) {
                return 1;
            }
        }
    }

    cor[u] = 2;
    return 0;
}

int main() {
    int t, n, m, a, b;
    int i, ciclo;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        // Inicializa o grafo
        for (i = 1; i <= n; i++) {
            inicio[i] = -1;
            cor[i] = 0;
        }

        aresta = 0;

        // Lê as dependências
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);

            destino[aresta] = b;
            prox[aresta] = inicio[a];
            inicio[a] = aresta;
            aresta++;
        }

        ciclo = 0;

        // Percorre todos os documentos
        for (i = 1; i <= n; i++) {
            if (cor[i] == 0) {
                if (dfs(i)) {
                    ciclo = 1;
                    break;
                }
            }
        }

        if (ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
