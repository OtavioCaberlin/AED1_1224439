/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 17/09/2026
Objetivo    : Descrobrir se é pilha, fila ou fila de prioridade a partir da retirada ou adição de números.
Dificuldade : Utilizar as três estruturas ao mesmo tempo, descobrir o maior valor para fila de prioridade e muitas leituras.
Uso de IA   : Usei para ajudar a me indicar como consciliar as três estruturas e quando fazer o uso delas.
-------------------------------------------------------------------------- */

#include <stdio.h>

#define MAX 1010   // máximo de operações por caso

int main() {
    int n, i, j, op, x;

    int valores[MAX];   // todos os valores inseridos, na ordem em que entraram
    int qtd;            // quantos valores já foram inseridos

    // Marcações: 1 = esse valor já foi removido daquela estrutura, 0 = ainda está lá
    int remPilha[MAX];
    int remFila[MAX];
    int remPq[MAX];

    int ehPilha, ehFila, ehPq;   // 1 = ainda pode ser essa estrutura, 0 = não pode
    int total;
    int pos;                     // posição do valor que a estrutura removeria (-1 = nenhum)

    // Lê vários casos de teste, até o fim da entrada
    while (scanf("%d", &n) == 1) {

        qtd = 0;
        ehPilha = 1;
        ehFila = 1;
        ehPq = 1;

        for (i = 0; i < n; i++) {
            scanf("%d %d", &op, &x);

            if (op == 1) {
                // Inserir: guarda o valor e marca como "ainda não removido" nas três
                valores[qtd] = x;
                remPilha[qtd] = 0;
                remFila[qtd] = 0;
                remPq[qtd] = 0;
                qtd++;
            } else {
                // Remover: x é o valor que a estrutura misteriosa devolveu.

                // PILHA: seria o último valor que ainda não foi removido
                pos = -1;
                for (j = qtd - 1; j >= 0; j--) {
                    if (remPilha[j] == 0) {
                        pos = j;
                        break;   // achou o mais recente, para de procurar
                    }
                }
                if (pos == -1 || valores[pos] != x) {
                    ehPilha = 0;
                } else {
                    remPilha[pos] = 1;   // marca como removido
                }

                // FILA: seria o primeiro valor que ainda não foi removido
                pos = -1;
                for (j = 0; j < qtd; j++) {
                    if (remFila[j] == 0) {
                        pos = j;
                        break;   // achou o mais antigo, para de procurar
                    }
                }
                if (pos == -1 || valores[pos] != x) {
                    ehFila = 0;
                } else {
                    remFila[pos] = 1;
                }

                // FILA DE PRIORIDADE: seria o maior valor que ainda não foi removido
                pos = -1;
                for (j = 0; j < qtd; j++) {
                    if (remPq[j] == 0) {
                        if (pos == -1 || valores[j] > valores[pos]) {
                            pos = j;   // encontrou um candidato maior
                        }
                    }
                }
                if (pos == -1 || valores[pos] != x) {
                    ehPq = 0;
                } else {
                    remPq[pos] = 1;
                }
            }
        }

        // Conta quantas estruturas continuam possíveis
        total = ehPilha + ehFila + ehPq;

        if (total == 0) {
            printf("impossible\n");
        } else if (total > 1) {
            printf("not sure\n");
        } else if (ehPilha) {
            printf("stack\n");
        } else if (ehFila) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}
