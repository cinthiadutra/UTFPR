/**
 * @file aula21.1.c
 * @author cinthia dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Escreva um programa que leia do usuário o nome de um arquivo texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.
 */

 #include <stdio.h>
 #include <stdlib.h>

int main() {
    char nome_arquivo[100];
    FILE *arquivo;
    int contador_linhas = 0;
    char caractere;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            contador_linhas++;
        }
    }

    fclose(arquivo);

    printf("O arquivo possui %d linhas.\n", contador_linhas);

    return 0;
}