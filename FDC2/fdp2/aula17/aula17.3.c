/**
 * @file aula17.3.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que leia dois números inteiros e crie uma função chamada maiorMenor.
 *  A função deverá receber os dois números e determinar:

qual é o maior;
qual é o menor.
Os dois resultados deverão ser enviados de volta à função main por meio dos parâmetros da função.

Requisito: utilize passagem por referência (retorno por referencia) para retornar os dois resultados.
 */

#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *num1, int *num2, int *maior, int *menor ){
if (*num1 > *num2) {
        *maior = *num1;
        *menor = *num2;
    } else {
        *maior = *num2;
        *menor = *num1;
    }
    printf("O maior número é: %d\n", *maior);
    printf("O menor número é: %d\n", *menor);
};

int main() {
    int num1, num2, maior, menor;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    maiorMenor(&num1, &num2, &maior, &menor);

    return 0;
}