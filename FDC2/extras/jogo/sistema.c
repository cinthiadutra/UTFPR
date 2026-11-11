/**
 * @file sistema.c
 * @brief Controle do fluxo principal do Jogo do Milhao.
 */

#include "sistema.h"
#include "view/perguntaView.h"
#include "view/view.h"
#include "view/gerenciarView.h"

#include <stdio.h>

void sistemaExecutar(void)
{
    int opcaoSelecionada = menuJogar;
    int confirmada = 0;
    int alternativaSelecionada = 0;
    int perguntaRespondida = 0;
    int respostaCorreta = 0;
    int indicePergunta = 0;
    int opcaoDerrota = derrotaReiniciar;
    TelaAtual tela = telaMenu;
    Pergunta primeiraPergunta;

    if (!perguntasInicializar()) {
        fprintf(stderr, "Nao foi possivel carregar as perguntas.\n");
        return;
    }

    viewInicializar();

    while (!viewDeveFechar()) {
        if (tela == telaGerenciar) {
            if (gerenciarView()) tela = telaMenu;
            continue;
        }

        if (tela == telaPergunta) {
            alternativaSelecionada = perguntaViewAtualizar(
                alternativaSelecionada, perguntaRespondida, &confirmada);

            if (alternativaSelecionada < 0) {
                tela = telaMenu;
                alternativaSelecionada = 0;
                perguntaRespondida = 0;
                confirmada = 0;
            } else if (confirmada && !perguntaRespondida) {
                respostaCorreta =
                    'A' + alternativaSelecionada ==
                    primeiraPergunta.respostaCorreta;
                if (respostaCorreta) {
                    indicePergunta++;
                    alternativaSelecionada = 0;
                    confirmada = 0;
                    if (!perguntasCarregarIndice(&primeiraPergunta,
                                                   indicePergunta)) {
                        tela = telaMenu;
                        indicePergunta = 0;
                    }
                } else {
                    perguntaRespondida = 1;
                    tela = telaPerdeu;
                }
            }
            if (tela == telaPergunta) {
                perguntaViewDesenhar(&primeiraPergunta,
                                       alternativaSelecionada,
                                       perguntaRespondida, respostaCorreta);
            }
            continue;
        }

        if (tela == telaPerdeu) {
            opcaoDerrota = perguntaViewAtualizarPerdeu(
                opcaoDerrota, &confirmada);
            if (confirmada && opcaoDerrota == derrotaReiniciar) {
                if (!perguntasCarregarPrimeira(&primeiraPergunta)) {
                    fprintf(stderr, "Nao foi possivel reiniciar a partida.\n");
                    break;
                }
                tela = telaPergunta;
                indicePergunta = 0;
                alternativaSelecionada = 0;
                perguntaRespondida = 0;
                respostaCorreta = 0;
                confirmada = 0;
            } else if (confirmada && opcaoDerrota == derrotaSair) {
                break;
            }
            perguntaViewDesenharPerdeu(opcaoDerrota);
            continue;
        }

        opcaoSelecionada = viewAtualizarMenu(opcaoSelecionada, &confirmada);

        if (confirmada) {
            if (opcaoSelecionada == menuJogar) {
                if (perguntasCarregarPrimeira(&primeiraPergunta)) {
                    tela = telaPergunta;
                    indicePergunta = 0;
                    alternativaSelecionada = 0;
                    perguntaRespondida = 0;
                    respostaCorreta = 0;
                    opcaoDerrota = derrotaReiniciar;
                } else {
                    fprintf(stderr, "Nao foi possivel carregar a pergunta.\n");
                }
            } else if (opcaoSelecionada == menuPerguntas) {
                tela = telaGerenciar;
            } else if (opcaoSelecionada == menuSair) {
                break;
            }
            confirmada = 0;
        }

        viewDesenharMenu(opcaoSelecionada);
    }

    if (!perguntasSalvar()) {
        fprintf(stderr, "Nao foi possivel salvar as perguntas no binario e no CSV.\n");
    }
    perguntasLiberar();
    viewFinalizar();
}
