/**
 * @file aula20.3.c
 * @author cinthiadutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-10-16
 * 
 * @copyright Copyright (c) 2026
 * Faça um programa em C que permita cadastrar os dados de pessoas utilizando uma struct chamada Pessoa, 
 * contendo os campos nome e idade.
O programa deverá solicitar ao usuário a quantidade de pessoas que deseja cadastrar e 
alocar dinamicamente um vetor de estruturas com o tamanho informado. Em seguida, deverá ler o nome e a idade de cada pessoa e, ao final, 
exibir os dados de todos os cadastros.
Utilize malloc() para alocar a memória e free() para liberá-la ao terminar.
 */
#include <stdio.h>
#include <stdlib.h>

 typedef struct {
    char nome[50];
    int idade;
} Pessoa;


int main() {
    int quantidade, i;
    Pessoa *pessoas;

    printf("Digite a quantidade de pessoas que deseja cadastrar: ");
    scanf("%d", &quantidade);

    pessoas = malloc(quantidade * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    printf("Dados cadastrados:\n");
    for (i = 0; i < quantidade; i++) {
        printf("Pessoa %d: Nome: %s, Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }

    free(pessoas);

    return 0;
}