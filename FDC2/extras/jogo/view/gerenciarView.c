#include "gerenciarView.h"
#include "../perguntas/perguntas.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>

static char busca[128];
static char mensagem[160];
static int selecionado;
static int editando;
static int inserindo;
static int confirmando;
static int campo;
static Pergunta rascunho;

static void editarTexto(char *texto, size_t capacidade)
{
    int codigo;
    while ((codigo = GetCharPressed()) > 0) {
        if (codigo < 32) continue;
        int bytes;
        const char *utf8 = CodepointToUTF8(codigo, &bytes);
        size_t tamanho = strlen(texto);
        if (tamanho + (size_t)bytes < capacidade) {
            memcpy(texto + tamanho, utf8, (size_t)bytes);
            texto[tamanho + bytes] = '\0';
        }
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        size_t tamanho = strlen(texto);
        if (tamanho) {
            tamanho--;
            while (tamanho && ((unsigned char)texto[tamanho] & 0xc0) == 0x80) tamanho--;
            texto[tamanho] = '\0';
        }
    }
}

static void salvarAlteracao(void)
{
    snprintf(mensagem, sizeof(mensagem), "%s", perguntasSalvar()
        ? "Salvo no binario e no CSV."
        : "Falha ao salvar. Alteracao em memoria; F5 tenta novamente.");
}

