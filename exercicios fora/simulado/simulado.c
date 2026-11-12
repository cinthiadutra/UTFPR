/**
 * @file simulado.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief simulado para p2 sobre alocacao dinamica, arquivos
 * @version 0.1
 * @date 2026-11-11
 *
 * @copyright Copyright (c) 2026
 * simulado
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "players.h"

void imprimirRelatorio(
    const char *paises[],
    int vitorias[],
    int derrotas[])
{
    FILE *arquivo = fopen("ranking_report.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar o relatorio.\n");
        return;
    }

    printf("PAIS       |WINS |LOSSES| WINRATE|\n");
    fprintf(arquivo, "PAIS       |WINS |LOSSES| WINRATE|\n");

    for (int p = 0; p < 6; p++)
    {
        int partidas = vitorias[p] + derrotas[p];
        int winrate = 0;

        if (partidas > 0)
        {
            winrate = (int)(100.0 * vitorias[p] / partidas);
        }

        printf("%-11s|%5d|%6d|%7d%%|\n",
               paises[p], vitorias[p], derrotas[p], winrate);

        fprintf(arquivo, "%-11s|%5d|%6d|%7d%%|\n",
                paises[p], vitorias[p], derrotas[p], winrate);
    }

    if (fclose(arquivo) != 0)
    {
        printf("Erro ao finalizar o arquivo.\n");
        return;
    }

    printf("\nRelatorio salvo em ranking_report.txt\n");
}

void somaPorPais(Jogador jog[], int quantidade)
{
    const char *paises[6] = {
        "Brasil", "EUA", "França",
        "Inglaterra", "China", "Japão"};

    const char *minusculos[6] = {
        "brasil", "eua", "frança",
        "inglaterra", "china", "japão"};

    int vitorias[6] = {0};
    int derrotas[6] = {0};

    for (int p = 0; p < 6; p++)
    {
        for (int i = 0; i < quantidade; i++)
        {
            int mesmoPais =
                strcmp(jog[i].pais, paises[p]) == 0 ||
                strcmp(jog[i].pais, minusculos[p]) == 0;

            if (p == 5 &&
                (strcmp(jog[i].pais, "Japao") == 0 ||
                 strcmp(jog[i].pais, "japao") == 0))
            {
                mesmoPais = 1;
            }

            if (mesmoPais)
            {
                vitorias[p] += jog[i].vitorias;
                derrotas[p] += jog[i].derrotas;
            }
        }
    }

    /* Só imprime depois de calcular todos os países. */
    imprimirRelatorio(paises, vitorias, derrotas);
}

int main()
{
    FILE *arquivo;
    Jogador *jogadores;
    Jogador *jogadoresTemp;
    char pais[20];

    int capacidade = 5;
    int quantidade = 0;
    arquivo = fopen("players.dat", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    jogadores = malloc(5 * sizeof(Jogador));
    if (jogadores == NULL)
    {
        perror("Erro ao realocar!");
        exit(EXIT_FAILURE);
    } // else

    while (1)
    {
        printf("Entre com um dos paises [Brasil, EUA, França, Inglaterra, China e Japão]: ");

        if (scanf("%19s", pais) != 1)
        {
            free(jogadores);
            return 1;
        }

        if (strcmp(pais, "fim") == 0)
        {
            break;
        }

        if (quantidade == capacidade)
        {
          int  novaCapacidade = capacidade+5;
            Jogador *temporario = realloc(
                jogadores, novaCapacidade * (sizeof(Jogador)));

            if (temporario == NULL)
            {
                printf("Erro ao aumentar o vetor.\n");
                free(jogadores);
                return 1;
            }

            jogadores = temporario;
            capacidade += 5;
        }

        strcpy(jogadores[quantidade].pais, pais);

        printf("Entre com o nome do Jogador:");
        scanf(" %19s", jogadores[quantidade].nickname);

        printf("Entre com o numero de vitorias do Jogador:");
        scanf(" %d", &jogadores[quantidade].vitorias);
        getchar();

        printf("Entre com o numero de derrotas do Jogador:");
        scanf(" %d", &jogadores[quantidade].derrotas);
        getchar();
        quantidade++;
    }

    jogadoresTemp = realloc(jogadores, (capacidade + quantidade) * sizeof(Jogador));

    if (jogadoresTemp == NULL)
    {
        free(jogadores);
        return 1;
    }

    jogadores = jogadoresTemp;
    capacidade += 5;

    fwrite(jogadores, sizeof(Jogador), quantidade, arquivo);
    jogadoresTemp = realloc(jogadores, (quantidade) * sizeof(Jogador));

    fclose(arquivo);

    somaPorPais(jogadores, quantidade);

    free(jogadores);
    fopen("players.dat", "rb");
}
