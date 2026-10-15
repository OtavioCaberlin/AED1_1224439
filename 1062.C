
#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {
        int primeiro = 1;

        while (1) {
            int saida[N];
            int x;

            scanf("%d", &x);

            // Zero encerra as sequências deste tamanho.
            if (x == 0)
                break;

            saida[0] = x;

            for (int i = 1; i < N; i++)
                scanf("%d", &saida[i]);

            int pilha[N];
            int topo = -1;
            int proximo = 1;
            int possivel = 1;

            for (int i = 0; i < N; i++) {
                // Coloca vagões na estação até encontrar o desejado.
                while (proximo <= N &&
                       (topo == -1 || pilha[topo] != saida[i])) {
                    pilha[++topo] = proximo;
                    proximo++;
                }

                // Se o topo é o vagão desejado, ele pode sair.
                if (topo >= 0 && pilha[topo] == saida[i]) {
                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel)
                printf("Yes\n");
            else
                printf("No\n");
        }

        // Separa os blocos de tamanhos diferentes.
        if (primeiro)
            printf("\n");
    }

    return 0;
}
