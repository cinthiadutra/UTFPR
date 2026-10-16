/**
 * @file aula20.2.c 
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * Faça um programa em C que solicite ao usuário uma quantidade inicial de números inteiros e 
 * aloque dinamicamente um vetor com esse tamanho. O programa deverá permitir que o usuário informe os valores que deseja armazenar.
Depois de preencher o vetor, pergunte se ele deseja adicionar mais números. Caso a resposta seja positiva, 
solicite quantas novas posições deseja acrescentar e utilize realloc() para aumentar o tamanho do vetor. 
Leia os novos valores e, ao final, exiba todos os números armazenados.
O programa deverá utilizar calloc() inicialmente, preservar os valores já existentes no vetor e liberar a memória alocada ao terminar.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade, i, nova_quantidade;
    int *vetor;

    printf("Digite a quantidade inicial de números inteiros que deseja armazenar: ");
    scanf("%d", &quantidade);

    vetor = calloc(quantidade, sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    char resposta;
    printf("Deseja adicionar mais números? (s/n): ");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        printf("Quantos novos números deseja acrescentar? ");
        scanf("%d", &nova_quantidade);

        vetor = realloc(vetor, (quantidade + nova_quantidade) * sizeof(int));
        if (vetor == NULL) {
            printf("Erro ao realocar memória.\n");
            return 1;
        }

        for (i = quantidade; i < quantidade + nova_quantidade; i++) {
            printf("Digite o número %d: ", i + 1);
            scanf("%d", &vetor[i]);
        }
        quantidade += nova_quantidade;
    }

    printf("Valores armazenados:\n");
    for (i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}