/**
 * @file aula17.4.c
 * @author cinthiadutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que leia 10 números inteiros e armazene-os em um vetor.

Crie uma função chamada processarVetor que receba o vetor e seu tamanho.
 A função deverá substituir cada elemento do vetor pelo seu dobro.

Ao retornar à main, o programa deverá exibir o vetor após o processamento.

Requisito: utilize a passagem de um vetor como parâmetro e 
faça com que as alterações realizadas pela função sejam aplicadas ao vetor original.
 */

#include <stdio.h>
#include <stdlib.h>
void processarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = vetor[i] * 2;
    }
}

int main() {
    int tam = 10;
    int vetor[tam];
    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]); }

   printf("Vetor após o processamento:\n");
    processarVetor(vetor, tam);
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;     
    



}