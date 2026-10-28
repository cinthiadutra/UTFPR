/**
 * @file aula21.6.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma palavra, e o programa informe o número de vezes que aquela palavra aparece
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
    char nome_arquivo[100], palavra[100];
    FILE *arquivo;          

    int contador_ocorrencias = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    printf("Digite a palavra a ser contada: ");
    scanf("%s", palavra);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }   
// logica para contar as ocorrências da palavra no arquivo
    char c;
    int i = 0;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == palavra[i]) {
            i++;
            if (palavra[i] == '\0') {
                contador_ocorrencias++;
                i = 0;
            }
        } else {
            i = 0;
        }
    }

    printf("A palavra '%s' aparece %d vezes no arquivo.\n", palavra, contador_ocorrencias);

    fclose(arquivo);
    return 0;
}