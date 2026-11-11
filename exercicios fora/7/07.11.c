/**
 * @file 07.11.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-11-10
 *
 * @copyright Copyright (c) 2026
 * Elabore uma função que receba três notas e uma letra como parâmetros. Se a letra for A, calcule e
retorne a média aritmética. Se a letra for P, calcule e retorne a média ponderada, com pesos 5, 3 e 2,
respectivamente.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float calculeMediaArit(float a, float b, float c)
{
    return (a + b + c) / 3;
}
float calculeMediaPond(float a, float b, float c)
{
    return (a + b + c) / 5 + 3 + 2;
}

int main()
{
    float notas[3];
    char opcao;
    for (int i = 0; i < 3; i++)
    {
        printf("Digite sua nota na p%d:", i);
        scanf("%f", &notas[i]);
    }
    printf("Escolha o tipo de media P para ponderada e A para aritmetica :");
    scanf("%c", &opcao);
    getchar();

    switch (opcao)
    {
    case 'A':
        printf("A nota é: %f", calculeMediaArit(notas[0], notas[1], notas[2]));
        break;
    case 'a':
        printf("A nota é: %f", calculeMediaArit(notas[0], notas[1], notas[2]));
        break;
    case 'P':
        printf("A nota é: %f", calculeMediaPond(notas[0], notas[1], notas[2]));
        break;
    case 'p':
        printf("A nota é: %f", calculeMediaPond(notas[0], notas[1], notas[2]));
        break;
    default:
        break;
    }
}