/**
 * @file view.h
 * @brief Interface publica da camada visual.
 */

#ifndef viewH
#define viewH

/**
 * Inicializa a janela e os recursos visuais.
 */
void viewInicializar(void);

/**
 * Informa se a janela foi solicitada para fechar.
 *
 * @return 1 quando a janela deve ser fechada, 0 caso contrario.
 */
int viewDeveFechar(void);

/**
 * Atualiza a opcao selecionada com base no teclado.
 *
 * @param selecionada opcao atualmente selecionada.
 * @param confirmada recebe 1 quando ENTER for pressionado.
 * @return nova opcao selecionada.
 */
int viewAtualizarMenu(int selecionada, int *confirmada);

/**
 * Desenha o menu principal na janela.
 *
 * @param selecionada opcao atualmente selecionada.
 */
void viewDesenharMenu(int selecionada);

void viewDesenharFundo(void);
int viewFundoDisponivel(void);

/**
 * Libera os recursos visuais.
 */
void viewFinalizar(void);

#endif
