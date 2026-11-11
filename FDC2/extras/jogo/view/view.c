/**
 * @file view.c
 * @brief Implementacao da interface visual com Raylib.
 */

#include "view.h"
#include "../sistema.h"

#include "raylib.h"

#define windowWidth 1100
#define windowHeight 700

static Texture2D imagemFundo;

static const char *menuItems[menuTotal] = {
    "Jogar",
    "Perguntas",
    "Sair"
};

static Texture2D carregarImagemFundo(void)
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

static void desenharTextoCentralizado(const char *texto, int y, int tamanho,
                                        Color cor)
{
    int larguraTexto = MeasureText(texto, tamanho);
    DrawText(texto, (windowWidth - larguraTexto) / 2, y, tamanho, cor);
}

void viewDesenharFundo(void)
{
    Rectangle origem = {0, 0, (float)imagemFundo.width,
                        (float)imagemFundo.height};
    Rectangle destino = {0, 0, windowWidth, windowHeight};

    DrawTexturePro(imagemFundo, origem, destino, (Vector2){0, 0}, 0.0f,
                   WHITE);
    DrawRectangle(0, 0, windowWidth, windowHeight, (Color){5, 12, 35, 155});
}

void viewInicializar(void)
{
    InitWindow(windowWidth, windowHeight, "Jogo do Milhao");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    imagemFundo = carregarImagemFundo();
}

int viewDeveFechar(void)
{
    return WindowShouldClose();
}

int viewAtualizarMenu(int selecionada, int *confirmada)
{
    if (IsKeyPressed(KEY_DOWN)) {
        selecionada = (selecionada + 1) % menuTotal;
    }
    if (IsKeyPressed(KEY_UP)) {
        selecionada = (selecionada + menuTotal - 1) % menuTotal;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        *confirmada = 1;
    }

    return selecionada;
}

void viewDesenharMenu(int selecionada)
{
    const Color fundo = (Color){12, 20, 45, 255};
    const Color painel = (Color){22, 35, 75, 255};
    const Color dourado = (Color){244, 194, 56, 255};
    const Color branco = (Color){245, 247, 255, 255};
    const Color apagado = (Color){166, 180, 214, 255};

    BeginDrawing();
    ClearBackground(fundo);

    if (viewFundoDisponivel()) {
        viewDesenharFundo();
    }

    DrawCircle(windowWidth / 2, 155, 92, (Color){30, 55, 110, 210});
    DrawCircleLines(windowWidth / 2, 155, 92, dourado);
    desenharTextoCentralizado("JOGO DO MILHAO", 95, 48, dourado);
    desenharTextoCentralizado("Fundamentos de Programacao 2", 215, 20,
                                apagado);

    DrawRectangleRounded((Rectangle){345, 275, 410, 275}, 0.08f, 12, painel);

    for (int i = 0; i < menuTotal; i++) {
        int y = 305 + i * 75;

        if (i == selecionada) {
            DrawRectangleRounded((Rectangle){380, y - 10, 340, 55}, 0.2f, 8,
                                 dourado);
            desenharTextoCentralizado(menuItems[i], y, 28, fundo);
        } else {
            desenharTextoCentralizado(menuItems[i], y, 28, branco);
        }
    }

    desenharTextoCentralizado("Use as setas e ENTER para selecionar", 610, 18,
                                apagado);
    EndDrawing();
}

int viewFundoDisponivel(void)
{
    return IsTextureValid(imagemFundo);
}

void viewFinalizar(void)
{
    if (IsTextureValid(imagemFundo)) {
        UnloadTexture(imagemFundo);
    }
    CloseWindow();
}
