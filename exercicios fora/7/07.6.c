/**
 * @file 07.6.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-11-10
 * 
 * @copyright Copyright (c) 2026
 * Faça uma função que receba três números inteiros, representando horas, minutos e segundos, e
retorne o tempo total em segundos.
 */

 #include <stdio.h>
 #include <stdlib.h>

 int tempoTotalSegundos(int hora, int min, int seg){

    int horaParaMin = hora*60;

    int minutoParaSegundo= (horaParaMin+min)*60;

    return minutoParaSegundo+seg;}


    int main(){

    int hora, minuto, segundo;    

printf("Para fazer a conversão total de segundos entre primeiro com a hora:");

scanf("%d",&hora);

printf("Para fazer a conversão total de segundos entre agora com o minuto:");

scanf("%d",&minuto);

printf("Para fazer a conversão total de segundos agora com o segundo:");

scanf("%d",&segundo);


printf("a conversão total de segundos foi de: %d", tempoTotalSegundos(hora,minuto,segundo));



 }