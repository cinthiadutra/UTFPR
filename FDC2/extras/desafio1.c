/**
 * @file desafio1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-09-29
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

// Declare suas funções aqui
int isPrime(int num)

{
    int soma = 0;
    for (int x = 1; x <= num; x++)
        if (num % x == 0)
        {
            printf("O numero %d é divisivel por %d", num, x);
            soma += 1;
        }
        else
        {
            printf("O numero %d nao é divisivel por %d", num, x);
        }
    if (soma == 2)
    {
        return 1;
    }
    else
        return 0;
}
int sumOfPrimes(int num1, int num2)
{
    int result = 0;
    int soma = 0;

    for (int i = num1; i <= num2; i++)
    {
        result = isPrime(i);

        if (result == 1)
        {
            soma = soma + i;
        }
        else
            printf("%d", i);
    }

    return soma;
}

int main()
{
    int num1, num2, total;
#ifdef DEBUG_INPUT
    freopen("../.vscode/input.txt", "r", stdin);
#endif
    // Seu código aqui
    scanf("%d", &num1);
    scanf("%d", &num2);

    if ((num1 > 0 && num2 > 0) && num1 < num2)
    {

        total = sumOfPrimes(num1, num2);
        printf("A soma total de numeros primos é:%d", total);
    }
    else
    {
        printf("Invalid input");
    }
    return 0;
}
