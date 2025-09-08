#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Função auxiliar: retorna o nome do atributo pelo número do menu
const char *getNomeAtributo(int opcao)
{
    switch (opcao)
    {
    case 1:
        return "População";
    case 2:
        return "Área";
    case 3:
        return "PIB";
    case 4:
        return "Pontos Turísticos";
    case 5:
        return "Densidade Demográfica";
    default:
        return "Desconhecido";
    }
};

// Função para comparar um atributo e retornar pontos
int compararAtributo(int opcao, float valor1, float valor2, const char *nome1, const char *nome2)
{
    printf("\nComparando %s:\n", getNomeAtributo(opcao));
    printf("Carta 1 (%s): %.2f\n", nome1, valor1);
    printf("Carta 2 (%s): %.2f\n", nome2, valor2);

    if (opcao == 5)
    { // Densidade: menor vence
        return (valor1 < valor2) ? (printf("-> Carta 1 venceu neste atributo!\n"), 1) : (valor2 < valor1) ? (printf("-> Carta 2 venceu neste atributo!\n"), -1)
                                                                                                          : (printf("-> Empate neste atributo!\n"), 0);
    }
    else
    { // Regra geral: maior vence
        return (valor1 > valor2) ? (printf("-> Carta 1 venceu neste atributo!\n"), 1) : (valor2 > valor1) ? (printf("-> Carta 2 venceu neste atributo!\n"), -1)
                                                                                                          : (printf("-> Empate neste atributo!\n"), 0);
    }
};

int main()
{
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // Declaração das variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Variáveis calculadas
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Declaração das variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Variáveis calculadas
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada de dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Informe o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Informe o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Informe o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // lê até o ENTER, incluindo espaços

    printf("Informe a Populacao: ");
    scanf("%d", &populacao1);

    printf("Informe a Area em km²: ");
    scanf("%f", &area1);

    printf("Informe o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Informe o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);

    // Entrada de dados da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Informe o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Informe o Codigo da Carta (ex: B03): ");
    scanf("%s", codigo2);

    printf("Informe o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Informe a Populacao: ");
    scanf("%d", &populacao2);

    printf("Informe a Area em km²: ");
    scanf("%f", &area2);

    printf("Informe o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Informe o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // === Menu interativo ===
    int escolha1, escolha2;

    printf("=== Super Trunfo: Cidades ===\n");
    printf("Escolha dois atributos para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    // Primeira escolha
    printf("\nPrimeira escolha: ");
    scanf("%d", &escolha1);

    if (escolha1 < 1 || escolha1 > 5)
    {
        printf("Opção inválida!\n");
        return 0;
    }

    // Menu dinâmico: remove a opção já escolhida
    printf("\nEscolha o segundo atributo:\n");
    for (int i = 1; i <= 5; i++)
    {
        if (i != escolha1)
        {
            printf("%d - %s\n", i, getNomeAtributo(i));
        }
    }

    printf("\nSegunda escolha: ");
    scanf("%d", &escolha2);

    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1)
    {
        printf("Opção inválida!\n");
        return 0;
    }

    // === Comparações ===
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Primeiro atributo
    switch (escolha1)
    {
    case 1:
        pontosCarta1 += compararAtributo(1, populacao1, populacao2, nomeCidade1, nomeCidade2);
        break;
    case 2:
        pontosCarta1 += compararAtributo(2, area1, area2, nomeCidade1, nomeCidade1);
        break;
    case 3:
        pontosCarta1 += compararAtributo(3, pib1, pib2, nomeCidade1, nomeCidade2);
        break;
    case 4:
        pontosCarta1 += compararAtributo(4, pontosTuristicos1, pontosTuristicos2, nomeCidade1, nomeCidade2);
        break;
    case 5:
        pontosCarta1 += compararAtributo(5, densidade1, densidade2, nomeCidade1, nomeCidade2);
        break;
    default:
        printf("Erro inesperado!\n");
        return 0;
    }

    // Segundo atributo
    switch (escolha2)
    {
    case 1:
        pontosCarta1 += compararAtributo(1, populacao1, populacao2, nomeCidade1, nomeCidade2);
        break;
    case 2:
        pontosCarta1 += compararAtributo(2, area1, area2, nomeCidade1, nomeCidade1);
        break;
    case 3:
        pontosCarta1 += compararAtributo(3, pib1, pib2, nomeCidade1, nomeCidade2);
        break;
    case 4:
        pontosCarta1 += compararAtributo(4, pontosTuristicos1, pontosTuristicos2, nomeCidade1, nomeCidade2);
        break;
    case 5:
        pontosCarta1 += compararAtributo(5, densidade1, densidade2, nomeCidade1, nomeCidade2);
        break;
    default:
        printf("Erro inesperado!\n");
        return 0;
    }

    // Converter pontosCarta1 em pontosCarta2
    // (cada comparação retorna +1, -1 ou 0 para carta1; então carta2 = inverso)
    pontosCarta2 = -pontosCarta1;

    // === Resultado Final ===
    printf("\n=== Resultado Final ===\n");
    printf("Soma dos pontos:\n");
    printf("Carta 1 (%s): %d\n", nomeCidade1, pontosCarta1);
    printf("Carta 2 (%s): %d\n", nomeCidade2, pontosCarta2);

    if (pontosCarta1 > pontosCarta2)
    {
        printf("-> Carta 1 (%s) venceu a rodada!\n", nomeCidade1);
    }
    else if (pontosCarta2 > pontosCarta1)
    {
        printf("-> Carta 2 (%s) venceu a rodada!\n", nomeCidade2);
    }
    else
    {
        printf("-> Empate!\n");
    }

    return 0;
}
