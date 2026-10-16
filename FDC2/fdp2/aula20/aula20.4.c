/**
 * @file aula20.4.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * Faça um programa em C que solicite ao usuário a quantidade de linhas e colunas de uma matriz de números inteiros. 
 * Em seguida, aloque dinamicamente uma matriz com as dimensões informadas.
O programa deverá preencher a matriz com valores digitados pelo usuário e, ao final,
 exibir os elementos organizados em linhas e colunas.
Inicialize todos os elementos com zero utilizando calloc() na alocação de cada linha. Após exibir a matriz,
 libere toda a memória alocada,
 lembrando que é necessário liberar primeiro cada linha e, depois, o vetor de ponteiros para as linhas.
 * 
 */

 #include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas, i, j;
    int **matriz;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        matriz[i] = calloc(colunas, sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d.\n", i);
            for (j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz preenchida:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}