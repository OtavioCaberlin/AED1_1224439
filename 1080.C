/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Maior número entre 100 e sua posição.
Dificuldade : Como utilizar vetores e suas aplicações.
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {

	// Declaração das variáveis
	int v[100], maior, entrada, i;

	// Definindo número de loops
	for(i = 0; i < 100; i++) {

		// Processamento da entrada
		scanf("%d", &v[i]);

		// Definindo o termo inicial
		if(i == 0) {
			maior = v[0];
			entrada = 1;
		}

		// Comparando com os demais termos
		else if(v[i] > maior) {
			maior = v[i];
			entrada = i + 1;
		}
	}

	// Processamento da saída
	printf("%d\n", maior);
	printf("%d\n", entrada);

	return 0;
}
