/**
 * @file aula16.1.c
 * @author Cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-02
 *
 * @copyright Copyright (c) 2026
 *
 * Faça um programa que implemente uma função que receba três números
 * inteiros como parâmetros e retorne o maior deles. No programa principal,
 * leia os três números, chame a função e apresente o maior valor.
 */

#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

int main()
{
    int num1, num2, num3;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Digite o terceiro número: ");
    scanf("%d", &num3);

    int resultado = maior(num1, num2, num3);
    printf("O maior número é: %d\n", resultado);

    return 0;
}