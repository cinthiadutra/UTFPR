/**
 * @file perguntas.c
 * @brief Carregamento e persistencia das perguntas.
 */
#include "perguntas.h"

#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Pergunta *listaPerguntas;
static uint32_t quantidadePerguntas;
static char caminhoBinario[256];
static char caminhoCsv[256];
static int inicializado;
static const char *nomesNivel[] = {
    "Muito fácil", "Fácil", "Médio", "Difícil", "Muito difícil"
};

const char *perguntasNomeNivel(dificuldade nivel)
{
    return nivel >= muitoFacil && nivel <= muitoDificil
               ? nomesNivel[nivel] : "Desconhecida";
}

void perguntasLiberar(void)
{
    free(listaPerguntas);
    listaPerguntas = NULL;
    quantidadePerguntas = 0;
    inicializado = 0;
}

/* Aceita campos entre aspas, virgulas internas e aspas duplicadas. */
static int separarCampos(char *linha, char *campos[], int limite)
{
    char *leitura = linha;
    char *escrita = linha;
    int quantidade = 0;
    for (;;) {
        if (quantidade == limite) return 0;
        campos[quantidade++] = escrita;
        if (*leitura == '"') {
            leitura++;
            for (;;) {
                if (*leitura == '\0') return 0;
                if (*leitura == '"') {
                    leitura++;
                    if (*leitura != '"') break;
                }
                *escrita++ = *leitura++;
            }
        } else {
            while (*leitura && *leitura != ',' && *leitura != '\r' && *leitura != '\n') {
                *escrita++ = *leitura++;
            }
        }
        char separador = *leitura;
        if (separador != ',' && separador != '\r' && separador != '\n' && separador != '\0') return 0;
        if (separador) leitura++;
        *escrita++ = '\0';
        if (separador != ',') break;
    }
    return quantidade;
}

static int carregarCsv(FILE *arquivo)
{
    char linha[8192];
    if (!fgets(linha, sizeof(linha), arquivo)) return 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char *campos[13];
        Pergunta pergunta = {0};
        if (separarCampos(linha, campos, 13) != 13) return 0;
        pergunta.id = atoi(campos[0]);
        int nivel;
        for (nivel = 0; nivel < 5; nivel++) {
            if (strcmp(campos[1], nomesNivel[nivel]) == 0) break;
        }
        if (nivel == 5 || strlen(campos[7]) >= sizeof(pergunta.enunciado)) return 0;
        pergunta.nivel = (dificuldade)nivel;
        for (int j = 0; j < 5; j++) {
            if (strlen(campos[2 + j]) >= sizeof(pergunta.metadados[j])) return 0;
            strcpy(pergunta.metadados[j], campos[2 + j]);
        }
        strcpy(pergunta.enunciado, campos[7]);
        for (int i = 0; i < 4; i++) {
            if (strlen(campos[8 + i]) >= sizeof(pergunta.alternativas[i])) return 0;
            strcpy(pergunta.alternativas[i], campos[8 + i]);
        }
        if (strlen(campos[12]) != 1 || campos[12][0] < 'A' || campos[12][0] > 'D') return 0;
        pergunta.respostaCorreta = campos[12][0];
        Pergunta *novaLista = realloc(listaPerguntas, (quantidadePerguntas + 1) * sizeof(Pergunta));
        if (!novaLista) return 0;
        listaPerguntas = novaLista;
        listaPerguntas[quantidadePerguntas++] = pergunta;
    }
    return !ferror(arquivo);
}

