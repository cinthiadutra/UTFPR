/**
 * @file aula15.2.c
 * @author Cinthia Dutra (cinthia.dutra@utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2026-08-26
 *
 * @copyright Copyright (c) 2026
 *
 * Você foi contratado para desenvolver um sistema de cadastro de pessoas que permitirá armazenar e exibir informações essenciais de 5 indivíduos. 
 * Seu programa deve solicitar os seguintes dados para cada pessoa:

Nome, Idade, Peso, Data de nascimento (dia, mês e ano), 
Nacionalidade (Brasileiro ou Estrangeiro), 
Documento de identificação: Se for brasileiro, deve armazenar o CPF ou se for estrangeiro, deve armazenar o Passaporte

Regras obrigatórias:
Utilize structs para estruturar os dados da pessoa;
Utilize typedef para facilitar a definição de tipos personalizados;
Utilize union para armazenar CPF ou Passaporte, garantindo eficiência na memória;
Utilize enum para representar a nacionalidade da pessoa (Brasileiro ou Estrangeiro).
Após o cadastro, o programa deve exibir todas as informações cadastradas de maneira clara e organizada.


 */

 #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

    typedef enum {
        BRASILEIRO,
        ESTRANGEIRO
    } Nacionalidade;

    typedef union {
        char cpf[12]; // CPF tem 11 dígitos + '\0'
        char passaporte[20]; // Passaporte pode ter até 19 caracteres + '\0'
    } Documento;

    typedef struct{
        int diaNascimento;
        int mesNascimento;
        int anoNascimento;
    } DataNascimento;

    typedef struct {
        char nome[50];
        int idade;
        float peso;
        DataNascimento dataNascimento;
        Nacionalidade nacionalidade;
        Documento documento;
    } Pessoa;

int main(){
    setlocale(LC_ALL, "");

    Pessoa pessoas[5];

    for (int i = 0; i < 5; i++) {
        printf("Cadastro da pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf("%49s", pessoas[i].nome);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Peso: ");
        scanf("%f", &pessoas[i].peso);
        printf("Data de nascimento (dia mês ano): ");
        scanf("%d/ %d/ %d", &pessoas[i].dataNascimento.diaNascimento, &pessoas[i].dataNascimento.mesNascimento, &pessoas[i].dataNascimento.anoNascimento);
        printf("Nacionalidade (0 - Brasileiro, 1 - Estrangeiro): ");
        int opcao;
        scanf("%d", &opcao);
        pessoas[i].nacionalidade = opcao == 0 ? BRASILEIRO : ESTRANGEIRO;

        if (pessoas[i].nacionalidade == BRASILEIRO) {
            printf("CPF: ");
            scanf("%11s", pessoas[i].documento.cpf);
        } else {
            printf("Passaporte: ");
            scanf("%19s", pessoas[i].documento.passaporte);
        }
    }

    printf("\nInformações cadastradas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Data de nascimento: %02d/%02d/%04d\n", pessoas[i].dataNascimento.diaNascimento, pessoas[i].dataNascimento.mesNascimento,pessoas[i].dataNascimento.anoNascimento);
        printf("Nacionalidade: %s\n", pessoas[i].nacionalidade == BRASILEIRO ? "Brasileiro" : "Estrangeiro");
        if (pessoas[i].nacionalidade == BRASILEIRO) {
            printf("CPF: %s\n", pessoas[i].documento.cpf);
        } else {
            printf("Passaporte: %s\n", pessoas[i].documento.passaporte);
        }
    }

        printf("Cadastros: \n");
    for (int i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Data de nascimento: %02d/%02d/%04d\n", pessoas[i].dataNascimento.diaNascimento, pessoas[i].dataNascimento.mesNascimento, pessoas[i].dataNascimento.anoNascimento);
        printf("Nacionalidade: %s\n", pessoas[i].nacionalidade == BRASILEIRO ? "Brasileiro" : "Estrangeiro");
        if (pessoas[i].nacionalidade == BRASILEIRO) {
            printf("CPF: %s\n", pessoas[i].documento.cpf); 
        } else {
            printf("Passaporte: %s\n", pessoas[i].documento.passaporte);
        }
        printf("\n");
    }           
    return 0;
}