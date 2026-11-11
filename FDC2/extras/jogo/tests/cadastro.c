#include "perguntas/perguntas.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    Pergunta p, copia;
    assert(perguntasInicializar());
    assert(perguntasQuantidade() == 25);
    /* Simula o binario da versao anterior e verifica recuperacao de metadados. */
    assert(perguntasCarregarPrimeira(&p));
    struct {
        int id;
        dificuldade nivel;
        char enunciado[tamanhoTextoPergunta];
        char alternativas[4][tamanhoAlternativa];
        char respostaCorreta;
    } antiga = {0};
    antiga.id = p.id; antiga.nivel = p.nivel;
    strcpy(antiga.enunciado, p.enunciado);
    memcpy(antiga.alternativas, p.alternativas, sizeof(antiga.alternativas));
    antiga.respostaCorreta = p.respostaCorreta;
    FILE *arquivo = fopen("perguntas/perguntas.bin", "wb");
    assert(arquivo);
    uint32_t quantidade = 1;
    assert(fwrite("JOGOP001", 1, 8, arquivo) == 8);
    assert(fwrite(&quantidade, sizeof(quantidade), 1, arquivo) == 1);
    assert(fwrite(&antiga, sizeof(antiga), 1, arquivo) == 1);
    assert(fclose(arquivo) == 0);
    perguntasLiberar();
    assert(perguntasInicializar());
    assert(perguntasQuantidade() == 1);
    assert(perguntasCarregarPrimeira(&copia));
    assert(strcmp(copia.metadados[0], "Dart") == 0);
    assert(strcmp(copia.enunciado, p.enunciado) == 0);
    perguntasLiberar();
    assert(remove("perguntas/perguntas.bin") == 0);
    assert(perguntasInicializar());
    assert(perguntasPesquisar("FLUTTER", 0, &p) >= 0);
    assert(perguntasPesquisar("13", 0, &p) == 12);
    assert(strcmp(p.metadados[0], "Dart") == 0);
    strcpy(p.enunciado, "Teste, com \"aspas\" e acentuação");
    assert(perguntasInserir(&p));
    assert(perguntasPesquisar("26", 0, &p) == 25);
    p.respostaCorreta = 'D';
    assert(perguntasAlterar(26, &p));
    assert(!perguntasAlterar(999, &p));
    p.respostaCorreta = 'Z';
    assert(!perguntasInserir(&p));
    assert(!perguntasAlterar(26, &p));
    assert(perguntasExcluir(1));
    assert(!perguntasExcluir(1));
    assert(perguntasSalvar());
    perguntasLiberar();
    assert(perguntasInicializar());
    assert(perguntasPesquisar("26", 0, &p) == 24);
    assert(p.respostaCorreta == 'D');
    perguntasLiberar();
    assert(remove("perguntas/perguntas.bin") == 0);
    assert(perguntasInicializar());
    assert(perguntasPesquisar("26", 0, &copia) == 24);
    assert(strcmp(copia.enunciado, p.enunciado) == 0);
    assert(strcmp(copia.metadados[0], p.metadados[0]) == 0);
    assert(copia.respostaCorreta == p.respostaCorreta);
    while (perguntasCarregarPrimeira(&p)) assert(perguntasExcluir(p.id));
    assert(perguntasQuantidade() == 0);
    assert(perguntasSalvar());
    perguntasLiberar();
    assert(perguntasInicializar());
    assert(perguntasQuantidade() == 0);
    perguntasLiberar();
    assert(remove("perguntas/perguntas.bin") == 0);
    assert(perguntasInicializar());
    assert(perguntasQuantidade() == 0);
    assert(perguntasInserir(&copia));
    assert(perguntasSalvar());
    perguntasLiberar();
    puts("OK: cadastro, pesquisa, validacao, exclusao, CSV, binario e lista vazia.");
}
