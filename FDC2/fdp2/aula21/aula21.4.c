/**
 * @file aula21.4.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Crie um programa para calcular e exibir o número de palavras contido em um arquivo texto. O usuário deverá informar o nome do arquivo
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
    char nome_arquivo[100];
    FILE *arquivo;
    char caractere;
    int contador_palavras = 0;      

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == ' ' || caractere == '\n' || caractere == '\t') {
            contador_palavras++;
        }
    }
    printf("O número de palavras no arquivo é: %d\n", contador_palavras);

    fclose(arquivo);

    return 0;
}