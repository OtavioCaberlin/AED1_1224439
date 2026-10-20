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
