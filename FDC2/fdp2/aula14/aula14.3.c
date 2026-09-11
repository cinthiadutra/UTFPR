/**
 * @file aula14.3.c
 * @author Cinthia Dutra (cinthiadutra@gmail.com)   
 * @brief 
 * @version 0.1
 * @date 2026-08-24
 * 
 * @copyright Copyright (c) 2026
 * 
 * 
 * Ranking de uma competição de programação

Crie uma estrutura Participante contendo: nome, curso, pontuação obtida em 4 desafios, pontuação total e situação.

Leia do teclado o nome, o curso e as quatro pontuações de um participante.

Calcule a pontuação total e determine a situação do participante de acordo com as seguintes regras:

pontuação total maior ou igual a 300: Classificado;
pontuação total maior ou igual a 200 e menor que 300: Em avaliação;
pontuação total menor que 200: Eliminado.
Ao final, exiba todas as informações do participante, incluindo a pontuação total e a situação.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char curso[50];
    int pontuacao[4];
    int pontuacao_total;
    char situacao[20];
} Participante;

int main() {
    Participante participante;
    setlocale(LC_ALL, "");


    printf("Digite o nome do participante: ");
    fgets(participante.nome, sizeof(participante.nome), stdin);
    participante.nome[strcspn(participante.nome, "\n")] = '\0'; // Remove newline character

    printf("Digite o curso do participante: ");
    fgets(participante.curso, sizeof(participante.curso), stdin);
    participante.curso[strcspn(participante.curso, "\n")] = '\0'; // Remove newline character

    participante.pontuacao_total = 0;
    for (int i = 0; i < 4; i++) {
        printf("Digite a pontuação do desafio %d: ", i + 1);
        scanf("%d", &participante.pontuacao[i]);
        participante.pontuacao_total += participante.pontuacao[i];
    }

    if (participante.pontuacao_total >= 300) {
        snprintf(participante.situacao, sizeof(participante.situacao), "Classificado");
    } else if (participante.pontuacao_total >= 200) {
        snprintf(participante.situacao, sizeof(participante.situacao), "Em avaliação");
    } else {
        snprintf(participante.situacao, sizeof(participante.situacao), "Eliminado");
    }

    printf("\nInformações do Participante:\n");
    printf("Nome: %s\n", participante.nome);
    printf("Curso: %s\n", participante.curso);
    printf("Pontuação Total: %d\n", participante.pontuacao_total);
    printf("Situação: %s\n", participante.situacao);

    return 0;
}
