/**
 * @file perguntaView.h
 * @brief Interface visual da tela de perguntas.
 */

#ifndef perguntaViewH
#define perguntaViewH

#include "../perguntas/perguntas.h"

typedef enum {
    derrotaReiniciar,
    derrotaSair,
    derrotaTotal
} OpcaoDerrota;

int perguntaViewAtualizar(int selecionada, int respondida, int *confirmada);
int perguntaViewAtualizarPerdeu(int selecionada, int *confirmada);
void perguntaViewDesenhar(const Pergunta *pergunta, int selecionada,
                            int respondida, int acertou);
void perguntaViewDesenharPerdeu(int selecionada);

#endif
