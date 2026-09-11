/**
 * @file aula17.1.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * Faça um programa em C que leia um número inteiro e possua uma função 
 * chamada dobrar.

A função deverá receber o número como parâmetro e alterar seu valor, 
multiplicando-o por 2.

O programa deverá:

Ler o número na main;
Exibir o valor original;
Chamar a função dobrar;
Exibir o valor após a alteração.
Requisito: utilize passagem por referência para que a alteração realizada pela função seja refletida na variável original.

Texto de resposta Questão 1
 */

#include <stdio.h>
#include <stdlib.h>

void dobrar(int *num) {
    *num *= 2; // Multiplica o valor apontado por num por 2
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Valor original: %d\n", numero);

    dobrar(&numero); // Passa o endereço de numero para a função dobrar

    printf("Valor após a alteração: %d\n", numero);

    return 0;
}