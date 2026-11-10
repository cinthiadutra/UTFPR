# Jogo do Milhao

Base inicial da interface grafica usando [Raylib](https://www.raylib.com/) e C.

## Organizacao

- `main.c`: ponto de entrada.
- `sistema.h` e `sistema.c`: tipos e fluxo principal do sistema.
- `perguntas/perguntas.c` e `perguntas/perguntas.h`: leitura da primeira
  pergunta do CSV.
- `view/view.h` e `view/view.c`: assinaturas e implementacao da interface
  grafica.
- `view/pergunta_view.c` e `view/pergunta_view.h`: tela visual da pergunta.
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
As opcoes `Jogar` e `Perguntas` ainda sao pontos de integracao para as proximas
partes do projeto.
