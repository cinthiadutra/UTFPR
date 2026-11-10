/**
 * @file pergunta_view.c
 * @brief Implementacao da tela de perguntas com Raylib.
 */

#include "pergunta_view.h"
#include "view.h"

#include "raylib.h"

#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 700

int pergunta_view_atualizar(int selecionada, int respondida, int *confirmada)
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

int pergunta_view_atualizar_perdeu(int selecionada, int *confirmada)
{
    *confirmada = 0;

    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) {
        selecionada = (selecionada + 1) % DERROTA_TOTAL;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        *confirmada = 1;
    }

    return selecionada;
}

void pergunta_view_desenhar(const Pergunta *pergunta, int selecionada,
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
    if (view_fundo_disponivel()) {
        view_desenhar_fundo();
    }

    DrawRectangleRounded((Rectangle){100, 75, 900, 550}, 0.04f, 12, painel);
    DrawText(TextFormat("Pergunta %d - %s", pergunta->id, pergunta->dificuldade),
             145, 105, 24, dourado);
    DrawText(pergunta->enunciado, 145, 160, 25, branco);

    for (int i = 0; i < 4; i++) {
        int y = 250 + i * 75;
        Color cor_alternativa = i == selecionada
                                    ? dourado
                                    : (Color){30, 50, 90, 245};
        Color cor_texto = i == selecionada ? fundo : branco;

        if (respondida && 'A' + i == pergunta->resposta_correta) {
            cor_alternativa = verde;
            cor_texto = branco;
        } else if (respondida && i == selecionada && !acertou) {
            cor_alternativa = vermelho;
            cor_texto = branco;
        }

        DrawRectangleRounded((Rectangle){145, y, 810, 52}, 0.12f, 8,
                             cor_alternativa);
        DrawText(TextFormat("%c) %s", 'A' + i, pergunta->alternativas[i]), 165,
                 y + 13, 20, cor_texto);
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

void pergunta_view_desenhar_perdeu(int selecionada)
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

    for (int i = 0; i < DERROTA_TOTAL; i++) {
        int y = 355 + i * 75;
        Color cor_botao = i == selecionada ? destaque : painel;
        Color cor_texto = i == selecionada ? vermelho : branco;

        DrawRectangleRounded((Rectangle){350, y, 400, 55}, 0.15f, 8,
                             cor_botao);
        DrawText(i == DERROTA_REINICIAR ? "REINICIAR" : "SAIR", 475, y + 15,
                 24, cor_texto);
    }

    DrawText("UP/DOWN para escolher | ENTER para confirmar", 315, 590, 18,
             (Color){255, 220, 220, 255});
    EndDrawing();
}
