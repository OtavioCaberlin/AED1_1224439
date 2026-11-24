/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1008
Data        : 24/11/2026
Objetivo    : Mostrar o número do funcionário e seu salário.
Dificuldade : Nenhuma.
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */

#include <stdio.h>

float Calcular_Salario (int x, float y) {

    return x * y;
}

int main() {

    int num, horas;
    float valor;

    scanf ("%d %d", &num, &horas);
    scanf ("%f", &valor);

    float salario = Calcular_Salario (horas, valor);

    printf ("NUMBER = %d\n", num);
    printf ("SALARY = U$ %.2f\n", salario);

    return 0;
}
