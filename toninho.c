#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n; // Quanitdade de vazamentos no dia
    int atual = 0;
    int tempoTotal = 0;

    scanf("%d", &n);
    bool visitado[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        visitado[i] = false;
    }
    visitado[0] = true;
    int T[n + 1][n + 1];
    int rota[n + 2];
    rota[0] = 0;

    // Inicializando a matriz
    for (int i = 0; i < n + 1; i++)
    { // coluna
        for (int j = 0; j < n + 1; j++)
        { // linha
            scanf("%d", &T[i][j]);
        }
    }

    /* // Teste: imprimir a matriz para conferir
    printf("Matriz de tempos:\n");
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }*/

    // Guloso
    for (int i = 1; i < n + 1; i++) // não pode começar com zero
    {
        int menorTempo = 99999;
        int proximo = -1;

        for (int j = 0; j < n + 1; j++)
        {
            if (!visitado[j] && T[atual][j] < menorTempo)
            {
                menorTempo = T[atual][j];
                proximo = j;
            }
        }
        rota[i] = proximo;
        tempoTotal += T[atual][proximo];
        visitado[proximo] = true;
        atual = proximo;
    }

    rota[n + 1] = 0;
    tempoTotal += T[atual][0];

    for (int i = 0; i < n + 2; i++)
    {
        printf("%d", rota[i]);
        if (i < n + 1)
        {
            printf(" -> ");
        }
    }

    printf("\n%d", tempoTotal);

    printf("\n");
    return 0;
}