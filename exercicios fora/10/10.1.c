/**
 * @file 10.1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-11-13
 *
 * @copyright Copyright (c) 2026
 * Aloque dinamicamente um array de 5 números inteiros.
  Peça ao usuário que digite os 5 números no
  espaço alocado, mostre-os na tela e libere a memória.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arrt = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("Escreva o numero %d", i);
        scanf("%d", &arrt[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arrt[i]);
    }
}