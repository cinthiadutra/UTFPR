/**
 * @file aula_14.1
 * @author Cinthia Dutra (cinthiadutra@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-21
 * 
 * @copyright Copyright (c) 2026
 * 
 * 1- Crie uma estrutura Jogador para representar o perfil de um jogador de videogame. A estrutura deve conter: nome e pontuação.
Em seguida, declare e leia do teclado os dados de dois jogadores.
Ao final, calcule e exiba a diferença entre as pontuações dos dois jogadores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char nome[40];
 int pontos;
}Jogador;

int main (){
    Jogador squad[2];
    int diferenca = 0;

    for (size_t i = 0; i < 2; i++)
    {
      printf("Digite seu user :");
      fgets(squad[i].nome, 21, stdin);
        squad[i].nome[strcspn(squad[i].nome,"\n")]='\0';
        setbuf(stdin, NULL);


      printf("Agora Digite sua pontuacao: ");
      scanf("%i", &squad[i].pontos);
        getchar();


      

    }
    diferenca =abs( squad[0].pontos- squad[1].pontos);
    printf(" A diferença de pontuaçâo entre os dois é %i", diferenca);
    



}
