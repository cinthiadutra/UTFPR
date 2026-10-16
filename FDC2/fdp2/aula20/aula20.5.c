/**
 * @file aula20.5.c
 * @author cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que receba números inteiros enquanto os valores digitados forem positivos.

Inicialmente, aloque dinamicamente um vetor com espaço para 5 números inteiros. 
Sempre que todas as posições disponíveis estiverem preenchidas, 
utilize realloc() para aumentar a capacidade do vetor em mais 5 posições.
Quando o usuário digitar um valor negativo, encerre a leitura e realoque o vetor para que ele tenha exatamente o número de 
posições necessárias para armazenar os valores positivos digitados.

Ao final, exiba os valores recebidos e libere a memória alocada.
 * 
 */

 #include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int capacidade = 5;
    int quantidade = 0;
    int numero;

    vetor = malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite números inteiros positivos (digite um número negativo para encerrar):\n");
    while (1) {
        if (scanf("%d", &numero) != 1) {
            printf("Entrada inválida.\n");
            free(vetor);
            return 1;
        }

        if (numero < 0) {
            break;
        }

        if (quantidade == capacidade) {
            int *novo_vetor = realloc(vetor, (capacidade + 5) * sizeof(int));
            if (novo_vetor == NULL) {
                printf("Erro ao realocar memória.\n");
                free(vetor);
                return 1;
            }
            vetor = novo_vetor;
            capacidade += 5;
        }

        vetor[quantidade++] = numero;
    }

    if (quantidade > 0) {
        int *novo_vetor = realloc(vetor, quantidade * sizeof(int));
        if (novo_vetor == NULL) {
            printf("Erro ao realocar memória.\n");
            free(vetor);
            return 1;
        }
        vetor = novo_vetor;
    } else {
        free(vetor);
        vetor = NULL;
    }

    printf("Valores recebidos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
