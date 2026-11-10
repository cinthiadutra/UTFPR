/**
 * @file sistema.h
 * @brief Assinaturas e tipos principais do sistema.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include "perguntas/perguntas.h"

/**
 * Opcoes disponiveis no menu principal.
 */
typedef enum {
    MENU_JOGAR,
    MENU_PERGUNTAS,
    MENU_SAIR,
    MENU_TOTAL
} OpcaoMenu;

typedef enum {
    TELA_MENU,
    TELA_PERGUNTA,
    TELA_PERDEU
} TelaAtual;

/**
 * Executa o fluxo principal do sistema.
 */
void sistema_executar(void);

#endif
