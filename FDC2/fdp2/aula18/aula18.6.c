/**
 * @file aula18.7.c
 * @author cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-18
 *
 * @copyright Copyright (c) 2026
 *
 * Crie uma função recursiva que retorne quantas vezes um valor procurado aparece nos tamanho elementos do vetor.
 * Na main, preencha o vetor, chame a função e exiba a quantidade de ocorrências retornadas.

int contaOcorrencias(int vetor[], int tamanho, int valorProcurado);
Exemplo:

Vetor: {2, 5, 2, 8, 2, 4}
valor = 2

Resultado: 3 ocorrências
 */

#include <stdio.h>
#include <stdlib.h>

int contaOcorrencias(int vetor[], int tam, int valorProcurado)
{
    if (tam == 0)
    {
        return 0; 
    }
    
    return (vetor[tam - 1] == valorProcurado) + contaOcorrencias(vetor, tam - 1, valorProcurado);
}

int main()
{
    int tamanho, valorProcurado;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho]; 

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valorProcurado);

    int ocorrencias = contaOcorrencias(vetor, tamanho, valorProcurado);
    printf("o vetor é {");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", vetor[i]);
        if (i < tamanho - 1)
        {
            printf(", ");
        }
    }
    printf("}  Resultado: %d ocorrências\n", ocorrencias);

    free(vetor);
    return 0;
}