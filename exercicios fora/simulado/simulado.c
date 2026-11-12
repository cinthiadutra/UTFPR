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

typedef struct
{
    char pais[20];
    char nickname[20];
    int vitorias;
    int derrotas;

} Jogador;

void alocar(int tam)
{
    Jogador *vetJogTemp;
    Jogador *vetJog = calloc(tam, sizeof(Jogador));

    if (vetJog == NULL)
    {
        vetJogTemp = realloc(vetJog, 10 * sizeof(int));
        if (vetJogTemp != NULL)
        {
            vetJog = vetJogTemp;
        }
        else
        {
            perror("Erro ao realocar!");
        } // else
    }
}

// void calculoFinal(int wins, int loss , int tam)
// {
//     int somaBrasil, somaEUA, somaFranca,somaInglaterra,somaChina,somaJapao;
//     int somaBrasilD, somaEUAD, somaFrancaD,somaInglaterraD,somaChinaD,somaJapaoD;

//     Jogador jogador[tam];
//     for (int i =0; i<tam; i++){
//        if(jogador[i].pais =="Brasil"||jogador[i].pais =="brasil"){
//         somaBrasil = jogador.
//     }

// }

int somaV(Jogador jog[], int v)
{
    if (v == 0)
    {
        return 0;
    }

    return jog[v - 1].vitorias + somaV(jog, v - 1);
}
int somaT(Jogador jog[], int v)
{
    if (v == 0)
    {
        return 0;
    }

    return jog[v - 1].derrotas + somaT(jog, v - 1);
}

int calculeWinrate(int der, int vit)
{

    return (vit / (vit + der)) * 100;
}

void somaPorPais(Jogador jog[])
{
    if (strcmp(jog->pais, "Brasil") == 0 || strcmp(jog->pais, "brasil") == 0)
        printf("Brasil | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));
    else if (strcmp(jog->pais, "EUA") == 0 || strcmp(jog->pais, "eua") == 0)
        printf("EUA | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));

    else if (strcmp(jog->pais, "França") == 0 || strcmp(jog->pais, "frança") == 0)
        printf("França | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));

    else if (strcmp(jog->pais, "Inglaterra") == 0 || strcmp(jog->pais, "inglaterra") == 0)
        printf("Inglaterra | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));

    else if (strcmp(jog->pais, "China") == 0 || strcmp(jog->pais, "china") == 0)
        printf("China | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));

    else if (strcmp(jog->pais, "Japao") == 0 || strcmp(jog->pais, "japao") == 0 || strcmp(jog->pais, "Japão") == 0 || strcmp(jog->pais, "japão") == 0)
        printf("Japão | %d  | %d | %d %%", somaV(jog, 5), somaT(jog, 5), calculeWinrate(somaV(jog, 5), somaT(jog, 5)));
}

int main()
{
    FILE *arquivo;
    Jogador *jogadores;
    Jogador *jogadoresTemp;

    int capacidade, vitorias, derrotas, quantidade, i;

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
    capacidade = 5;
    i = 0;
    printf("Entre com o nome do pais:");
    fgets(jogadores[i].pais, 20, stdin);
    jogadores[i].pais[strcspn(jogadores[i].pais, "\n")] = '\0';
    setbuf(stdin, NULL);
    while (strcmp(jogadores[i].pais, "fim") != 0 && capacidade != 0)
    {

        printf("Entre com o nome do Jogador:");
        fgets(jogadores[i].nickname, 20, stdin);
        jogadores[i].nickname[strcspn(jogadores[i].nickname, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("Entre com o numero de vitorias do Jogador:");
        scanf(" %d", &vitorias);
        getchar();

        printf("Entre com o numero de derrotas do Jogador:");
        scanf(" %d", &derrotas);
        getchar();
        quantidade = i;
        i++;
        fwrite(jogadores, sizeof(Jogador), quantidade, arquivo);
        fclose(arquivo);
     
    }

    {
        jogadores = realloc(jogadores, i);
        fwrite(jogadores, sizeof(Jogador), quantidade, arquivo);
        fclose(arquivo);
    }
    somaPorPais(jogadores);

    free(jogadores);
    fopen("players.dat", "rb");
}
