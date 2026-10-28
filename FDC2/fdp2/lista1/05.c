/**
 * @file 05.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-09
 * 
 * @copyright Copyright (c) 2026
 * 
 * 5) Crie um programa que gerencie um cadastro de materiais para obras disponíveis em um fornecedor.
 *  Cada material deve conter: nome (com tamanho máximo de 40 caracteres), quantidade (int) e preço (float). 
 * O cadastro deve ter capacidade para, no máximo, 15 produtos.

O programa deve possuir um menu que permita ao usuário manipular os cadastros. Nesse menu:

a) Ao digitar a opção I, deve-se realizar a inserção de um material na primeira posição livre;
b) Ao digitar a opção R, deve-se remover um material pelo índice, que deverá ser fornecido pelo usuário;
c) Ao digitar a opção L, deve-se listar todos os cadastros preenchidos;
d) Ao digitar a opção P, deve-se solicitar o nome de um material e exibir sua quantidade e seu preço;
e) Ao digitar a opção V, deve-se listar todos os produtos que tenham quantidade igual a zero;
f) Ao digitar a opção S, o programa deve ser encerrado.

Observações:

Cada opção do menu deve ser implementada em uma função diferente.
Após a execução de cada função, o menu deve ser reexibido, exceto na opção S.
Não utilize variáveis globais. Utilize passagem de parâmetros quando necessário.
Não se esqueça de criar um método para verificar qual posição do vetor está livre.
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 typedef struct 
 {
   char nome[40];
   int quantidade;
   float preco;

 }Material;

 void insertItem(Material mat)
 {
printf("Insira o nome do material:");
fgets(mat.nome, 50, stdin);
        mat.nome[strcspn(mat.nome, "\n")] = '\0';
setbuf(stdin, NULL);

printf("Insira a quantidade do material:");
scanf("%d", &mat.quantidade);

printf("Insira o preço do material:");
scanf("%.1f", &mat.preco);

 }
 void removeItem(int index){


 }
