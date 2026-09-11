/**
 * @file aula17.6.c
 * @author Cinthia Dutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que leia as notas de 5 alunos e 
 * armazene-as em um vetor de estruturas. Cada aluno tem um nome (string) 
 * e uma nota(float)

Crie funções para:

cadastrar os alunos;
calcular e retornar a média das notas;
identificar o aluno com a maior nota;
exibir os dados de todos os alunos.
Na main, chame as funções na sequencia e exiba os resultados obtidos e/ou retornados

Texto de resposta Questão 6
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct 
 {
    char nome[50];
    float nota;
 }Alunos;
 
void calcularMedia(
   Alunos *alunos, int quantidade, float *media
){
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].nota;
    }
    *media = soma / quantidade;
}

void identificarMaiorNota(
   Alunos *alunos, int quantidade, Alunos *maiorAluno
){
    *maiorAluno = alunos[0];
    for (int i = 1; i < quantidade; i++) {
        if (alunos[i].nota > maiorAluno->nota) {
            *maiorAluno = alunos[i];
        }
    }
}

int main() {
    Alunos alunos[5];
    float media;
    Alunos maiorAluno;

    // Cadastrar os alunos
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }

    // Calcular a média das notas
    calcularMedia(alunos, 5, &media);
    printf("A média das notas é: %.2f\n", media);

    // Identificar o aluno com a maior nota
    identificarMaiorNota(alunos, 5, &maiorAluno);
    printf("O aluno com a maior nota é: %s com nota %.2f\n", maiorAluno.nome, maiorAluno.nota);

    // Exibir os dados de todos os alunos
    printf("\nDados dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Aluno: %s, Nota: %.2f\n", alunos[i].nome, alunos[i].nota);
    }

    return 0;
}
