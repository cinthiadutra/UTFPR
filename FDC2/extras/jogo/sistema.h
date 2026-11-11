/**
 * @file sistema.h
 * @brief Assinaturas e tipos principais do sistema.
 */

#ifndef sistemaH
#define sistemaH

#include "perguntas/perguntas.h"

/**
 * Opcoes disponiveis no menu principal.
 */
typedef enum {
    menuJogar,
    menuPerguntas,
    menuSair,
    menuTotal
} OpcaoMenu;

typedef enum {
    telaMenu,
    telaPergunta,
    telaGerenciar,
    telaPerdeu
} TelaAtual;

/**
 * Executa o fluxo principal do sistema.
 */
void sistemaExecutar(void);

#endif
