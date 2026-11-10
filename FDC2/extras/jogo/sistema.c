/**
 * @file sistema.c
 * @brief Controle do fluxo principal do Jogo do Milhao.
 */

#include "sistema.h"
#include "view/pergunta_view.h"
#include "view/view.h"

#include <stdio.h>

void sistema_executar(void)
{
    int opcao_selecionada = MENU_JOGAR;
    int confirmada = 0;
    int alternativa_selecionada = 0;
    int pergunta_respondida = 0;
    int resposta_correta = 0;
    int indice_pergunta = 0;
    int opcao_derrota = DERROTA_REINICIAR;
    TelaAtual tela = TELA_MENU;
    Pergunta primeira_pergunta;

    view_inicializar();

    while (!view_deve_fechar()) {
        if (tela == TELA_PERGUNTA) {
            alternativa_selecionada = pergunta_view_atualizar(
                alternativa_selecionada, pergunta_respondida, &confirmada);

            if (alternativa_selecionada < 0) {
                tela = TELA_MENU;
                alternativa_selecionada = 0;
                pergunta_respondida = 0;
                confirmada = 0;
            } else if (confirmada && !pergunta_respondida) {
                resposta_correta =
                    'A' + alternativa_selecionada ==
                    primeira_pergunta.resposta_correta;
                if (resposta_correta) {
                    indice_pergunta++;
                    alternativa_selecionada = 0;
                    confirmada = 0;
                    if (!perguntas_carregar_indice(&primeira_pergunta,
                                                   indice_pergunta)) {
                        tela = TELA_MENU;
                        indice_pergunta = 0;
                    }
                } else {
                    pergunta_respondida = 1;
                    tela = TELA_PERDEU;
                }
            }
            if (tela == TELA_PERGUNTA) {
                pergunta_view_desenhar(&primeira_pergunta,
                                       alternativa_selecionada,
                                       pergunta_respondida, resposta_correta);
            }
            continue;
        }

        if (tela == TELA_PERDEU) {
            opcao_derrota = pergunta_view_atualizar_perdeu(
                opcao_derrota, &confirmada);
            if (confirmada && opcao_derrota == DERROTA_REINICIAR) {
                if (!perguntas_carregar_primeira(&primeira_pergunta)) {
                    fprintf(stderr, "Nao foi possivel reiniciar a partida.\n");
                    break;
                }
                tela = TELA_PERGUNTA;
                indice_pergunta = 0;
                alternativa_selecionada = 0;
                pergunta_respondida = 0;
                resposta_correta = 0;
                confirmada = 0;
            } else if (confirmada && opcao_derrota == DERROTA_SAIR) {
                break;
            }
            pergunta_view_desenhar_perdeu(opcao_derrota);
            continue;
        }

        opcao_selecionada = view_atualizar_menu(opcao_selecionada, &confirmada);

        if (confirmada) {
            if (opcao_selecionada == MENU_JOGAR) {
                if (perguntas_carregar_primeira(&primeira_pergunta)) {
                    tela = TELA_PERGUNTA;
                    indice_pergunta = 0;
                    alternativa_selecionada = 0;
                    pergunta_respondida = 0;
                    resposta_correta = 0;
                    opcao_derrota = DERROTA_REINICIAR;
                } else {
                    fprintf(stderr, "Nao foi possivel carregar a pergunta.\n");
                }
            } else if (opcao_selecionada == MENU_PERGUNTAS) {
                printf("Opcao selecionada: Perguntas\n");
            } else if (opcao_selecionada == MENU_SAIR) {
                break;
            }
            confirmada = 0;
        }

        view_desenhar_menu(opcao_selecionada);
    }

    view_finalizar();
}
