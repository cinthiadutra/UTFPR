/**
 * @file aula14.4.c
 * @author Cinthia Dutra (cinthiadutra@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-24
 * 
 * @copyright Copyright (c) 2026
 * 
 * Consumo de energia de um setup gamer

Crie uma estrutura Componente para representar um componente de computador.
Para cada componente, armazene: nome do componente e potência elétrica, em watts.

Em seguida, utilize um vetor de estruturas Componente capaz de armazenar os dados de 5 componentes.

Leia do teclado:

os dados dos 5 componentes;
a quantidade de horas que o computador permanece ligado por dia.
Calcule o consumo diário de energia de cada componente utilizando a fórmula:

consumo diário (Wh) = potência (W) × horas de uso por dia
Ao final, exiba:

o consumo diário de cada componente, em Wh;
o consumo diário total do computador, em Wh;
a participação percentual de cada componente no consumo total.
Obs: Para calcular a participação percentual de cada componente, utilize:

participação (%) = consumo do componente / consumo total × 100
Apresente os valores percentuais com duas casas decimais.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float potencia;
} Componente;       

int main() {
    Componente componentes[5];
    float consumo_diario[5];
    float consumo_total = 0;
    int horas_por_dia;

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do componente %d: ", i + 1);
        fgets(componentes[i].nome, sizeof(componentes[i].nome), stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = '\0'; // Remove newline character

        printf("Digite a potência do componente %d (em watts): ", i + 1);
        scanf("%f", &componentes[i].potencia);
        getchar(); // Limpa o buffer do teclado
    }

    printf("Digite a quantidade de horas que o computador permanece ligado por dia: ");
    scanf("%d", &horas_por_dia);

    for (int i = 0; i < 5; i++) {
        consumo_diario[i] = componentes[i].potencia * horas_por_dia;
        consumo_total += consumo_diario[i];
    }

    printf("\nConsumo diário de cada componente (em Wh):\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %.2f Wh\n", componentes[i].nome, consumo_diario[i]);
    }

    printf("\nConsumo diário total do computador: %.2f Wh\n", consumo_total);

    printf("\nParticipação percentual de cada componente no consumo total:\n");
    for (int i = 0; i < 5; i++) {
        float participacao = (consumo_diario[i] / consumo_total) * 100;
        printf("%s: %.2f%%\n", componentes[i].nome, participacao);
    }

    return 0;
}