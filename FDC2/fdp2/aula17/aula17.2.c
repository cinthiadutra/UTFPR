/**
 * @file aula17.2.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * 
 * 
 * Faça um programa em C que leia dois números inteiros e 
 * crie uma função chamada trocar. A função deverá receber os dois números e trocar seus valores. 
 * Faça uma função main para testar o funcionamento da função desenvolvida.

Exemplo:
Antes da troca:
A = 10
B = 20

Depois da troca:
A = 20
B = 10

Requisito: a função deverá utilizar passagem por referência, a alteração realizada na 
função deve afetar as variáveis originais.
 */

#include <stdio.h>
#include <stdlib.h>
void trocar(int *a, int *b) {
    int temp = *a; // Armazena o valor de a em uma variável temporária
    *a = *b;       // Atribui o valor de b para a
    *b = temp;    // Atribui o valor temporário (original de a) para b
}   

int main(){
    int a, b;   
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Antes da troca:\nA = %d\nB = %d\n", a, b);
    trocar(&a, &b); // Passa os endereços de a e b
    printf("Depois da troca:\nA = %d\nB = %d\n", a, b);

    return 0;
}