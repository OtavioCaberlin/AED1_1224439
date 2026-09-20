#include <stdio.h>
#include <stdlib.h>

int main() {
    
  // quantidade de números que serão lidos
    int n = 100;
    int i;
    int maior, posicao;

    // Aloca dinamicamente um vetor com espaço para 100 inteiros
    int *v = (int *) malloc(n * sizeof(int));

    // Lê os 100 números e guarda no vetor
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Começa supondo que o primeiro número é o maior
    maior = v[0];
    posicao = 1; 

    // Percorre o resto do vetor procurando um número maior
    for (i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1;   // i começa em 0, então somamos 1
        }
    }

    // Imprime o maior valor e sua posição, cada um em uma linha
    printf("%d\n%d\n", maior, posicao);

    // Libera a memória alocada
    free(v);

    return 0;
}