static int carregarBinario(FILE *arquivo)
{
    char assinatura[8];
    uint32_t quantidade;
    if (fread(assinatura, 1, 8, arquivo) != 8 || (memcmp(assinatura, "JOGOP001", 8) != 0 && memcmp(assinatura, "JOGOP002", 8) != 0) ||
        fread(&quantidade, sizeof(quantidade), 1, arquivo) != 1 || quantidade > 100000) return 0;
    listaPerguntas = calloc(quantidade ? quantidade : 1, sizeof(Pergunta));
    if (!listaPerguntas) return 0;
    for (uint32_t i = 0; i < quantidade; i++) {
        if (assinatura[7] == '1') {
            typedef struct {
                int id;
                dificuldade nivel;
                char enunciado[tamanhoTextoPergunta];
                char alternativas[4][tamanhoAlternativa];
                char respostaCorreta;
            } PerguntaAntiga;
            PerguntaAntiga antiga;
            if (fread(&antiga, sizeof(antiga), 1, arquivo) != 1) return 0;
            listaPerguntas[i].id = antiga.id;
            listaPerguntas[i].nivel = antiga.nivel;
            memcpy(listaPerguntas[i].enunciado, antiga.enunciado, sizeof(antiga.enunciado));
            memcpy(listaPerguntas[i].alternativas, antiga.alternativas, sizeof(antiga.alternativas));
            listaPerguntas[i].respostaCorreta = antiga.respostaCorreta;
        } else if (fread(&listaPerguntas[i], sizeof(Pergunta), 1, arquivo) != 1) return 0;
    }
    for (uint32_t i = 0; i < quantidade; i++) {
        Pergunta *pergunta = &listaPerguntas[i];
        if (pergunta->nivel < muitoFacil || pergunta->nivel > muitoDificil ||
            pergunta->respostaCorreta < 'A' || pergunta->respostaCorreta > 'D' ||
            !memchr(pergunta->enunciado, '\0', sizeof(pergunta->enunciado))) return 0;
        for (int j = 0; j < 5; j++) {
            if (!memchr(pergunta->metadados[j], '\0', sizeof(pergunta->metadados[j]))) return 0;
        }
        for (int j = 0; j < 4; j++) {
            if (!memchr(pergunta->alternativas[j], '\0', sizeof(pergunta->alternativas[j]))) return 0;
        }
    }
    if (fgetc(arquivo) != EOF || ferror(arquivo)) return 0;
    quantidadePerguntas = quantidade;
    if (assinatura[7] == '1') {
        /* Recupera colunas que o formato antigo nao armazenava. */
        FILE *csv = fopen(caminhoCsv, "r");
        if (csv) {
            Pergunta *antigas = listaPerguntas;
            listaPerguntas = NULL;
            quantidadePerguntas = 0;
            if (carregarCsv(csv)) {
                for (uint32_t i = 0; i < quantidade; i++) {
                    for (uint32_t j = 0; j < quantidadePerguntas; j++) {
                        if (antigas[i].id == listaPerguntas[j].id)
                            memcpy(antigas[i].metadados, listaPerguntas[j].metadados, sizeof(antigas[i].metadados));
                    }
                }
            }
            fclose(csv);
            free(listaPerguntas);
            listaPerguntas = antigas;
            quantidadePerguntas = quantidade;
        }
    }
    return 1;
}

int perguntasInicializar(void)
{
    const char *pastas[] = {"perguntas", "jogo/perguntas", "FDC2/extras/jogo/perguntas", "extras/jogo/perguntas"};
    if (inicializado) return 1;
    /* Procura o binario antes de considerar qualquer CSV. */
    for (int binario = 1; binario >= 0; binario--) {
        for (unsigned int i = 0; i < sizeof(pastas) / sizeof(pastas[0]); i++) {
            char caminho[256];
            snprintf(caminho, sizeof(caminho), "%s/perguntas.%s", pastas[i], binario ? "bin" : "csv");
            FILE *arquivo = fopen(caminho, binario ? "rb" : "r");
            if (!arquivo) {
                if (errno == ENOENT) continue;
                perror(caminho);
                return 0;
            }
            snprintf(caminhoCsv, sizeof(caminhoCsv), "%s/perguntas.csv", pastas[i]);
            int sucesso = binario ? carregarBinario(arquivo) : carregarCsv(arquivo);
            fclose(arquivo);
            if (!sucesso) {
                fprintf(stderr, "Arquivo de perguntas invalido: %s\n", caminho);
                perguntasLiberar();
                return 0;
            }
            snprintf(caminhoBinario, sizeof(caminhoBinario), "%s/perguntas.bin", pastas[i]);
            inicializado = 1;
            return 1;
        }
    }
    return 0;
}

static void escreverCampo(FILE *arquivo, const char *texto)
{
    fputc('"', arquivo);
    for (; *texto; texto++) {
        if (*texto == '"') fputc('"', arquivo);
        fputc(*texto, arquivo);
    }
    fputc('"', arquivo);
}

int perguntasSalvar(void)
{
    if (!inicializado) return 0;
    char temporarioBinario[272], temporarioCsv[272];
    snprintf(temporarioBinario, sizeof(temporarioBinario), "%s.tmp", caminhoBinario);
    snprintf(temporarioCsv, sizeof(temporarioCsv), "%s.tmp", caminhoCsv);
    FILE *binario = fopen(temporarioBinario, "wb");
    if (!binario) return 0;
    int sucesso = fwrite("JOGOP002", 1, 8, binario) == 8 &&
        fwrite(&quantidadePerguntas, sizeof(quantidadePerguntas), 1, binario) == 1;
    if (quantidadePerguntas && fwrite(listaPerguntas, sizeof(Pergunta), quantidadePerguntas, binario) != quantidadePerguntas) sucesso = 0;
    if (fclose(binario) != 0) sucesso = 0;
    FILE *csv = fopen(temporarioCsv, "w");
    if (!csv) { remove(temporarioBinario); return 0; }
    fputs("id,dificuldade,tema,rodada_inicial,rodada_final,marco_seguranca,rodada_do_milhao,pergunta,alternativa_a,alternativa_b,alternativa_c,alternativa_d,resposta_correta\n", csv);
    for (uint32_t i = 0; i < quantidadePerguntas; i++) {
        Pergunta *p = &listaPerguntas[i];
        fprintf(csv, "%d,", p->id);
        escreverCampo(csv, perguntasNomeNivel(p->nivel));
        for (int j = 0; j < 5; j++) { fputc(',', csv); escreverCampo(csv, p->metadados[j]); }
        fputc(',', csv); escreverCampo(csv, p->enunciado);
        for (int j = 0; j < 4; j++) { fputc(',', csv); escreverCampo(csv, p->alternativas[j]); }
        fprintf(csv, ",%c\n", p->respostaCorreta);
    }
    if (ferror(csv)) sucesso = 0;
    if (fclose(csv) != 0) sucesso = 0;
    /* Ambos os temporarios ficam completos antes de substituir os originais. */
    if (sucesso && rename(temporarioBinario, caminhoBinario) == 0 && rename(temporarioCsv, caminhoCsv) == 0) return 1;
    remove(temporarioBinario);
    remove(temporarioCsv);
    return 0;
}

