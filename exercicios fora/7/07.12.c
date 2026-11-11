/**
 * @file 07.12.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-11-11
 *
 * @copyright Copyright (c) 2026
 * Escreva uma função que receba um número inteiro maior que zero e retorne a soma de seus
algarismos. Por exemplo, para 251, o resultado é 8 (2 + 5 + 1). Se o número lido não for maior que
zero, o programa deverá terminar exibindo “Número inválido”.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int funcaoSomar(int num)
{
    int soma = 0;

    while (num > 0)
    {
        soma += num % 10;
        num /= 10;
    }

    return soma;
}

int main()
{
    int num;
    printf("Entre com um numero maior que zero: ");

    scanf("%d", &num);

    if (num > 0)
    {
        printf("A soma dos numeros é: %d", funcaoSomar(num));
    }
    else
    {
        printf("numero Inválido\n");
    }
}