/**
 * @file aula18.7.c
 * @author cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-18
 * 
 * @copyright Copyright (c) 2026
 * 
 * Escreva uma função recursiva que receba um número inteiro n como parâmetro e 
 * retorne o n-ésimo termo da sequência de Fibonacci.

Considere que:

o 1º termo da sequência é 0;
o 2º termo da sequência é 1;
a partir do 3º termo, cada termo é obtido pela soma dos dois termos anteriores.
Assim, a sequência é:

0, 1, 1, 2, 3, 5, 8, 13, ...

Após implementar a função, desenvolva um programa que:

leia, pelo teclado, um número inteiro n, que representa a quantidade de termos da sequência que devem ser exibidos;
utilize a função recursiva para obter cada um desses termos, para isso pode usar um laço for;
exiba, na main(), os n primeiros termos da sequência, na ordem em que aparecem.
Por exemplo, se o usuário informar n = 6, o programa deverá exibir:

0 1 1 2 3 5
 */

 #include <stdio.h>
 #include <stdlib.h>

 int retornenfibonacci(int num){

    if (num == 0){
        return 0;
    }if (num ==1){
        return 1;

    }else{
        return retornenfibonacci(num - 1) + retornenfibonacci(num - 2);
    }
 }

    int main(){
        int num, qnts;

    printf("digite a quantidade de termos fibonnacci que deseja exibir: ");
    scanf("%d", &num);

    while (num < 0){
        printf("numero invalido, digite um numero inteiro positivo: ");
        scanf("%d", &num);
    }
    qnts = retornenfibonacci(num);

    for (int i = 0; i < num; i++){
        qnts = retornenfibonacci(i);
        printf("%d ", qnts);
    }


    printf(" o numero que se encontra no termo %d de fibonacci, é %d", num, qnts);

    return 0;
 }