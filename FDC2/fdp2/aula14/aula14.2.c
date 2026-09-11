/**
 * @file aula14.2.c
 * @author Cinthia Dutra (cinthiadutra@gmail.com)
 * @version 0.1
 * @date 2026-08-24
 *
 * @copyright Copyright (c) 2026
 *
 * Você precisa organizar os dados de uma reunião de uma equipe de desenvolvimento,
 * para isso, utilizando struct e typedef, crie os seguintes tipos de dados:

Horario: composto por hora, minuto e segundo;
Data: composta por dia, mês e ano;
Reuniao: composta por título, local, data e horário.
Em seguida, declare uma variável do tipo Reuniao e leia do teclado todas as suas informações.

Ao final, exiba os dados da reunião de forma organizada.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char titulo[100];
    char local[100];
    Data data;
    Horario horario;
} Reuniao;

int main()
{
    Reuniao reuniao;

    printf("Digite o título da reunião: ");
    fgets(reuniao.titulo, sizeof(reuniao.titulo), stdin);
    reuniao.titulo[strcspn(reuniao.titulo, "\n")] = '\0'; // Remove newline character

    printf("Digite o local da reunião: ");
    fgets(reuniao.local, sizeof(reuniao.local), stdin);
    reuniao.local[strcspn(reuniao.local, "\n")] = '\0'; // Remove newline character

    printf("Digite a data da reunião (dia mês ano): ");
    scanf("%d /%d /%d", &reuniao.data.dia, &reuniao.data.mes, &reuniao.data.ano);

    printf("Digite o horário da reunião (hora minuto segundo): ");
    scanf("%d :%d :%d", &reuniao.horario.hora, &reuniao.horario.minuto, &reuniao.horario.segundo);

    printf("\nDados da Reunião:\n");

    printf("Reunião: %s \n "
           "Local: %s \n"
           "Data: %02d/%02d/%04d\n "
           "Horário: %02d:%02d:%02d\n",
           reuniao.titulo, reuniao.local, reuniao.data.dia, reuniao.data.mes, reuniao.data.ano, reuniao.horario.hora, reuniao.horario.minuto, reuniao.horario.segundo);
    return 0;
}