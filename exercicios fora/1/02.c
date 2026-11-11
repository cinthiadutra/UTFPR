/**
 * @file 02.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-11-10
 * 
 * @copyright Copyright (c) 2026
 * Fac ̧a um programa que leia um n  ́umero real e o imprima
 */
#include <stdio.h>
#include <string.h>

int main(){
    float numero;

    printf("digite um numero: ");
    scanf("%f",&numero);

    printf("O numero é: %0.2f \n",numero);

    return 0;

}