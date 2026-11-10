/**
 * @file perguntas.h
 * @brief Leitura das perguntas do arquivo CSV.
 */

#ifndef PERGUNTAS_H
#define PERGUNTAS_H

#define TAMANHO_TEXTO_PERGUNTA 512
#define TAMANHO_ALTERNATIVA 256

typedef struct {
    int id;
    char dificuldade[32];
    char enunciado[TAMANHO_TEXTO_PERGUNTA];
    char alternativas[4][TAMANHO_ALTERNATIVA];
    char resposta_correta;
} Pergunta;

/**
 * Carrega a primeira pergunta disponivel no CSV.
 *
 * @param pergunta estrutura que recebera os dados.
 * @return 1 se a pergunta foi carregada, 0 em caso de erro.
 */
int perguntas_carregar_primeira(Pergunta *pergunta);

/**
 * Carrega uma pergunta pelo indice da linha de dados, iniciando em zero.
 */
int perguntas_carregar_indice(Pergunta *pergunta, int indice);

#endif