int perguntasCarregarIndice(Pergunta *pergunta, int indice)
{
    if (!pergunta || indice < 0 || (uint32_t)indice >= quantidadePerguntas) return 0;
    *pergunta = listaPerguntas[indice];
    return 1;
}

int perguntasCarregarPrimeira(Pergunta *pergunta)
{
    return perguntasCarregarIndice(pergunta, 0);
}


int perguntasQuantidade(void) { return (int)quantidadePerguntas; }

static int textoValido(const char *texto, size_t tamanho, int obrigatorio)
{
    if (!memchr(texto, '\0', tamanho) || strpbrk(texto, "\r\n")) return 0;
    if (!obrigatorio) return 1;
    for (; *texto; texto++) if (!isspace((unsigned char)*texto)) return 1;
    return 0;
}

static int perguntaValida(const Pergunta *p)
{
    if (!p || p->nivel < muitoFacil || p->nivel > muitoDificil || p->respostaCorreta < 'A' || p->respostaCorreta > 'D' ||
        !textoValido(p->enunciado, sizeof(p->enunciado), 1)) return 0;
    for (int j = 0; j < 4; j++) if (!textoValido(p->alternativas[j], sizeof(p->alternativas[j]), 1)) return 0;
    for (int j = 0; j < 5; j++) if (!textoValido(p->metadados[j], sizeof(p->metadados[j]), 0)) return 0;
    return 1;
}

static int indicePorId(int id)
{
    for (uint32_t i = 0; i < quantidadePerguntas; i++) if (listaPerguntas[i].id == id) return (int)i;
    return -1;
}

int perguntasInserir(const Pergunta *pergunta)
{
    if (!inicializado || !perguntaValida(pergunta) || quantidadePerguntas >= 100000) return 0;
    int maiorId = 0;
    for (uint32_t i = 0; i < quantidadePerguntas; i++) if (listaPerguntas[i].id > maiorId) maiorId = listaPerguntas[i].id;
    if (maiorId == INT_MAX) return 0;
    Pergunta *novaLista = realloc(listaPerguntas, (quantidadePerguntas + 1) * sizeof(Pergunta));
    if (!novaLista) return 0;
    listaPerguntas = novaLista;
    listaPerguntas[quantidadePerguntas] = *pergunta;
    listaPerguntas[quantidadePerguntas++].id = maiorId + 1;
    return 1;
}

int perguntasAlterar(int id, const Pergunta *pergunta)
{
    int indice = indicePorId(id);
    if (indice < 0 || !perguntaValida(pergunta)) return 0;
    listaPerguntas[indice] = *pergunta;
    listaPerguntas[indice].id = id;
    return 1;
}

int perguntasExcluir(int id)
{
    int indice = indicePorId(id);
    if (indice < 0) return 0;
    memmove(&listaPerguntas[indice], &listaPerguntas[indice + 1], (quantidadePerguntas - indice - 1) * sizeof(Pergunta));
    quantidadePerguntas--;
    return 1;
}

static int contemTexto(const char *texto, const char *termo)
{
    for (; *texto; texto++) {
        size_t j = 0;
        while (termo[j] && texto[j] && tolower((unsigned char)texto[j]) == tolower((unsigned char)termo[j])) j++;
        if (!termo[j]) return 1;
    }
    return !*termo;
}

int perguntasPesquisar(const char *termo, int inicio, Pergunta *pergunta)
{
    if (!termo || !pergunta || inicio < 0) return -1;
    for (int i = inicio; i < (int)quantidadePerguntas; i++) {
        char id[24];
        snprintf(id, sizeof(id), "%d", listaPerguntas[i].id);
        if (!*termo || strcmp(id, termo) == 0 || contemTexto(listaPerguntas[i].enunciado, termo) || contemTexto(listaPerguntas[i].metadados[0], termo)) {
            *pergunta = listaPerguntas[i];
            return i;
        }
    }
    return -1;
}
