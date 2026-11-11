/**
 * @file 03.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-11-10
 *
 * @copyright Copyright (c) 2026
 * Pec ̧a ao usu  ́ario para digitar tr ˆes valores inteiros e imprima a soma deles.
 */

#include <stdio.h>
#include <string.h>

int main()
{

    int num1, num2, num3, soma;

    printf("Escreva o 1 numero: ");
    scanf("%d", &num1);

    printf("Escreva o 2 numero: ");
    scanf("%d", &num2);

    printf("Escreva o 3 numero: ");
    scanf("%d", &num3);

    soma = num1 + num2 + num3;

    printf("A soma dos numeros %d %d %d é %d", num1, num2, num3, soma);

    return 0;
}