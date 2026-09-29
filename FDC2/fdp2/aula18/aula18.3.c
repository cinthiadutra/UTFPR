/**
 * @file aula18.3.c
 * @author cinthia dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-18
 *
 * @copyright Copyright (c) 2026
 * Crie uma função que retorne o fatorial de um número passado por parâmetro. Na main, receba um numero do teclado, chame a função recursiva exiba o valor do fatorial retornado pela função.

fatorial(n):
    = 1 se n=0
    = n x fatorial (n-1) se n>0
Texto de resposta Questão 3
 */

#include <stdio.h>
#include <stdlib.h>

int fatorial(int num)
{

    if (num == 0)
    {
        return 1;
    }
    else
    {
        int fator;
         fator = num * fatorial(num - 1);
        return fator;

    }
};

int main()
{
    int num, fatorialGeral;
    printf("Digite o numero que voce deseja saber o fatorial: ");
    scanf("%d", &num);

    while (num < 0)
    {
        printf("Numero invalido. Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    }
    fatorialGeral = fatorial(num);

    printf(" o fatorial de %d, é %d", num, fatorialGeral);

    return 0;
}
