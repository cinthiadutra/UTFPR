/**
 * @file 07.1.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-11-10
 * 
 * @copyright Copyright (c) 2026
 * Crie uma func ̧  ̃ao que recebe como par ˆametro um n  ́umero inteiro e devolve o seu dobr
 */

 #include <stdio.h>
 #include <stdlib.h>

 int dobro(int num){
    return num *2;
 }
 int main(){
    int num;
    printf("Entre com um numero: ");
    scanf("%d",&num);

    printf("O dobro de %d é :  %d", num, dobro(num));
    return 0;
 }