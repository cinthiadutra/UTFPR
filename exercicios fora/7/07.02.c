/**
 * @file 07.02.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-11-10
 *
 * @copyright Copyright (c) 2026
 * Fac ̧a uma func ̧  ̃ao que receba a data atual (dia, m ˆes e ano em inteiro) e exiba-a na tela
no formato textual por extenso. Exemplo: Data: 01/01/2000, Imprimir: 1 de janeiro de
2000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *imprimir(int mes)
{
    switch (mes)

    {
    case 1:
        return "Janeiro";
        break;
    case 2:
        return "Fevereiro";
        break;
    case 3:
        return "Março";
        break;
    case 4:
        return "Abril";
        break;

    case 5:
        return "Maio";
        break;

    case 6:
        return "Junho";
        break;
    case 7:
        return "Julho";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
       return "Setembro";
        break;
    case 10:
        return "Outubro";
        break;

    case 11:
        return "Novembro";
        break;

    case 12:
        return "Dezembro";
        break;
    default:
        return "erro de mes";
        break;
    }
}
void imprimirData(int dia, int mes, int ano)
{

    printf("%d/%d /%d\n", dia, mes, ano);
}
void imprimirDataPorExtenso(int dia, int mes, int ano)
{

    printf("%d de %s de %d", dia, imprimir(mes), ano);
}
int main()
{
    int dia, mes, ano;
    printf("Insira o dia: ");
    scanf("%d", &dia);

    printf("Insira o mes: ");
    scanf("%d", &mes);

    printf("Insira o ano: ");
    scanf("%d", &ano);

    imprimirData(dia, mes, ano);

    imprimirDataPorExtenso(dia, mes, ano);
}