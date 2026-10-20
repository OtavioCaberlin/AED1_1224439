/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1004
Data        : 20/10/2026
Objetivo    : Calcular o produto de dois números.
Dificuldade : Nenhuma.
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */

#include <stdio.h>

// Função para calcular o produto de 2 números
int Produtos (int x, int y) {

    return x * y;
}

int main() {

    // Declaração das variáveis
    int num1, num2, PROD;

    // Processamento da entrada
    scanf ("%d %d", &num1, &num2);

    PROD = Produtos (num1, num2);

    // Processamento da saída
    printf ("PROD = %d\n", PROD);

    return 0;
}
