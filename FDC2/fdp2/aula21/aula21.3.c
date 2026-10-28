/**
 * @file aula21.3.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Escreva um programa para converter o conteúdo de um arquivo texto em caracteres maiúsculos. 
 * O programa deverá ler do usuário o nome do arquivo a ser convertido e o nome do arquivo a ser salvo.
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
    char nome_arquivo_entrada[100], nome_arquivo_saida[100];
    FILE *arquivo_entrada, *arquivo_saida;
    char caractere;
    int c;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;           
    }

    arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return 1;
    }

    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere >= 'a' && caractere <= 'z') {
            caractere = caractere - 32; // Converte para maiúsculo
        }
        fputc(caractere, arquivo_saida);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}