/**
 * @file aula18.1.c
 * @author cinthia dutra (cinthia.dutra@utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 * Crie uma função recursiva que receba um número inteiro positivo 
 * n e exiba todos os números pares de n até 0. Na main, 
 * receba um numero do teclado e chame a função recursiva.
Exemplo:

Entrada:
10

Saída:
10 8 6 4 2 0
 */

#include <stdio.h>
#include <stdlib.h>

void numerosPares(int num){
    if(num == 0){
        printf("%d ", num);
        return;
    } else
    if(num % 2 == 0){
        printf("%d ", num);
    }
    numerosPares(num - 1);
}

int main(){
    int num;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    while(num < 0){
        printf("Numero invalido. Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    }
    numerosPares(num);
}