#include <stdio.h>

int buscaBinaria(int casas[], int n, int alvo) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (casas[meio] == alvo)
            return meio;

        if (casas[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int main() {
    int NC, NE;
    scanf("%d %d", &NC, &NE);

    int casas[NC], encomendas[NE];

    for (int i = 0; i < NC; i++)
        scanf("%d", &casas[i]);

    for (int i = 0; i < NE; i++)
        scanf("%d", &encomendas[i]);

    int posicao = 0;
    long long distancia = 0;

    for (int i = 0; i < NE; i++) {
        // Localiza a casa da encomenda por busca binária.
        int destino = buscaBinaria(casas, NC, encomendas[i]);

        // Soma a distância entre a posição atual e o destino.
        int deslocamento = destino - posicao;

        if (deslocamento < 0)
            deslocamento = -deslocamento;

        distancia += deslocamento;
        posicao = destino;
    }

    printf("%lld\n", distancia);

    return 0;
}
