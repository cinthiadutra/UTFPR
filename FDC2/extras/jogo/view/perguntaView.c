/**
 * @file perguntaView.c
 * @brief Implementacao da tela de perguntas com Raylib.
 */

#include "perguntaView.h"
#include "view.h"

#include "raylib.h"

#define windowWidth 1100
#define windowHeight 700

int perguntaViewAtualizar(int selecionada, int respondida, int *confirmada)
{
    *confirmada = 0;

    if (IsKeyPressed(KEY_ESCAPE)) {
        return -1;
    }

    if (respondida) {
        if (IsKeyPressed(KEY_ENTER)) {
            return -1;
        }
        return selecionada;
    }

    if (IsKeyPressed(KEY_DOWN)) {
        selecionada = (selecionada + 1) % 4;
    }
    if (IsKeyPressed(KEY_UP)) {
        selecionada = (selecionada + 3) % 4;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        *confirmada = 1;
    }

    return selecionada;
}

int perguntaViewAtualizarPerdeu(int selecionada, int *confirmada)
{
    *confirmada = 0;

    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) {
        selecionada = (selecionada + 1) % derrotaTotal;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        *confirmada = 1;
    }

    return selecionada;
}

void perguntaViewDesenhar(const Pergunta *pergunta, int selecionada,
                            int respondida, int acertou)
{
    const Color fundo = (Color){12, 20, 45, 255};
    const Color painel = (Color){12, 25, 55, 235};
    const Color dourado = (Color){244, 194, 56, 255};
    const Color branco = (Color){245, 247, 255, 255};
    const Color vermelho = (Color){210, 70, 75, 255};
    const Color verde = (Color){55, 190, 110, 255};

    BeginDrawing();
    ClearBackground(fundo);
    if (viewFundoDisponivel()) {
        viewDesenharFundo();
    }

    DrawRectangleRounded((Rectangle){100, 75, 900, 550}, 0.04f, 12, painel);
    DrawText(TextFormat("Pergunta %d - %s", pergunta->id, perguntasNomeNivel(pergunta->nivel)),
             145, 105, 24, dourado);
    DrawText(pergunta->enunciado, 145, 160, 25, branco);

    for (int i = 0; i < 4; i++) {
        int y = 250 + i * 75;
        Color corAlternativa = i == selecionada
                                    ? dourado
                                    : (Color){30, 50, 90, 245};
        Color corTexto = i == selecionada ? fundo : branco;

        if (respondida && 'A' + i == pergunta->respostaCorreta) {
            corAlternativa = verde;
            corTexto = branco;
        } else if (respondida && i == selecionada && !acertou) {
            corAlternativa = vermelho;
            corTexto = branco;
        }

        DrawRectangleRounded((Rectangle){145, y, 810, 52}, 0.12f, 8,
                             corAlternativa);
        DrawText(TextFormat("%c) %s", 'A' + i, pergunta->alternativas[i]), 165,
                 y + 13, 20, corTexto);
    }

    if (respondida) {
        DrawText(acertou ? "Resposta correta!" : "Resposta incorreta!", 145,
                 585, 20, acertou ? verde : vermelho);
        DrawText("ENTER ou ESC para voltar ao menu", 520, 585, 18,
                 (Color){166, 180, 214, 255});
    } else {
        DrawText("UP/DOWN para escolher | ENTER para responder | ESC para voltar",
                 145, 585, 18, (Color){166, 180, 214, 255});
    }
    EndDrawing();
}

void perguntaViewDesenharPerdeu(int selecionada)
{
    const Color vermelho = (Color){150, 18, 30, 255};
    const Color destaque = (Color){244, 194, 56, 255};
    const Color painel = (Color){95, 10, 25, 220};
    const Color branco = (Color){255, 245, 245, 255};

    BeginDrawing();
    ClearBackground(vermelho);
    DrawText("VOCE PERDEU!", 350, 155, 60, branco);
    DrawText("A resposta selecionada estava incorreta.", 290, 245, 24,
             (Color){255, 220, 220, 255});

    for (int i = 0; i < derrotaTotal; i++) {
        int y = 355 + i * 75;
        Color corBotao = i == selecionada ? destaque : painel;
        Color corTexto = i == selecionada ? vermelho : branco;

        DrawRectangleRounded((Rectangle){350, y, 400, 55}, 0.15f, 8,
                             corBotao);
        DrawText(i == derrotaReiniciar ? "REINICIAR" : "SAIR", 475, y + 15,
                 24, corTexto);
    }

    DrawText("UP/DOWN para escolher | ENTER para confirmar", 315, 590, 18,
             (Color){255, 220, 220, 255});
    EndDrawing();
}
