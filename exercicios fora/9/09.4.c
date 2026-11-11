/**
 * \file 09.4.c
 * \brief trocar o conteudo das variaveis
 * \author Cinthia Dutra
 * \date 11/11/2026
 */

/*
 * Enunciado:
 * Leia dois valores inteiros e chame uma função que troque o conteúdo das duas variáveis. Após a
 * chamada, A deve conter o valor original de B e B, o valor original de A. Exiba os resultados.
 */
#include <stdio.h>
void troca(int *a, int *b)
{
    int aT = 0;
    int bT = 0;

    aT = *a;
    bT = *b;

    a = &bT;
    b = &aT;

    printf("Valores na func a:%d b:%d \n",*a,*b);
}
int main()
{

    int a, b;

    printf("Escreve o valor da primeira variavel: ");
    scanf(" %d", &a);

    printf("Escreve o valor da segunda variavel: ");
    scanf(" %d", &b);

    printf("valores: a: %d b: %d \n", a, b);

    troca(&a, &b);

}
