/**
 * @file aula21.5.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Elabore um programa para calcular e exibir o número de vezes que cada letra ocorre dentro de um arquivo texto. 
 * Ignore as letras com acento. O usuário deverá informar o nome do arquivo.
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
    char nome_arquivo[100];
    FILE *arquivo;
    int contador_letras[26] = {0}; 
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((c = fgetc(arquivo)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            contador_letras[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            contador_letras[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (contador_letras[i] > 0) {
            printf("A letra '%c' aparece %d vezes.\n", i + 'a', contador_letras[i]);
        }
    }

    fclose(arquivo);
    return 0;
}