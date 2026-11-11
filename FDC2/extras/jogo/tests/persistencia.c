#include "perguntas/perguntas.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Executar em uma pasta temporaria com uma copia do CSV em perguntas/. */
int main(void)
{
    Pergunta originais[25];
    Pergunta atual;
    assert(perguntasInicializar());
    for (int i = 0; i < 25; i++) assert(perguntasCarregarIndice(&originais[i], i));
    assert(!perguntasCarregarIndice(&atual, 25));
    assert(!perguntasCarregarIndice(&atual, -1));
    assert(!perguntasCarregarPrimeira(NULL));
    assert(originais[0].nivel == muitoFacil);
    assert(originais[24].nivel == muitoDificil);
    assert(strcmp(originais[12].alternativas[0], "[1, 3]") == 0);
    assert(strcmp(originais[20].alternativas[3], "S, M, F") == 0);
    assert(perguntasSalvar());
    perguntasLiberar();
    assert(remove("perguntas/perguntas.csv") == 0);
    assert(perguntasInicializar());
    for (int i = 0; i < 25; i++) {
        assert(perguntasCarregarIndice(&atual, i));
        assert(memcmp(&originais[i], &atual, sizeof(atual)) == 0);
    }
    assert(perguntasSalvar());
    perguntasLiberar();
    FILE *arquivo = fopen("perguntas/perguntas.bin", "wb");
    assert(arquivo);
    fputs("invalido", arquivo);
    assert(fclose(arquivo) == 0);
    assert(!perguntasInicializar());
    assert(!perguntasSalvar());
    puts("OK: CSV, 25 perguntas, campos com virgulas, binario sem CSV e arquivo invalido.");
    return 0;
}
