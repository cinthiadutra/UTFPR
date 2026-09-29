/**
 * @file aula18.4.c
 * @author cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-18
 *
 * @copyright Copyright (c) 2026
 * Crie uma função recursiva que receba um número inteiro positivo e retorne a quantidade de dígitos desse número.

Exemplos:

quantidadeDigitos(7) -> retorna 1
quantidadeDigitos(42) -> retorna 2
quantidadeDigitos(12345) -> retorna 5
 */

#include <stdio.h>
#include <stdlib.h>

int quantidadeNumeros(int valor)
{
    if (valor < 10)
    {
        return 1;
    }
    else
    {
        return 1 + quantidadeNumeros(valor/10);
    }
}

int main()
{
    int num, qntd;
    printf("Digite o numero que voce deseja saber a quantidade: ");
    scanf("%d", &num);

    while (num < 0)
    {
        printf("Numero invalido. Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    }
    qntd = quantidadeNumeros(num);

    printf(" a quantidade de digitos de %d, é %d", num, qntd);

    return 0;
}
