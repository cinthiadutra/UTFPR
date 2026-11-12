#ifndef PLAYERS_H
#define PLAYERS_H

typedef struct
{
    char pais[20];
    char nickname[20];
    int vitorias;
    int derrotas;

} Jogador;

void somaPorPais(Jogador jog[], int quantidade);
void imprimirRelatorio(
    const char *paises[],
    int vitorias[],
    int derrotas[]
);

#endif