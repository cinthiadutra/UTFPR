/**
 * @file aula18.7.c
 * @author cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-18
 *
 * @copyright Copyright (c) 2026
 *
 * Crie uma função recursiva que receba um vetor e sua quantidade de elementos
 * e exiba os elementos na ordem inversa.
 * Na main, preencha o vetor e chame a função.

void imprimeReverso(int vetor[], int tamanho);
Exemplo:

Vetor: {10, 20, 30, 40, 50}
Saída: 50 40 30 20 10
Obs.: Você deve apenas exibir de maneira inversa, sem alterar o conteúdo do vetor e sem utilizar laços de repetição.
 */

#include <stdio.h>
#include <stdlib.h>

void imprimeReverso(int vetor[], int tamanho)
{

    if (tamanho == 0)
    {
        return; 
    }
    printf("%d ", vetor[tamanho - 1]);  
    imprimeReverso(vetor, tamanho - 1); 
}

void leVetor(int vetor[], int tamanho, int indice)
{
    if (indice == tamanho)
    {
        return;
    }

    scanf("%d", &vetor[indice]);
    leVetor(vetor, tamanho, indice + 1);
}

int main()
{
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho]; 

    printf("Digite os elementos do vetor:\n");
    leVetor(vetor, tamanho, 0);

    printf("Vetor na ordem inversa: ");
    imprimeReverso(vetor, tamanho);
    printf("\n");

    return 0;
}