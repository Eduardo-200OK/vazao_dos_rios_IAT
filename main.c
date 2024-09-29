#include <stdio.h>

#define NUM_RIOS 10 // 10 é a quantidade de rios avaliados
#define MESES 24    // 24 é o número de meses avaliados
#define MAX_NOME_RIO 30

// Nomes dos rios
const char nomes_rios[NUM_RIOS][MAX_NOME_RIO] = { 
    "Rio Piraquara",
    "Rio Pequeno",
    "Rio Miringuava",
    "Rio Passauna",
    "Rio da Varzea",
    "Rio Bananas",
    "Rio das Pedras",
    "Rio Vitorino",
    "Rio Marmeleiro",
    "Rio Cachoeirinha"
};

// Vazão dos rios nos 2 anos analisados
float vazoes[NUM_RIOS][MESES] = {
    {1.80, 2.29, 2.40, 2.55, 2.56, 2.51, 2.38, 2.17, 2.01, 2.12, 1.69, 1.50, 1.40, 1.52, 2.44, 2.00, 2.36, 1.90, 2.15, 2.13, 1.73, 1.72, 2.07, 2.12},
    {1.84, 2.89, 1.80, 0.92, 0.61, 1.55, 1.13, 2.45, 1.25, 1.69, 2.91, 4.48, 4.12, 3.07, 5.46, 1.88, 1.90, 2.14, 1.46, 2.08, 1.84, 5.22, 5.42, 2.70},
    {1.00, 2.99, 0.84, 0.51, 0.48, 1.43, 1.00, 5.21, 0.80, 0.90, 2.36, 3.73, 6.92, 4.94, 10.01, 1.05, 1.74, 2.62, 0.77, 2.84, 1.11, 7.12, 5.09, 1.29},
    {1.59, 1.43, 2.03, 0.91, 1.09, 1.26, 0.90, 1.48, 1.03, 1.70, 1.06, 0.78, 1.59, 0.90, 0.74, 1.02, 1.35, 2.37, 1.09, 1.64, 2.04, 2.26, 2.43, 2.40},
    {3.09, 4.21, 1.94, 0.83, 1.17, 5.22, 3.64, 9.35, 3.54, 4.48, 5.73, 13.09, 10.98, 7.59, 19.38, 6.13, 5.70, 6.76, 4.60, 4.24, 3.83, 9.59, 11.02, 6.47},
    {4.67, 3.22, 1.06, 0.80, 1.71, 8.36, 3.97, 18.02, 3.14, 2.61, 2.08, 15.76, 23.80, 8.81, 7.19, 1.98, 1.16, 3.16, 2.41, 4.60, 2.58, 18.04, 3.89, 1.14},
    {2.97, 2.40, 1.00, 0.93, 1.58, 5.15, 3.01, 11.66, 2.20, 2.70, 1.02, 7.18, 17.79, 6.03, 3.40, 1.40, 1.08, 2.93, 1.79, 5.58, 2.43, 16.60, 5.87, 1.06},
    {3.10, 6.08, 3.84, 1.83, 5.11, 17.84, 13.31, 10.99, 5.09, 2.55, 1.42, 2.75, 15.83, 18.17, 4.98, 2.23, 1.53, 2.26, 2.30, 1.89, 6.02, 19.75, 11.45, 3.71},
    {1.99, 4.52, 1.15, 1.46, 5.14, 9.77, 7.55, 6.73, 1.06, 0.81, 0.64, 3.10, 10.22, 5.69, 2.70, 0.74, 0.74, 2.58, 1.49, 0.97, 4.01, 11.59, 2.56, 0.74},
    {0.33, 0.33, 0.27, 0.25, 0.21, 0.24, 0.23, 0.36, 0.25, 0.27, 0.34, 0.48, 0.47, 0.45, 0.52, 0.32, 0.35, 0.37, 0.32, 0.42, 0.32, 0.44, 0.34, 0.28}
};

void mostrarNomesRios(){
    printf("1 - Rio Piraquara\n");
    printf("2 - Rio Pequeno\n");
    printf("3 - Rio Miringuava\n");
    printf("4 - Rio Passauna\n");
    printf("5 - Rio da Varzea\n");
    printf("6 - Rio Bananas\n");
    printf("7 - Rio das Pedras\n");
    printf("8 - Rio Vitorino\n");
    printf("9 - Rio Marmeleiro\n");
    printf("10 - Rio Cachoeirinha\n");
}

void mostrarMeses(){
    printf("\n<-2020->\n");
    printf("(1) - Jan\t(2) - Fev\t(3) - Mar\t(4) - Abril\n");
    printf("(5) - Mai\t(6) - Jun\t(7) - Jul\t(8) - Ago\n");
    printf("(9) - Set\t(10) - Out\t(11) - Nov\t(12) - Dez\n");
    printf("\n<-2021->\n");
    printf("(13) - Jan\t(14) - Fev\t(15) - Mar\t(16) - Abril\n");
    printf("(17) - Mai\t(18) - Jun\t(19) - Jul\t(20) - Ago\n");
    printf("(21) - Set\t(22) - Out\t(23) - Nov\t(24) - Dez\n");
}

// Função para exibir o nome dos rios
void mostrarRios() {
  for (int i = 0; i < NUM_RIOS; i += 2) {
        if (i + 1 < NUM_RIOS) {
            printf("(%d) %-20s (%d) %-20s\n", i + 1, nomes_rios[i], i + 2, nomes_rios[i + 1]);
        } else {
            printf("(%d) %-20s\n", i + 1, nomes_rios[i]);
        }
    }
}


