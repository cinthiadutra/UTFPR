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
    int d1, u1, s1, m1;
    int d2, c2, u2, s2;
    int d3, c3, u3, s3;

    if (num > 0 && num < 10)
    {
        s1 = num;
    }
    else

        if (num >= 10 && num < 100)
    {
        d1 = num / 10;
        u1 = num % 10;
        s1 = d1 + u1;
    }
    else

        if (num >= 100 && num < 1000)
    {
        c2 = num / 100;
        u2 = num % 100;
        d2 = (num - (c2 * 100)) / 10;

        s2 = c2 + d2 + u2;
    }

    else
    {
        m1 = num / 1000;
        c3 = (num - (m1 * 1000)) / 100;
        d3 = ((num - (m1 * 1000)) - c3 * 100) / 10;
        u3 = num % 1000;
        s3 = m1 + c3 + d3 + u3;
    }

    return s1+s2+s3;
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