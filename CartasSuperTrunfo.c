#include <stdio.h>

int main() {
    // --- Declaração de Variáveis ---
    
    // Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[30];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos1;
    float densidade_populacional1; // Novo: Para o desafio Aventureiro
    
    // Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[30];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float densidade_populacional2; // Novo: Para o desafio Aventureiro
    
    int escolha_atributo;
    int vencedor = 0; // 1 para Carta 1, 2 para Carta 2, 0 para Empate

    // --- 1. Entrada de dados da Carta 1 ---
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade (apenas uma palavra): ");
    scanf("%s", cidade1);
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // --- 2. Entrada de dados da Carta 2 ---
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade (apenas uma palavra): ");
    scanf("%s", cidade2);
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // --- 3. Cálculos de Atributos ---
    densidade_populacional1 = (float)populacao1 / area1;
    densidade_populacional2 = (float)populacao2 / area2;

    // --- 4. Menu Interativo e Lógica de Comparação ---
    
    printf("\n======================================\n");
    printf("         MENU DE COMPARAÇÃO           \n");
    printf("======================================\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Populacional (Regra Inversa)\n");
    printf("--------------------------------------\n");
    printf("Sua escolha: ");
    
    if (scanf("%d", &escolha_atributo) != 1) {
        printf("\nERRO: Entrada invalida. Encerrando.\n");
        return 1;
    }
    
    printf("\n--- Comparacao de Cartas ---\n");

    switch (escolha_atributo) {
        case 1: // Populacao - Vence o MAIOR
            printf("Atributo: Populacao\n");
            printf("Valores: %s: %lu | %s: %lu\n", cidade1, populacao1, cidade2, populacao2);
            if (populacao1 > populacao2) {
                vencedor = 1;
            } else if (populacao2 > populacao1) {
                vencedor = 2;
            }
            break;

        case 2: // Area - Vence o MAIOR
            printf("Atributo: Area\n");
            printf("Valores: %s: %.2f km² | %s: %.2f km²\n", cidade1, area1, cidade2, area2);
            if (area1 > area2) {
                vencedor = 1;
            } else if (area2 > area1) {
                vencedor = 2;
            }
            break;
            
        case 3: // PIB - Vence o MAIOR
            printf("Atributo: PIB\n");
            printf("Valores: %s: %.2f bi | %s: %.2f bi\n", cidade1, pib1, cidade2, pib2);
            if (pib1 > pib2) {
                vencedor = 1;
            } else if (pib2 > pib1) {
                vencedor = 2;
            }
            break;

        case 4: // Pontos Turisticos - Vence o MAIOR
            printf("Atributo: Pontos Turisticos\n");
            printf("Valores: %s: %d | %s: %d\n", cidade1, pontos1, cidade2, pontos2);
            if (pontos1 > pontos2) {
                vencedor = 1;
            } else if (pontos2 > pontos1) {
                vencedor = 2;
            }
            break;
            
        case 5: // Densidade Populacional - Vence o MENOR (Regra Inversa!)
            printf("Atributo: Densidade Populacional\n");
            printf("!!! REGRA INVERSA: Vence o MENOR valor !!!\n");
            printf("Valores: %s: %.2f hab/km² | %s: %.2f hab/km²\n", cidade1, densidade_populacional1, cidade2, densidade_populacional2);
            
            // Regra Inversa: O MENOR valor ganha
            if (densidade_populacional1 < densidade_populacional2) {
                vencedor = 1; 
            } else if (densidade_populacional2 < densidade_populacional1) {
                vencedor = 2;
            }
            break;

        default: 
            printf("\nOpcao invalida! Por favor, escolha um numero entre 1 e 5.\n");
            return 1;
    }

    // --- 5. Exibição do Resultado Final ---
    printf("--------------------------------------\n");
    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) VENCEU!\n", cidade1);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) VENCEU!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("======================================\n");

    return 0;
}
