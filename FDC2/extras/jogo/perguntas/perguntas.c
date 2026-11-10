/**
 * @file perguntas.c
 * @brief Implementacao da leitura das perguntas em CSV.
 */

#include "perguntas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *abrir_arquivo_perguntas(void)
{
    const char *caminhos[] = {
        "perguntas/perguntas.csv",
        "jogo/perguntas/perguntas.csv",
        "FDC2/extras/jogo/perguntas/perguntas.csv",
        "extras/jogo/perguntas/perguntas.csv"
    };

    for (unsigned int i = 0; i < sizeof(caminhos) / sizeof(caminhos[0]); i++) {
        FILE *arquivo = fopen(caminhos[i], "r");

        if (arquivo != NULL) {
            return arquivo;
        }
    }

    return NULL;
}

static int separar_campos(char *linha, char *campos[], int limite)
{
    int quantidade = 0;
    char *inicio = linha;

    while (quantidade < limite) {
        char *separador = strchr(inicio, ',');

        if (separador != NULL) {
            *separador = '\0';
        }
        campos[quantidade++] = inicio;

        if (separador == NULL) {
            break;
        }
        inicio = separador + 1;
    }

    if (quantidade > 0) {
        campos[quantidade - 1][strcspn(campos[quantidade - 1], "\r\n")] = '\0';
    }

    return quantidade;
}

int perguntas_carregar_indice(Pergunta *pergunta, int indice)
{
    char linha[2048];
    char *campos[13];
    FILE *arquivo;

    if (pergunta == NULL || indice < 0) {
        return 0;
    }

    arquivo = abrir_arquivo_perguntas();
    if (arquivo == NULL || fgets(linha, sizeof(linha), arquivo) == NULL) {
        if (arquivo != NULL) {
            fclose(arquivo);
        }
        return 0;
    }

    for (int i = 0; i <= indice; i++) {
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            fclose(arquivo);
            return 0;
        }
    }

    if (separar_campos(linha, campos, 13) != 13) {
        fclose(arquivo);
        return 0;
    }
    pergunta->id = atoi(campos[0]);
    snprintf(pergunta->dificuldade, sizeof(pergunta->dificuldade), "%s",
             campos[1]);
    snprintf(pergunta->enunciado, sizeof(pergunta->enunciado), "%s",
             campos[7]);

    for (int i = 0; i < 4; i++) {
        snprintf(pergunta->alternativas[i],
                 sizeof(pergunta->alternativas[i]), "%s", campos[8 + i]);
    }

    pergunta->resposta_correta = campos[12][0];

    fclose(arquivo);
    return 1;
}

int perguntas_carregar_primeira(Pergunta *pergunta)
{
    return perguntas_carregar_indice(pergunta, 0);
}