int gerenciarView(void)
{
    Pergunta atual = {0};
    int indice = perguntasPesquisar(busca, selecionado, &atual);
    if (indice < 0) indice = perguntasPesquisar(busca, 0, &atual);
    selecionado = indice < 0 ? 0 : indice;
    if (editando) {
        if (IsKeyPressed(KEY_ESCAPE)) { editando = 0; return 0; }
        if (IsKeyPressed(KEY_TAB)) campo = (campo + 1) % 12;
        if (campo < 5) editarTexto(campo == 0 ? rascunho.enunciado : rascunho.alternativas[campo - 1], campo == 0 ? tamanhoTextoPergunta : tamanhoAlternativa);
        else if (campo < 10) editarTexto(rascunho.metadados[campo - 5], 128);
        else if (campo == 10) {
            if (IsKeyPressed(KEY_RIGHT)) rascunho.nivel = (dificuldade)((rascunho.nivel + 1) % 5);
            if (IsKeyPressed(KEY_LEFT)) rascunho.nivel = (dificuldade)((rascunho.nivel + 4) % 5);
        } else {
            if (IsKeyPressed(KEY_RIGHT)) rascunho.respostaCorreta = (char)('A' + (rascunho.respostaCorreta - 'A' + 1) % 4);
            if (IsKeyPressed(KEY_LEFT)) rascunho.respostaCorreta = (char)('A' + (rascunho.respostaCorreta - 'A' + 3) % 4);
        }
        if (IsKeyPressed(KEY_F2)) {
            int sucesso = inserindo ? perguntasInserir(&rascunho) : perguntasAlterar(rascunho.id, &rascunho);
            if (sucesso) { editando = 0; salvarAlteracao(); }
            else snprintf(mensagem, sizeof(mensagem), "Preencha o enunciado e as quatro alternativas.");
        }
    } else if (confirmando) {
        if (IsKeyPressed(KEY_ESCAPE)) confirmando = 0;
        if (IsKeyPressed(KEY_ENTER)) {
            if (indice >= 0 && perguntasExcluir(atual.id)) salvarAlteracao();
            confirmando = 0;
        }
    } else {
        if (IsKeyPressed(KEY_ESCAPE)) return 1;
        editarTexto(busca, sizeof(busca));
        if (IsKeyPressed(KEY_DOWN) && indice >= 0) {
            int proximo = perguntasPesquisar(busca, indice + 1, &atual);
            if (proximo >= 0) selecionado = proximo;
        }
        if (IsKeyPressed(KEY_UP)) {
            int anterior = -1;
            for (int i = 0; i < selecionado;) {
                int achado = perguntasPesquisar(busca, i, &atual);
                if (achado < 0 || achado >= selecionado) break;
                anterior = achado;
                i = achado + 1;
            }
            if (anterior >= 0) selecionado = anterior;
        }
        if ((IsKeyPressed(KEY_INSERT) || IsKeyPressed(KEY_F1))) {
            rascunho = (Pergunta){0}; rascunho.respostaCorreta = 'A';
            editando = inserindo = 1; campo = 0; mensagem[0] = '\0';
        }
        if (IsKeyPressed(KEY_F2) && perguntasCarregarIndice(&atual, selecionado) && indice >= 0) {
            rascunho = atual; editando = 1; inserindo = 0; campo = 0; mensagem[0] = '\0';
        }
        if (IsKeyPressed(KEY_DELETE) && indice >= 0) confirmando = 1;
        if (IsKeyPressed(KEY_F5)) salvarAlteracao();
    }

    BeginDrawing();
    ClearBackground((Color){12, 20, 45, 255});
    DrawText(editando ? "Editar pergunta" : "Gerenciar perguntas", 30, 20, 30, GOLD);
    if (editando) {
        const char *rotulos[] = {"Enunciado", "A", "B", "C", "D", "Tema", "Rodada inicial", "Rodada final", "Marco seguranca", "Rodada milhao", "Dificuldade", "Resposta"};
        for (int i = 0; i < 12; i++) {
            int y = 75 + i * 43;
            const char *texto = i == 0 ? rascunho.enunciado : i < 5 ? rascunho.alternativas[i - 1] : i < 10 ? rascunho.metadados[i - 5] : i == 10 ? perguntasNomeNivel(rascunho.nivel) : TextFormat("%c", rascunho.respostaCorreta);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), (Rectangle){20, y - 4, 1060, 38})) campo = i;
            DrawRectangle(195, y - 4, 875, 34, i == campo ? (Color){50, 65, 95, 255} : (Color){25, 35, 55, 255});
            DrawText(rotulos[i], 30, y, 18, i == campo ? GOLD : WHITE);
            BeginScissorMode(200, y, 865, 28);
            int largura = MeasureText(texto, 18);
            DrawText(texto, i == campo && largura > 855 ? 1060 - largura : 205, y, 18, WHITE);
            EndScissorMode();
        }
        DrawText("TAB ou clique: campo | Setas: dificuldade/resposta | F2: salvar | ESC: cancelar", 30, 610, 18, LIGHTGRAY);
    } else {
        DrawText(TextFormat("Pesquisar por ID, enunciado ou tema: %s", busca), 30, 70, 20, WHITE);
        DrawText(TextFormat("%d perguntas | Digite para filtrar; BACKSPACE apaga", perguntasQuantidade()), 30, 105, 18, LIGHTGRAY);
        int linha = 0;
        for (int i = selecionado; linha < 9;) {
            Pergunta p;
            int achado = perguntasPesquisar(busca, i, &p);
            if (achado < 0) break;
            int y = 155 + linha * 44;
            if (linha == 0) DrawRectangle(20, y - 5, 1060, 36, (Color){50, 65, 95, 255});
            BeginScissorMode(30, y, 1030, 30);
            DrawText(TextFormat("%d | %s", p.id, p.enunciado), 30, y, 19, linha == 0 ? GOLD : WHITE);
            EndScissorMode();
            linha++; i = achado + 1;
        }
        if (!linha) DrawText("Nenhuma pergunta encontrada.", 30, 160, 22, WHITE);
        DrawText("Setas: selecionar | F1: inserir | F2: alterar | DELETE: excluir", 30, 575, 19, LIGHTGRAY);
        DrawText("ESC: voltar | F5: salvar novamente", 30, 605, 19, LIGHTGRAY);
        if (confirmando) {
            DrawRectangle(80, 260, 940, 120, MAROON);
            DrawText("Excluir a pergunta selecionada?", 110, 280, 26, WHITE);
            DrawText("ENTER confirma | ESC cancela", 110, 330, 22, WHITE);
        }
    }
    DrawText(mensagem, 30, 655, 18, GOLD);
    EndDrawing();
    return 0;
}
