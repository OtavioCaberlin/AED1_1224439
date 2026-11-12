/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 12/11/2026
Objetivo    : .
Dificuldade : .
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */

#include <stdio.h>

int grafo[26][26];
int visitado[26];
int componente[26];
int vertices;

void dfs(int v) {
    visitado[v] = 1;
    componente[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (grafo[v][i] == 1 && visitado[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int testes, arestas;
    char a, b;

    scanf("%d", &testes);

    for (int t = 1; t <= testes; t++) {

        scanf("%d %d", &vertices, &arestas);

        for (int i = 0; i < vertices; i++) {
            visitado[i] = 0;

            for (int j = 0; j < vertices; j++) {
                grafo[i][j] = 0;
            }
        }

        for (int i = 0; i < arestas; i++) {
            scanf(" %c %c", &a, &b);

            int x = a - 'a';
            int y = b - 'a';

            grafo[x][y] = 1;
            grafo[y][x] = 1;
        }

        printf("Case #%d:\n", t);

        int componentes = 0;

        for (int i = 0; i < vertices; i++) {

            if (visitado[i] == 0) {

                for (int j = 0; j < vertices; j++) {
                    componente[j] = 0;
                }

                dfs(i);

                for (int j = 0; j < vertices; j++) {
                    if (componente[j] == 1) {
                        printf("%c,", j + 'a');
                    }
                }

                printf("\n");
                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}
