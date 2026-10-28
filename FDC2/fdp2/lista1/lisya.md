1) Crie uma estrutura que represente um atleta. Essa estrutura deve conter o nome do atleta, o esporte, a idade e a altura. Em seguida, escreva um programa que leia os dados de cinco atletas. Calcule e exiba o nome do atleta mais alto e o nome do atleta mais velho.
2) Utilizando a estrutura atleta do exercício anterior, escreva um programa que leia os dados de cinco atletas e os exiba em ordem de idade, do mais velho para o mais novo.

Dica: pesquise pelo algoritmo Bubble Sort no Google.

3) Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída um triângulo lateral formado por asteriscos, conforme o exemplo a seguir, em que n = 4:
*
**
***
****
***
**
*

4) Faça uma função que receba um inteiro N como parâmetro. Calcule e retorne o resultado da seguinte série S:


5) Crie um programa que gerencie um cadastro de materiais para obras disponíveis em um fornecedor. Cada material deve conter: nome (com tamanho máximo de 40 caracteres), quantidade (int) e preço (float). O cadastro deve ter capacidade para, no máximo, 15 produtos.

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
6) Escreva uma função para calcular o volume e a área de uma esfera, considerando π = 3.1414592. O valor do raio r deve ser passado por parâmetro, e os valores calculados devem ser retornados por referência.


7) Escreva uma função que receba como parâmetro um vetor contendo N valores inteiros. Essa função deve retornar, por referência, dois valores: a soma dos números pares e a soma dos números ímpares.


8) Elabore uma função que receba como parâmetros os coeficientes de uma equação do segundo grau. Em seguida, calcule e mostre suas raízes. Lembre-se de que as raízes são calculadas pela fórmula:



em que Δ = b² – 4 × a × c e ax² + bx + c = 0 representa uma equação do segundo grau.

A variável a deve ser diferente de zero. Caso a seja igual a zero, imprima a mensagem “Não é equação de segundo grau” e retorne o valor −1.

Caso contrário, retorne o número de raízes e as raízes, por referência, quando elas existirem:

Se Δ < 0, não existe raiz real. Número de raízes: 0.
Se Δ = 0, existe uma raiz real. Número de raízes: 1.
Se Δ > 0, existem duas raízes reais. Número de raízes: 2.
9) Faça uma função recursiva que calcule o valor da série S descrita a seguir, para um valor n maior que zero, fornecido como parâmetro:



10) Em matemática, o número harmônico, designado por Hₙ, define-se como o enésimo termo da série harmônica. Ou seja:



Escreva uma função recursiva que calcule o valor de qualquer Hn.

11) Crie uma função recursiva que retorne a soma dos elementos de um vetor de inteiros.
12) Crie uma função recursiva que retorne a média dos elementos de um vetor de inteiros.