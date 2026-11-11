/**
 * @file perguntas.h
 * @brief Carregamento e persistencia das perguntas.
 */

#ifndef perguntasH
#define perguntasH

#define tamanhoTextoPergunta 512
#define tamanhoAlternativa 256
typedef enum {muitoFacil, FACIL, MEDIO, DIFICIL, muitoDificil}dificuldade;

typedef struct {
    int id;
    dificuldade nivel;
    char enunciado[tamanhoTextoPergunta];
    char alternativas[4][tamanhoAlternativa];
    char respostaCorreta;
    /* tema, rodada inicial/final, marco de seguranca e rodada do milhao. */
    char metadados[5][128];
} Pergunta;

/**
 * Copia a primeira pergunta carregada em memoria.
 *
 * @param pergunta estrutura que recebera os dados.
 * @return 1 se a pergunta foi carregada, 0 em caso de erro.
 */
/* Inicializa pelo binario existente ou importa o CSV na primeira execucao. */
int perguntasInicializar(void);
/* Salva todas as perguntas no binario e no CSV. */
int perguntasSalvar(void);
void perguntasLiberar(void);
const char *perguntasNomeNivel(dificuldade nivel);

int perguntasCarregarPrimeira(Pergunta *pergunta);

/**
 * Carrega uma pergunta pelo indice da linha de dados, iniciando em zero.
 */
int perguntasCarregarIndice(Pergunta *pergunta, int indice);

/* Consultas retornam copias; alteracoes ficam em memoria ate perguntasSalvar. */
int perguntasQuantidade(void);
int perguntasPesquisar(const char *termo, int inicio, Pergunta *pergunta);
int perguntasInserir(const Pergunta *pergunta);
int perguntasAlterar(int id, const Pergunta *pergunta);
int perguntasExcluir(int id);

#endif
