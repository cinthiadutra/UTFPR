/**
 * @file pergunta_view.h
 * @brief Interface visual da tela de perguntas.
 */

#ifndef PERGUNTA_VIEW_H
#define PERGUNTA_VIEW_H

#include "../perguntas/perguntas.h"

typedef enum {
    DERROTA_REINICIAR,
    DERROTA_SAIR,
    DERROTA_TOTAL
} OpcaoDerrota;

int pergunta_view_atualizar(int selecionada, int respondida, int *confirmada);
int pergunta_view_atualizar_perdeu(int selecionada, int *confirmada);
void pergunta_view_desenhar(const Pergunta *pergunta, int selecionada,
                            int respondida, int acertou);
void pergunta_view_desenhar_perdeu(int selecionada);

#endif