void mostrarVazao(int rio, int mes) {
    printf("A vazão do: %s no mes: %d é: %.2f\n", nomes_rios[rio], mes, vazoes[rio][mes - 1]);

}

void alterarVazao(int rio, int mes, float novaVazao) {
    vazoes[rio][mes - 1] = novaVazao;
    printf("Vazão alterada com sucesso!\n");
}

float calcularMedia(int rio, int mesInicio, int mesFim) {
    float soma = 0.0;
    int contador = 0;
    for (int i = mesInicio - 1; i < mesFim; i++) {
        soma += vazoes[rio][i];
        contador++;
    }
    return soma / contador;
}

void mostrarMaiorMenorVazao(int rio) {
    float maior = vazoes[rio][0], menor = vazoes[rio][0];
    int mesMaior = 1, mesMenor = 1;
    for (int i = 1; i < MESES; i++) {
        if (vazoes[rio][i] > maior) {
            maior = vazoes[rio][i];
            mesMaior = i + 1;
        }
        if (vazoes[rio][i] < menor) {
            menor = vazoes[rio][i];
            mesMenor = i + 1;
        }
    }
    printf("Maior vazão do: %s foi no mês %d: %.2f\n", nomes_rios[rio], mesMaior, maior);
    printf("Menor vazão do: %s foi no mês %d: %.2f\n", nomes_rios[rio], mesMenor, menor);
}

void mostrarRioMaiorVazao() {
    float maiorMedia = 0.0;
    int rioMaior = 0;
    for (int i = 0; i < NUM_RIOS; i++) {
        float media = calcularMedia(i, 1, MESES);
        if (media > maiorMedia) {
            maiorMedia = media;
            rioMaior = i;
        }
    }
    printf("O rio de maior vazão é o: %s tendo uma vazão média de: %.2f\n", nomes_rios[rioMaior], maiorMedia);
 
}

void mostrarRiosAcimaDeValor(float valor) {
    printf("Rios com vazão acima de: %.2f:\n", valor);
    for (int i = 0; i < NUM_RIOS; i++) {
        for (int m = 0; m < MESES; m++) {
            if (vazoes[i][m] > valor) {
                printf("%s, Mês: %d, Vazão: %.2f\n", nomes_rios[i], m + 1, vazoes[i][m]);
            }
        }
    }
}

int setRio() {
    mostrarNomesRios();
    int rio = 0;
    printf("Selecione o rio (1-10): ");
    scanf("%d", &rio);
    while (rio <= 0 || rio > 10) {
        mostrarRios();
        printf("O rio selecionado deve estar entre (1-10): ");
        scanf("%d", &rio);
    }
    return rio;
}

int setMes() {
    mostrarMeses();
    int mes = 0;
    printf("Digite o mês (1-24): ");
    scanf("%d", &mes);
    while (mes <= 0 || mes > 24) {
        printf("O mês selecionado deve estar entre (1-24): ");
        scanf("%d", &mes);
    }
    return mes;
}

int setMesInicio() {
    mostrarMeses();
    int mesInicio = 0;
    printf("Digite o mês inicial (1-24): ");
    scanf("%d", &mesInicio);
    while (mesInicio <= 0 || mesInicio > 24) {
        printf("O mês inicial selecionado deve estar entre (1-24): ");
        scanf("%d", &mesInicio);
    }
    return mesInicio;
}

int setMesFinal(int mesInicial) {
    mostrarMeses();
    int mesFinal = 0;
    printf("Digite o mês final (1-24): ");
    scanf("%d", &mesFinal);
    while ((mesFinal <= 0 || mesFinal > 24) || (mesFinal < mesInicial)){
        printf("O mês final selecionado deve estar entre (1-24) ou o mes final deve ser maior que o mes inicial: ");
        scanf("%d", &mesFinal);
    }
    return mesFinal;
}

void menu() {
    int opcao;
    int rio = 0, mes = 0, mesInicio, mesFim;
    float novaVazao, valor;
    do {
        printf("\nMenu:\n");
        printf("1. Vazão do rio para um MÊS\n");
        printf("2. Alterar a vazão de um rio para um mês\n");
        printf("3. Retornar a vazão média de um rio\n");
        printf("4. Retornar o mês de maior e menor vazão de um rio\n");
        printf("5. Retornar rio de maior vazão\n");
        printf("6. Retornar quais rios e em quais meses tiveram uma vazão acima de um valor indicado\n");
        printf("7. LISTA DE RIOS\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    rio = setRio();
                    mes = setMes();
                    mostrarVazao(rio - 1, mes);
                    break;
                case 2:
                    rio = setRio();
                    mes = setMes();
                    printf("Digite a nova vazão: ");
                    scanf("%f", &novaVazao);
                    alterarVazao(rio - 1, mes, novaVazao);
                    break;
                case 3:
                    rio = setRio();
                    mesInicio = setMesInicio();
                    mesFim = setMesFinal(mesInicio);
                    printf("A vazão média do: %s entre os meses: %d e %d é: %.2f\n", nomes_rios[rio - 1], mesInicio, mesFim, calcularMedia(rio - 1, mesInicio, mesFim));
                    break;
                case 4:
                    rio = setRio();
                    mostrarMaiorMenorVazao(rio - 1);
                    break;
                case 5:
                    mostrarRioMaiorVazao();
                    break;
                case 6:
                    printf("Digite o valor de referência: ");
                    scanf("%f", &valor);
                    mostrarRiosAcimaDeValor(valor);
                    break;
                case 7:
                    mostrarRios();
                    break;
                case 8:
                    printf("Saindo...\n");
                    break;
                    default:
                printf("Opção inválida. Tente novamente.\n");
            
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
