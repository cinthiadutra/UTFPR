/**
 * @file aula15.1.c
 * @author Cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 * 
 * @copyright Copyright (c) 2026
 * o iniciar sua jornada Pokémon, um treinador pode escolher entre três tipos de Pokémon iniciais.
 *  Crie um programa que utilize uma enumeração chamada TipoPokemon, com as opções: Fogo, Água e Grama
 * O programa deve pedir ao usuário para escolher um número (1 para Fogo, 2 para Água e 3 para Grama) e exibir uma mensagem motivadora baseada na escolha, por exemplo:
 *
 * Fogo: "Você escolheu o caminho ardente da vitória!"
 * Água: "A correnteza te levará ao topo!"
 * Grama: "O crescimento e a estratégia são suas armas!"
 * Caso o usuário escolha um número inválido, o programa deve alertá-lo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum TipoPokemon {
    FOGO,
    AGUA,
    GRAMA
};

int main() {
    setlocale(LC_ALL, "");  
    int escolha;
    printf("Escolha seu Pokémon inicial:\n");
    printf("1 - Fogo\n");
    printf("2 - Água\n");
    printf("3 - Grama\n");
    printf("Digite o número correspondente à sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case FOGO   :
            printf("Você escolheu o caminho ardente da vitória!\n");
            break;
        case AGUA:
            printf("A correnteza te levará ao topo!\n");
            break;
        case GRAMA :
            printf("O crescimento e a estratégia são suas armas!\n");
            break;
        default:
            printf("Escolha inválida! Por favor, selecione um número entre 1 e 3.\n");
            break;
    }

    return 0;
}