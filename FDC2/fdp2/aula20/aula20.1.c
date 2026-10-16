/**
 * @file aula20.1.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que solicite ao usuário a quantidade de números inteiros que deseja armazenar.
Em seguida, aloque dinamicamente um vetor com essa quantidade de posições, leia os números digitados e, ao final, exiba todos os valores armazenados.
O programa deverá utilizar malloc() para alocar a memória e free() para liberá-la ao terminar.
 * 
 */

 #include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade, i;
    int *vetor;

    printf("Digite a quantidade de números inteiros que deseja armazenar: ");
    scanf("%d", &quantidade);


    vetor = malloc(quantidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }


    for (i = 0; i < quantidade; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Valores armazenados:\n");
    for (i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

   
    free(vetor);

    return 0;
}