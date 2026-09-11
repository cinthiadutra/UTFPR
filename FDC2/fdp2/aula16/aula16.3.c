/**
 * @file aula16.3.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-04
 * 
 * @copyright Copyright (c) 2026
 * 
 * Implemente uma função que receba como parâmetros as três notas de um aluno e
 *  uma letra

Se a letra for A, a função deve calcular a média aritmética das três notas.
Se a letra for P, a função deve calcular a média ponderada, utilizando os
 pesos 5, 3 e 2, respectivamente.
Se a letra for S, a função deve calcular a soma das três notas.
A função deve retornar o valor calculado.

Na função main, leia as três notas e a letra, chame a função e apresente o resultado.
 */

#include <stdio.h>
#include <stdlib.h>


float calcular_media(float nota1, float nota2, float nota3, char letra)
{
    
    switch (letra)
    {
    case 'P':
    case 'p':
        return (nota1 * 5 + nota2 * 3 + nota3 * 2) / 10.0;
    case 'A':
    case 'a':
        return (nota1 + nota2 + nota3) / 3.0;
    case 'S':
    case 's':
        return nota1 + nota2 + nota3;
    default:
        printf("Letra inválida.\n");
        return -1;
    }
    }
    
int main()
   {
    
    float nota1, nota2, nota3;
    char letra;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a letra (A, P ou S): ");
    scanf(" %c", &letra);

    float resultado = calcular_media(nota1, nota2, nota3, letra);
    if (resultado != -1)
    {
        printf("Resultado: %.2f\n", resultado);
    }
}