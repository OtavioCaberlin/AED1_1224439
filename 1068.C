/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 17/09/2026
Objetivo    : Determinar se a quantidade de parênteses está correta ou não.
Dificuldade : Utilizar pilha, sua sintaxe e lógica.
Uso de IA   : Usei para ajudar a entender o funcionamento da pilha e sua sintaxe.
-------------------------------------------------------------------------- */

#include <stdio.h>

#define MAX 1010   // tamanho máximo de uma expressão

int main() {
    char expr[MAX];    // guarda a expressão lida
    char pilha[MAX];   // a pilha (vetor onde empilhamos os '(')
    int topo;          // quantidade de itens na pilha (posição livre do topo)
    int i, ok;

    // Lê uma expressão por linha, até o fim da entrada
    while (fgets(expr, MAX, stdin) != NULL) {

        topo = 0;   // pilha começa vazia
        ok = 1;     // supomos que a expressão está correta

        // Percorre a expressão caractere por caractere
        for (i = 0; expr[i] != '\0'; i++) {

            if (expr[i] == '(') {
                // Abriu parêntese: EMPILHA
                pilha[topo] = '(';
                topo++;
            } else if (expr[i] == ')') {
                // Fechou parêntese: precisa ter um '(' na pilha para desempilhar
                if (topo == 0) {
                    ok = 0;   // pilha vazia: sobrou um ')'
                    break;
                }
                // DESEMPILHA
                topo--;
            }
            // Outros caracteres são ignorados
        }

        // Se sobrou algum '(' na pilha, faltou fechar
        if (topo != 0) {
            ok = 0;
        }

        if (ok) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
