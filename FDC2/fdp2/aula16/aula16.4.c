/**
 * @file aula16.4.c
 * @author cinthia dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-09-04
 *
 * @copyright Copyright (c) 2026
 *
 * Implemente uma função que receba como parâmetro a média final
 * de um aluno e retorne seu conceito, de acordo com os seguintes intervalos:

Média entre 9 e 10, incluindo os dois limites: conceito A.
Média maior ou igual a 7 e menor que 9: conceito B.
Média maior ou igual a 5 e menor que 7: conceito C.
Média maior ou igual a 0 e menor que 5: conceito D.
Considere que a média final está entre 0 e 10.

O programa deve ser desenvolvido na seguinte ordem:

Escreva o protótipo da função.
Na função main, leia a média final, chame a função e apresente o conceito retornado.
Implemente a função após a função main.
 */

#include <stdio.h>
#include <stdlib.h>

char calcular_conceito(float media)
{
    if (media >= 9.0 && media <= 10.0)
    {
        return 'A';
    }
    else if (media >= 7.0 && media < 9.0)
    {
        return 'B';
    }
    else if (media >= 5.0 && media < 7.0)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}

int main()
{
    float media;
    char conceito;

    printf("Digite a média final: ");
    scanf("%f", &media);

    while(media < 0.0 || media > 10.0)
    {
        printf("Média inválida. Deve estar entre 0 e 10.\n");
        printf("Digite a média final: ");
        scanf("%f", &media);
    }

        conceito = calcular_conceito(media);
        printf("Conceito: %c\n", conceito);
    

    return 0;
}