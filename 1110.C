/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 17/09/2026
Objetivo    : Numerar o descarte de cartas e qual carta restou.
Dificuldade : Utilizar lista encadeada, sua sintaxe e lógica.
Uso de IA   : Usei para ajudar a entender o funcionamento da lista encadeada e sua sintaxe.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Cada nó da lista guarda o valor de uma carta e o endereço do próximo nó
struct no {
    int valor;
    struct no *prox;
};

int main() {
    int n, i, primeiro;
    struct no *inicio, *fim, *novo, *aux;

    // Repete para cada caso de teste, até ler 0
    while (scanf("%d", &n) && n != 0) {

        inicio = NULL;   // lista começa vazia
        fim = NULL;

        // Cria as cartas 1, 2, ..., n e insere sempre no final da lista
        for (i = 1; i <= n; i++) {
            novo = (struct no *) malloc(sizeof(struct no));
            novo->valor = i;
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;       // primeira carta: é o início da lista
            } else {
                fim->prox = novo;    // liga o antigo último ao novo
            }
            fim = novo;              // o novo passa a ser o último
        }

        printf("Discarded cards:");
        primeiro = 1;   // usado para acertar as vírgulas na impressão

        // Enquanto tiver mais de uma carta na lista
        while (inicio->prox != NULL) {

            // Descarta a carta do topo (início da lista)
            aux = inicio;
            inicio = inicio->prox;

            if (primeiro) {
                printf(" %d", aux->valor);
                primeiro = 0;
            } else {
                printf(", %d", aux->valor);
            }
            free(aux);   // libera o nó descartado

            // Se ainda sobrou mais de uma carta, move a do topo para o final
            if (inicio->prox != NULL) {
                aux = inicio;
                inicio = inicio->prox;   // o início agora é a segunda carta
                aux->prox = NULL;        // a carta movida será a última
                fim->prox = aux;         // liga no final da lista
                fim = aux;               // atualiza o ponteiro do final
            }
        }

        // Sobrou só uma carta
        printf("\nRemaining card: %d\n", inicio->valor);
        free(inicio);
    }

    return 0;
}
