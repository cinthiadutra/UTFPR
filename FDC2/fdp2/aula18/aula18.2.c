/**
 * @file aula18.2.c
 * @author cinthia dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-18
 *
 * @copyright Copyright (c) 2026
 *
 * Crie uma função recursiva que receba um número inteiro positivo e
 * retorne a soma de todos os números pares entre o número e zero. Na main,
 * receba um numero do teclado, chame a função recursiva exiba a soma retornada
 * pela função.

Exemplo:

Digite um numero: 10
A soma dos pares é 30
pois: 2 + 4 + 6 + 8 + 10 = 30

Texto de resposta Questão 2
 *
 */

#include <stdio.h>
#include <stdlib.h>

int somaPares(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num % 2 == 0)
    {
        int soma;
        soma = num + somaPares(num - 1);
        printf("o numero é %i e a soma %d\n " , num, soma);

        return soma;

    }
    else
    {
        return somaPares(num - 1);
    }
}

int main()
{
    int num, soma;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    while (num < 0)
    {
        printf("Numero invalido. Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    }
    soma = somaPares(num);

    printf("a soma dos pares é %i \n", soma);
}
