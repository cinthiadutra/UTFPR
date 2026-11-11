/**
 * \file 09.1.c
 * \brief modificar o valor do ponteiro
 * \author Cinthia Dutra
 * \date 11/11/2026
 */

/*
 * Enunciado:
 * Declare um inteiro, um real e um char, e ponteiros para esses tipos. Associe as variáveis aos
 * ponteiros usando &. Modifique os valores por meio dos ponteiros e imprima os valores das variáveis
 * antes e depois.
 */

#include <stdio.h>
int main()
{
    int numInt = 10;
    float numFloat = 5.5;
    char letra = 'C';

    int *ptfInt;
    float *ptrFloat;
    char *ptrLet;

    ptfInt = &numInt;
    ptrFloat = &numFloat;
    ptrLet = &letra;

    printf("%f %d %c\n", *ptrFloat, *ptfInt, *ptrLet);

    *ptfInt = 20;
    *ptrFloat = 11.9;
    *ptrLet = 'w';

    printf("depois %f %d %c", *ptrFloat, *ptfInt, *ptrLet);
}