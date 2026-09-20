/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 27/08/2026
Objetivo    : Fazer a verificação de um sudoku.
Dificuldade : Com verificar linha, coluna e a "matriz interna" (com alocação dinâmica de matrizes).
Uso de IA   : Usei para ajudar a entender como fazer a alocação dinâmica de matrizes.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t, i, j, k;
    int ok;
    int **m;   // matriz 9x9 

    // Aloca dinamicamente a matriz (primeiro as 9 linhas)
    m = (int **) malloc(9 * sizeof(int *));
    
    // Agora as 9 colunas de cada linha
    for (i = 0; i < 9; i++) {
        m[i] = (int *) malloc(9 * sizeof(int));
    }

    // quantidade de instâncias
    scanf("%d", &n);

    for (t = 1; t <= n; t++) {
        // Lê a matriz 9x9 desta instância
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &m[i][j]);
            }
        }

        ok = 1; 

        for (i = 0; i < 9; i++) {
            // Vetores para contar quantas vezes cada número (1 a 9) apareceu
            int lin[10] = {0};   // na linha i
            int col[10] = {0};   // na coluna i
            int blo[10] = {0};   // no bloco 3x3 número i

            for (j = 0; j < 9; j++) {
                lin[m[i][j]]++;          // elemento da linha i
                col[m[j][i]]++;          // elemento da coluna i
                // elemento j do bloco i (i escolhe o bloco, j escolhe a posição dentro dele)
                blo[m[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]]++;
            }

            // Cada número de 1 a 9 deve aparecer exatamente uma vez
            for (k = 1; k <= 9; k++) {
                if (lin[k] != 1 || col[k] != 1 || blo[k] != 1) {
                    ok = 0;
                }
            }
        }

        printf("Instancia %d\n", t);
        if (ok) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    // Libera a memória (primeiro cada linha, depois o vetor de linhas)
    for (i = 0; i < 9; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
