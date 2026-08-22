/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Otávio Fernandes Caberlin
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Fazer a verificação de um sudoku.
Dificuldade : Com verificar linha, coluna e a "matriz interna".
Uso de IA   : Usei para ajudar na parte da verificação da "matriz interna".
-------------------------------------------------------------------------- */

#include <stdio.h>

int sudoku[9][9];

int verificaLinha(int linha)
{
    int usado[10] = {0};

    for(int i = 0; i < 9; i++)
    {
        int num = sudoku[linha][i];

        if(usado[num])
        {
            return 0;
        }

        usado[num] = 1;
    }

    return 1;
}

int verificaColuna(int coluna)
{
    int usado[10] = {0};

    for(int i = 0; i < 9; i++)
    {
        int num = sudoku[i][coluna];

        if(usado[num])
        {
            return 0;
        }

        usado[num] = 1;
    }

    return 1;
}

int verificaBloco(int linhaInicial, int colunaInicial)
{
    int usado[10] = {0};

    for(int i = linhaInicial; i < linhaInicial + 3; i++)
    {
        for(int j = colunaInicial; j < colunaInicial + 3; j++)
        {
            int num = sudoku[i][j];

            if(usado[num])
            {
                return 0;
            }

            usado[num] = 1;
        }
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int instancia = 1; instancia <= n; instancia++)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int valido = 1;

        // Verifica linhas e colunas
        for(int i = 0; i < 9; i++)
        {
            if(!verificaLinha(i) || !verificaColuna(i))
            {
                valido = 0;
            }
        }

        // Verifica os 9 blocos 3x3
        for(int linha = 0; linha < 9; linha += 3)
        {
            for(int coluna = 0; coluna < 9; coluna += 3)
            {
                if(!verificaBloco(linha, coluna))
                {
                    valido = 0;
                }
            }
        }

        printf("Instancia %d\n", instancia);

        if(valido)
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }

        printf("\n");
    }

    return 0;
}
