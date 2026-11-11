/**
 * @file 07.7.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-11-10
 * 
 * @copyright Copyright (c) 2026
 * Faça uma função que receba uma temperatura em graus Celsius e retorne seu valor em Fahrenheit.
Utilize:
F = C × (9.0 / 5.0) + 32.0
 */
 #include <stdio.h>
 #include <stdlib.h>


float convertTemp(float tmpC){
    return tmpC*(9.0/5.0)+32.0;
}

int main(){
    float tc;
    printf("entre com a temperatura em celsius que deseja transformar: ");

    scanf("%f",&tc);


    printf("a temperatura em Fahrenheit é: %.2f", convertTemp(tc));

}