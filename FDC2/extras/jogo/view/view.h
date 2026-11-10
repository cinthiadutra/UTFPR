/**
 * @file view.h
 * @brief Interface publica da camada visual.
 */

#ifndef VIEW_H
#define VIEW_H

/**
 * Inicializa a janela e os recursos visuais.
 */
void view_inicializar(void);

/**
 * Informa se a janela foi solicitada para fechar.
 *
 * @return 1 quando a janela deve ser fechada, 0 caso contrario.
 */
int view_deve_fechar(void);

/**
 * Atualiza a opcao selecionada com base no teclado.
 *
 * @param selecionada opcao atualmente selecionada.
 * @param confirmada recebe 1 quando ENTER for pressionado.
 * @return nova opcao selecionada.
 */
int view_atualizar_menu(int selecionada, int *confirmada);

/**
 * Desenha o menu principal na janela.
 *
 * @param selecionada opcao atualmente selecionada.
 */
void view_desenhar_menu(int selecionada);

void view_desenhar_fundo(void);
int view_fundo_disponivel(void);

/**
 * Libera os recursos visuais.
 */
void view_finalizar(void);

#endif
