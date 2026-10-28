/**
 * @file simulado1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-10-08
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    Ferro,
    Bronze,
    Prata,
    Ouro,
    Diamante,
    Imortal
} Patentes;

typedef struct
{
    char nome[50];
    int vitorias;
    int derrotas;
    Patentes patente;
    int pontos;
} Jogador;

float calculeWinrate(int vitorias, int derrotas)
{
    int partidas = vitorias + derrotas;
    if (partidas == 0)
    {
        return 0;
    }
    return (int)((double)vitorias / partidas * 100.0);
}

void imprimeTabela(Jogador jog[])
{

    printf("Nome | Winrate (%%)\n");

    for (int i = 0; i <= 6; i++)
    {
        printf("%s | %0.2f\n", jog[i].nome, calculeWinrate(jog[i].vitorias, jog[i].derrotas));
    }
}

void escolhePatente(Patentes patente){
switch (patente)
{
case 0:
    printf("Jogador líder da patente Ferro");
    break;
case 1:
printf("Jogador líder da patente Bronze");
    break;  
 case 2:
printf("Jogador líder da patente Prata");
    break;
case 3:
printf("Jogador líder da patente Ouro");
    break;
case 4:
printf("Jogador líder da patente Diamante");
    break;
case 5:
printf("Jogador líder da patente Imortal");
    break;     

default:
printf("Jogador Sem patente");
    break;
}
}
int comparaJogador(Jogador jog[], int patenteEscolhida)
{
    int maior = 0 ;

    for (size_t i = 0; i <= 6; i++)
    {
        if ((int)jog[i].patente == patenteEscolhida)
        {

            if (jog[i].pontos > jog[maior].pontos)
            {

                maior = i;
            }
        }
    }

    return maior;
}
void imprimeLider(int patente, Jogador jogador[])
{
    int lider = comparaJogador(jogador, patente);
    escolhePatente(patente);
 
    printf("\nNome: %s\nVitorias: %d\nDerrotas: %d\nPontos: %d\n",
           jogador[lider].nome, jogador[lider].vitorias,
           jogador[lider].derrotas, jogador[lider].pontos);
}



void buscarPorNome( char nomeBuscado[50], Jogador jog[])

{
    int i = 0;

    for (int j = 0; j <= 6; j++)
    {

        if (strcmp(nomeBuscado, jog[j].nome) == 0)
        {
            i = j;
        }
    }
    printf(" Dados Encontrados: \n Vitórias: %d\n, Derrotas:%d\n", jog[i].vitorias, jog[i].derrotas);
}

int somapartida(Jogador jogador[], int quantidade)
{
    if (quantidade == 0)
    {
        return 0;
    }

    return jogador[quantidade - 1].vitorias +
           jogador[quantidade - 1].derrotas +
           somapartida(jogador, quantidade - 1);
}
int pontos(int win, int los){
    return (
        (win*3)+los*0);
}
int main()
{
    Jogador jogador[6];
    Patentes pt;
    char nomeEscolhido[50];
    int patescolhida = 0;

    for (int i = 0; i< 6; i++)
    {
        printf("Insira o nome do jogador %d: ",i+1);
        fgets(jogador[i].nome, 50, stdin);
        jogador[i].nome[strcspn(jogador[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);
do  
{
        printf(" Insira o numero de Vitórias %d: ",i+1);
        scanf("%d", &jogador[i].vitorias);}
        while (jogador[i].vitorias<0);
do {     
        printf(" Insira o numero de Derrotas %d: ",i+1);
        scanf("%d", &jogador[i].derrotas);}
 while (jogador[i].vitorias<0);
do {      
        printf(" Insira o numero da Patente %d: ",i+1);
        scanf("%d", &jogador[i].patente);
        getchar();
    }
 while (jogador[i].patente<0||jogador[i].patente>6);
 int pont = pontos(jogador[i].vitorias, jogador[i].derrotas);
 
 jogador[i].pontos = pont;

        printf(" o numero de Pontos do jogador %d: %d\n",i+1, pont);
    }
    imprimeTabela(jogador);
    
   
    printf("Consulta: jogador líder por patente : ");
    scanf("%d", &patescolhida);
    imprimeLider(patescolhida, jogador);

    

    printf("Busca por nome, digite o nome que deseja buscar: ");
    scanf("%s", &nomeEscolhido);
    buscarPorNome(nomeEscolhido, jogador);


    printf("Total de partidas disputadas: %d\n", somapartida(jogador, 6));

    return 0;
}