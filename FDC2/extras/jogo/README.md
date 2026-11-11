# Jogo do Milhao

Base inicial da interface grafica usando [Raylib](https://www.raylib.com/) e C.

## Organizacao

- `main.c`: ponto de entrada.
- `sistema.h` e `sistema.c`: tipos e fluxo principal do sistema.
- `perguntas/perguntas.c` e `perguntas/perguntas.h`: cadastro, pesquisa e persistencia das perguntas.
- `view/view.h` e `view/view.c`: assinaturas e implementacao da interface
  grafica.
- `view/perguntaView.c` e `view/perguntaView.h`: tela visual da pergunta.
- `Makefile`: compilacao, execucao e limpeza.

## macOS

Instale a dependencia:

```bash
brew install raylib
```

Compile e execute:

```bash
make
make run
```

O fundo da interface fica em `assets/bk.png`. Use `UP` e `DOWN` para navegar
pelo menu e `ENTER` para selecionar uma opcao.
A opcao `Jogar` inicia a partida; `Perguntas` abre o gerenciamento.

## Persistencia das perguntas

Na primeira execucao, todas as perguntas sao importadas de
`perguntas/perguntas.csv` e mantidas em memoria. Ao selecionar Sair ou fechar
a janela, o programa salva os dados em `perguntas/perguntas.bin` e atualiza o CSV.
Nas execucoes seguintes, carrega diretamente o binario, sem precisar do CSV.
Para importar novamente o CSV, remova o binario com o jogo fechado.

O binario usa um identificador de formato e os registros da estrutura C;
e destinado a mesma plataforma e versao da estrutura `Pergunta`.
Um binario invalido interrompe o carregamento sem sobrescrever seus dados.

## Gerenciar perguntas

No menu `Perguntas`, digite para pesquisar por ID exato, trecho do enunciado
ou tema. Uma busca vazia lista todas as perguntas. Use as setas para selecionar.

- `F1` (ou `INSERT`): inserir uma pergunta com ID automatico.
- `F2`: alterar a selecionada; no formulario, confirmar e salvar.
- `DELETE`: excluir, com confirmacao por `ENTER` ou cancelamento por `ESC`.
- `TAB` ou clique: selecionar um campo do formulario.
- Setas esquerda/direita: escolher dificuldade e resposta correta.
- `ESC`: cancelar a edicao ou voltar ao menu.
- `F5`: tentar salvar novamente em caso de falha.

Cada cadastro, alteracao ou exclusao salva o binario e o CSV. Os campos de
tema e rodadas sao preservados e podem ser editados. O enunciado e as quatro
alternativas sao obrigatorios. Os campos de texto usam uma unica linha.
No Mac, pode ser necessario usar `Fn` junto das teclas de funcao.

O formato binario anterior e lido automaticamente. Na migracao, o CSV,
quando disponivel, fornece os metadados ausentes no formato antigo.

Execute `python3 tests/executar.py` para testar a persistencia e o cadastro
em pastas temporarias, sem alterar os dados do jogo.
