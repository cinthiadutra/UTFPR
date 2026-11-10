/**
 * @file view.c
 * @brief Implementacao da interface visual com Raylib.
 */

#include "view.h"
#include "../sistema.h"

#include "raylib.h"

#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 700

static Texture2D imagem_fundo;

static const char *menu_items[MENU_TOTAL] = {
    "Jogar",
    "Perguntas",
    "Sair"
};

static Texture2D carregar_imagem_fundo(void)
{
    const char *caminhos[] = {
        "assets/bk.png",
        "jogo/assets/bk.png",
        "FDC2/extras/jogo/assets/bk.png",
        "extras/jogo/assets/bk.png"
    };

    for (unsigned int i = 0; i < sizeof(caminhos) / sizeof(caminhos[0]); i++) {
        if (FileExists(caminhos[i])) {
            TraceLog(LOG_INFO, "Carregando fundo: %s", caminhos[i]);
            return LoadTexture(caminhos[i]);
        }
    }

    TraceLog(LOG_ERROR, "Fundo nao encontrado. Caminho esperado: assets/bk.png");
    return (Texture2D){0};
}

static void desenhar_texto_centralizado(const char *texto, int y, int tamanho,
                                        Color cor)
{
    int largura_texto = MeasureText(texto, tamanho);
    DrawText(texto, (WINDOW_WIDTH - largura_texto) / 2, y, tamanho, cor);
}

void view_desenhar_fundo(void)
{
    Rectangle origem = {0, 0, (float)imagem_fundo.width,
                        (float)imagem_fundo.height};
    Rectangle destino = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    DrawTexturePro(imagem_fundo, origem, destino, (Vector2){0, 0}, 0.0f,
                   WHITE);
    DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, (Color){5, 12, 35, 155});
}

void view_inicializar(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Jogo do Milhao");
    SetTargetFPS(60);
    imagem_fundo = carregar_imagem_fundo();
}

int view_deve_fechar(void)
{
    return WindowShouldClose();
}

int view_atualizar_menu(int selecionada, int *confirmada)
{
    if (IsKeyPressed(KEY_DOWN)) {
        selecionada = (selecionada + 1) % MENU_TOTAL;
    }
    if (IsKeyPressed(KEY_UP)) {
        selecionada = (selecionada + MENU_TOTAL - 1) % MENU_TOTAL;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        *confirmada = 1;
    }

    return selecionada;
}

void view_desenhar_menu(int selecionada)
{
    const Color fundo = (Color){12, 20, 45, 255};
    const Color painel = (Color){22, 35, 75, 255};
    const Color dourado = (Color){244, 194, 56, 255};
    const Color branco = (Color){245, 247, 255, 255};
    const Color apagado = (Color){166, 180, 214, 255};

    BeginDrawing();
    ClearBackground(fundo);

    if (view_fundo_disponivel()) {
        view_desenhar_fundo();
    }

    DrawCircle(WINDOW_WIDTH / 2, 155, 92, (Color){30, 55, 110, 210});
    DrawCircleLines(WINDOW_WIDTH / 2, 155, 92, dourado);
    desenhar_texto_centralizado("JOGO DO MILHAO", 95, 48, dourado);
    desenhar_texto_centralizado("Fundamentos de Programacao 2", 215, 20,
                                apagado);

    DrawRectangleRounded((Rectangle){345, 275, 410, 275}, 0.08f, 12, painel);

    for (int i = 0; i < MENU_TOTAL; i++) {
        int y = 305 + i * 75;

        if (i == selecionada) {
            DrawRectangleRounded((Rectangle){380, y - 10, 340, 55}, 0.2f, 8,
                                 dourado);
            desenhar_texto_centralizado(menu_items[i], y, 28, fundo);
        } else {
            desenhar_texto_centralizado(menu_items[i], y, 28, branco);
        }
    }

    desenhar_texto_centralizado("Use as setas e ENTER para selecionar", 610, 18,
                                apagado);
    EndDrawing();
}

int view_fundo_disponivel(void)
{
    return IsTextureValid(imagem_fundo);
}

void view_finalizar(void)
{
    if (IsTextureValid(imagem_fundo)) {
        UnloadTexture(imagem_fundo);
    }
    CloseWindow();
}
