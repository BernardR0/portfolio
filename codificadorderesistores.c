#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    enum unidade_e {
        preto = 0,
        marrom = 1,
        vermelho = 2,
        laranja = 3,
        amarelo = 4,
        verde = 5,
        azul = 6,
        violeta = 7,
        cinza = 8,
        branco = 9,
        dourado = -1,
        prata = -2,
        ausente = -3 
    };

    struct resistor_t {
        int quantidade_de_cores;
        enum unidade_e cores[5];
        float resistencia;
        float resistencia_maxima;
        float resistencia_minima;
    };

    int escolha;
    do {
        int deu_certo = system("clear");

        printf("Calculadora de Resistência de Resistor\n");
        printf("1. Calcular resistência de resistor\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        deu_certo = scanf("%d", &escolha);
        if (deu_certo != 1) {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        if (escolha == 1) {


            int numero_de_faixas;
            struct resistor_t resistor;
            printf("O resistor tem 4 ou 5 cores? ");
            deu_certo = scanf("%d", &numero_de_faixas);
            if (numero_de_faixas != 4 && numero_de_faixas != 5) {
                printf("Número de faixas inválido!\n");
                deu_certo = system("clear");
                while (getchar() != '\n');
                continue;
            }
            resistor.quantidade_de_cores = numero_de_faixas;
            for (int i = 0; i < numero_de_faixas; i++) {
                char cor[10];

                printf("\nTabela de Cores dos Resistores:\n");
                printf("preto    - preto\n");
                printf("marrom   - marrom\n");
                printf("vermelho - vermelho\n");
                printf("laranja  - laranja\n");
                printf("amarelo  - amarelo\n");
                printf("verde    - verde\n");
                printf("azul     - azul\n");
                printf("violeta  - violeta\n");
                printf("cinza    - cinza\n");
                printf("branco   - branco\n");
                printf("dourado  - dourado\n");
                printf("prata    - prata\n");
                printf("ausente  - ausente\n\n");

                printf("Digite o nome da cor da faixa %d: ", i + 1);
                deu_certo = scanf("%s", cor);
                deu_certo = system("clear");
                if (strcmp(cor, "preto") == 0) resistor.cores[i] = preto;
                else if (strcmp(cor, "marrom") == 0) resistor.cores[i] = marrom;
                else if (strcmp(cor, "vermelho") == 0) resistor.cores[i] = vermelho;
                else if (strcmp(cor, "laranja") == 0) resistor.cores[i] = laranja;
                else if (strcmp(cor, "amarelo") == 0) resistor.cores[i] = amarelo;
                else if (strcmp(cor, "verde") == 0) resistor.cores[i] = verde;
                else if (strcmp(cor, "azul") == 0) resistor.cores[i] = azul;
                else if (strcmp(cor, "violeta") == 0) resistor.cores[i] = violeta;
                else if (strcmp(cor, "cinza") == 0) resistor.cores[i] = cinza;
                else if (strcmp(cor, "branco") == 0) resistor.cores[i] = branco;
                else if (strcmp(cor, "dourado") == 0) resistor.cores[i] = dourado;
                else if (strcmp(cor, "prata") == 0) resistor.cores[i] = prata;
                else if (strcmp(cor, "ausente") == 0) resistor.cores[i] = ausente; 
                else {
                    printf("\nTabela de Cores dos Resistores:\n");
                    printf("preto    - preto\n");
                    printf("marrom   - marrom\n");
                    printf("vermelho - vermelho\n");
                    printf("laranja  - laranja\n");
                    printf("amarelo  - amarelo\n");
                    printf("verde    - verde\n");
                    printf("azul     - azul\n");
                    printf("violeta  - violeta\n");
                    printf("cinza    - cinza\n");
                    printf("branco   - branco\n");
                    printf("dourado  - dourado\n");
                    printf("prata    - prata\n");
                    printf("ausente  - ausente\n\n");

                    printf("Cor inválida!\n");
                    deu_certo = system("clear");
                    i--; 
                }
            }
            int valor_base = 0;
            float multiplicador = 1;
            float tolerancia = 0;
            if (numero_de_faixas == 4) {
                valor_base = resistor.cores[0] * 10 + resistor.cores[1];
                multiplicador = pow(10, resistor.cores[2]);
                tolerancia = (resistor.cores[3] == dourado) ? 5 : (resistor.cores[3] == prata) ? 10 : 20; 
            } else if(numero_de_faixas == 5) {
                valor_base = resistor.cores[0] * 100 + resistor.cores[1] * 10 + resistor.cores[2];
                multiplicador = pow(10, resistor.cores[3]);
                tolerancia = (resistor.cores[4] == dourado) ? 5 : (resistor.cores[4] == prata) ? 10 : 20; 
            }
            resistor.resistencia = valor_base * multiplicador;
            resistor.resistencia_maxima = resistor.resistencia * (1 + tolerancia / 100);
            resistor.resistencia_minima = resistor.resistencia * (1 - tolerancia / 100);
            printf("\nResistência: %.2f ohms\n", resistor.resistencia);
            printf("Resistência máxima: %.2f ohms\n", resistor.resistencia_maxima);
            printf("Resistência mínima: %.2f ohms\n", resistor.resistencia_minima);
            printf("Pressione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        } else if (escolha != 2) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 2);
    printf("Saindo...\n");
    return 0;
}