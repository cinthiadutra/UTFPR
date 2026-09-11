/**
 * @file aula17.5.c
 * @author cinthiadutra (cinthiadutra@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2026-09-11
 * 
 * @copyright Copyright (c) 2026
 * 
 * Crie uma estrutura Aluno. Cada Aluno contém um nome, uma nota1, 
 * uma nota2, uma nota3 e uma média(float)

Faça um programa que cadastre os dados de um aluno.

Crie uma função calcularMedia que receba o aluno e calcule sua média. 
A média deverá ser armazenada no campo media da estrutura original.

Depois, na main, o programa deverá exibir o nome e a média do aluno

Requisito: utilize passagem por referência de uma struct.
 */

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
} Aluno;

void calcularMedia(Aluno *aluno) {
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3) / 3.0;
}

int main(){
    Aluno aluno;
    printf("Digite o nome do aluno: ");
    scanf("%49s", aluno.nome);
    printf("Digite a nota 1: ");
    scanf("%f", &aluno.nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &aluno.nota2);
    printf("Digite a nota 3: ");
    scanf("%f", &aluno.nota3);
    calcularMedia(&aluno);
    printf("Nome: %s\n", aluno.nome);
    printf("Média: %.2f\n", aluno.media);
    return 0;
}