/**
 * @file aula16.aula.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-09-04
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Função principal
 * @param argc Número de argumentos
 * @param argv Vetor de argumentos
 * @return 0 em caso de sucesso
 */

/**
 * @brief calcula o IMC (Índice de Massa Corporal) dado o peso e a altura
 *
 * @param peso peso em quilogramas
 * @param altura altura em metros
 * @return float retorna o im
 *
 */
float imc(float peso, float altura)
{
    return peso / (altura * altura);
}

int main(int argc, char *argv[])
{
    printf("foram recebidos %d argumentos!\n", argc - 1);
    float resultadoimc = imc(atof(argv[1]), atof(argv[2]));

    printf("Peso %d: %s\n", argv[1]);
    printf("Altura %d: %s\n", argv[2]);
    printf("IMC: %f\n", resultadoimc);

    if (resultadoimc < 18.5)
    {
        printf("Coma mais, voce está Abaixo do peso\n");
    }
    else if (resultadoimc >= 18.5 && resultadoimc < 25)
    {
        printf("Parabéns Peso normal\n");
    }
    else if (resultadoimc >= 25 && resultadoimc < 30)
    {
        printf("Atenção, você está com Sobrepeso\n");
    }
    else
    {
        printf("Se cuide vc está Obeso\n");
    }
    return 0;
}