/**
 * @file aula21.2.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Escreva um programa que leia do usuário os nomes de dois arquivos texto. 
 * Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo)

Texto de resposta Questão 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char nome_arquivo1[100], nome_arquivo2[100], nome_arquivo_saida[100];
    FILE *arquivo1, *arquivo2, *arquivo_saida;
    char caractere;

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nome_arquivo1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nome_arquivo2);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    arquivo1 = fopen(nome_arquivo1, "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir o primeiro arquivo.\n");
        return 1;
    }

    arquivo2 = fopen(nome_arquivo2, "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o segundo arquivo.\n");
        fclose(arquivo1);
        return 1;
    }

    arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    
    while ((caractere = fgetc(arquivo1)) != EOF) {
        fputc(caractere, arquivo_saida);
    }

    
    while ((caractere = fgetc(arquivo2)) != EOF) {
        fputc(caractere, arquivo_saida);
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo_saida);

    printf("Conteúdo dos arquivos copiado com sucesso para %s.\n", nome_arquivo_saida);

    return 0;
}