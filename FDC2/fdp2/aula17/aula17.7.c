#include <stdio.h>
 #include <stdlib.h>

 typedef struct 
 {
    char nome[50];
    float nota;
    char turma[1];
 }Alunos;
 
void calcularMediaGeral(
   Alunos *alunos, int quantidade, float *media
){
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].nota;
    }
    *media = soma / quantidade;
}

void calcularMediaDaTurma(
   Alunos *alunos, int quantidade, float *media
){
    float soma = 0;
    int count = 0;
    char turma[1];
    
    printf("Digite a turma para calcular a média: ");
    scanf("%s", turma);
    
    for (int i = 0; i < quantidade; i++) {
        if (alunos[i].turma[0] == turma[0]) {
            soma += alunos[i].nota;
            count++;
        }
        
    }

    printf("A quantidade de alunos na turma %s é: %d\n", turma, count);
    printf("A média da turma %s é: %.2f\n", turma, soma / count);
    
   
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
        printf("Digite a turma do aluno %d: ", i + 1);
        scanf("%s", alunos[i].turma);
    }

    // Calcular a média das notas
    calcularMediaGeral(alunos, 5, &media);
    printf("A média das notas é: %.2f\n", media);

    //calcular a média da turma
    calcularMediaDaTurma(alunos, 5, &media);
    printf("A média da turma é: %.2f\n", media);

    // Identificar o aluno com a maior nota
    identificarMaiorNota(alunos, 5, &maiorAluno);
    printf("O aluno com a maior nota é: %s com nota %.2f\n é da turma %s", maiorAluno.nome, maiorAluno.nota, maiorAluno.turma);
    // Exibir os dados de todos os alunos
    printf("\nDados das Turmas:\n");
    for (int i = 0; i < aluno[i].; i++) {
        printf("Aluno: %s, Nota: %.2f, Turma: %s\n", alunos[i].nome, alunos[i].nota, alunos[i].turma);
    }

    return 0;
}
