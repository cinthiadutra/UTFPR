/**
 * @file aula16.5.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-04
 * 
 * @copyright Copyright (c) 2026
 * Implemente uma função que receba como parâmetro um número inteiro não negativo valor e 
 * retorne o fatorial desse número.

Na função main, utilize argc e argv para receber valor,
 passe o valor recebido para a função e apresente o resultado.
 */

#include <stdio.h>
#include <stdlib.h>

int fatorial( int valor) {
    valor = (valor == 0) ? 1 : valor * fatorial(valor - 1);
    return valor;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_inteiro_nao_negativo>\n", argv[0]);
        return 1;
    }

    int valor = atoi(argv[1]);
    if (valor < 0) {
        printf("Erro: O valor deve ser um número inteiro não negativo.\n");
        return 1;
    }

    int resultado = fatorial(valor);
    printf("O fatorial de %d é %d\n", valor, resultado);

    return 0;
}