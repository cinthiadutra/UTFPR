/**
 * @file aula16.2.c
 * @author Cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-04
 * 
 * @copyright Copyright (c) 2026
 * 
 * Implemente uma função que receba como parâmetros o sexo (caractere) 
 * e a altura de uma pessoa (real), calcule e retorne seu peso ideal, 
 * utilizando as fórmulas a seguir:
Homens: (72.7 × altura) − 58
Mulheres: (62.1 × altura) − 44.7

Na função main, leia o sexo e a altura de uma pessoa, 
chame a função e apresente o peso ideal calculado.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula o peso ideal com base no sexo e altura.
 * 
 * @param sexo Caractere representando o sexo ('M' ou 'F').
 * @param altura Altura da pessoa em metros.
 * @return float Peso ideal calculado. Retorna -1 em caso de sexo inválido.
 */

float peso_ideal(char sexo, float altura)
{
    if (sexo == 'M' || sexo == 'm')
    {
        return (72.7 * altura) - 58;
    }
    else if (sexo == 'F' || sexo == 'f')
    {
        return (62.1 * altura) - 44.7;
    }
    else
    {
        printf("Sexo inválido.\n");
        return -1; // Retorna -1 para indicar erro
    }
}

int main()
{
    char sexo;
    float altura;

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    float peso = peso_ideal(sexo, altura);
    if (peso != -1)
    {
        printf("O peso ideal é: %.2f kg\n", peso);
    }

    return 0;
}