/**
 * @file 07.3.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-11-10
 *
 * @copyright Copyright (c) 2026
 * Faça uma função que receba um número e retorne 1 se ele for positivo, -1 se ele for negativo e 0 se
ele for igual a zero
 */
#include <stdio.h>
#include <stdlib.h>

int verificaNum(int num)
{
    if (num > 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num;
    printf("Escreva um numero: ");

    scanf("%d", &num);

    printf(" %d", verificaNum(num));
    return 0;
}