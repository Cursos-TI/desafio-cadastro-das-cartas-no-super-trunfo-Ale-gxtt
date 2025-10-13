#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função exit() em caso de erro

// Estrutura para representar os atributos da carta
typedef struct {
    char estado;
    char codigo[4];
    char cidade[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
} Carta;

// Função auxiliar para exibir o menu de atributos de forma dinâmica
// Recebe a escolha do primeiro atributo (escolha1) para omiti-lo na segunda vez
void exibir_menu_atributos(int escolha1) {
    printf("\nOpcoes de Atributos:\n");
    // O operador ternário abaixo indica se a opção está "disponível" ou se foi "escolhida"
    printf("1. Populacao %s\n", (escolha1 == 1) ? "(ESCOLHIDO)" : "");
    printf("2. Area %s\n", (escolha1 == 2) ? "(ESCOLHIDO)" : "");
    printf("3. PIB %s\n", (escolha1 == 3) ? "(ESCOLHIDO)" : "");
    printf("4. Pontos Turisticos %s\n", (escolha1 == 4) ? "(ESCOLHIDO)" : "");
    printf("5. Densidade Populacional (Inversa) %s\n", (escolha1 == 5) ? "(ESCOLHIDO)" : "");
    printf("--------------------------------------\n");
}

// Função para obter o valor numérico de um atributo (convertido para float para facilitar a soma)
// O valor retornado representa o valor numérico puro do atributo.
float obter_valor_atributo(const Carta *carta, int atributo_id) {
    switch (atributo_id) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->pontos_turisticos;
        case 5: return carta->densidade_populacional;
        default: return 0.0f;
    }
}

// Função para obter o nome do atributo (string)
const char* obter_nome_atributo(int atributo_id) {
    switch (atributo_id) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        default: return "INVALIDO";
    }
}

// Função para a lógica de comparação individual do atributo
// Retorna: 1 se Carta 1 vence, 2 se Carta 2 vence, 0 se é empate.
int comparar_atributo_individual(float valor1, float valor2, int atributo_id) {
    if (atributo_id == 5) { // Densidade Populacional: Vence o MENOR
        if (valor1 < valor2) return 1;
        if (valor2 < valor1) return 2;
    } else { // Outros atributos: Vence o MAIOR
        if (valor1 > valor2) return 1;
        if (valor2 > valor1) return 2;
    }
    return 0; // Empate
}

int main() {
    // Declaração de Cartas usando a estrutura
    Carta carta1, carta2;
    int escolha_attr1 = 0, escolha_attr2 = 0;
    
    // Variáveis para a lógica do desafio final
    float valor1_attr1, valor2_attr1;
    float valor1_attr2, valor2_attr2;
    float soma_carta1, soma_carta2;
    int vencedor_final = 0; // 1 para Carta 1, 2 para Carta 2, 0 para Empate

    // --- 1. Entrada de dados da Carta 1 ---
    printf("--- Cadastro da Carta 1 (%s) ---\n", carta1.cidade);
    printf("Nome da Cidade (apenas uma palavra): ");
    if (scanf("%s", carta1.cidade) != 1) return 1;
    printf("Estado (A-H): ");
    if (scanf(" %c", &carta1.estado) != 1) return 1;
    printf("Codigo da Carta (ex: A01): ");
    if (scanf("%s", carta1.codigo) != 1) return 1;
    printf("Populacao: ");
    if (scanf("%lu", &carta1.populacao) != 1) return 1;
    printf("Area (em km²): ");
    if (scanf("%f", &carta1.area) != 1) return 1;
    printf("PIB (em bilhoes de reais): ");
    if (scanf("%f", &carta1.pib) != 1) return 1;
    printf("Numero de Pontos Turisticos: ");
    if (scanf("%d", &carta1.pontos_turisticos) != 1) return 1;

    // --- 2. Entrada de dados da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 (%s) ---\n", carta2.cidade);
    printf("Nome da Cidade (apenas uma palavra): ");
    if (scanf("%s", carta2.cidade) != 1) return 1;
    printf("Estado (A-H): ");
    if (scanf(" %c", &carta2.estado) != 1) return 1;
    printf("Codigo da Carta (ex: B02): ");
    if (scanf("%s", carta2.codigo) != 1) return 1;
    printf("Populacao: ");
    if (scanf("%lu", &carta2.populacao) != 1) return 1;
    printf("Area (em km²): ");
    if (scanf("%f", &carta2.area) != 1) return 1;
    printf("PIB (em bilhoes de reais): ");
    if (scanf("%f", &carta2.pib) != 1) return 1;
    printf("Numero de Pontos Turisticos: ");
    if (scanf("%d", &carta2.pontos_turisticos) != 1) return 1;

    // --- 3. Cálculos de Atributos (Densidade) ---
    carta1.densidade_populacional = (carta1.area > 0) ? (float)carta1.populacao / carta1.area : 0.0f;
    carta2.densidade_populacional = (carta2.area > 0) ? (float)carta2.populacao / carta2.area : 0.0f;

    // ---------------------------------------------
    // --- 4. Menu Interativo e Escolha de Dois Atributos ---
    // ---------------------------------------------
    printf("\n======================================\n");
    printf("       COMPARAÇÃO AVANÇADA - MESTRE    \n");
    printf("======================================\n");
    
    // --- Escolha do 1º Atributo ---
    do {
        exibir_menu_atributos(0); // Exibe todas as opções
        printf("Escolha o PRIMEIRO atributo para comparar (1-5): ");
        if (scanf("%d", &escolha_attr1) != 1 || escolha_attr1 < 1 || escolha_attr1 > 5) {
            printf("\nOpcao invalida! Tente novamente.\n");
            // Limpa o buffer de entrada em caso de falha na leitura
            while(getchar() != '\n'); 
            escolha_attr1 = 0; // Força a repetição do loop
        }
    } while (escolha_attr1 == 0);

    printf("\nPRIMEIRO ATRIBUTO ESCOLHIDO: %s\n", obter_nome_atributo(escolha_attr1));
    
    // --- Escolha do 2º Atributo (Dinâmico) ---
    do {
        exibir_menu_atributos(escolha_attr1); // O atributo 1 aparecerá como ESCOLHIDO
        printf("Escolha o SEGUNDO atributo para comparar (1-5): ");
        if (scanf("%d", &escolha_attr2) != 1 || escolha_attr2 < 1 || escolha_attr2 > 5) {
            printf("\nOpcao invalida! Tente novamente.\n");
            while(getchar() != '\n');
            escolha_attr2 = 0;
        } else if (escolha_attr2 == escolha_attr1) {
            printf("\nERRO: Voce nao pode escolher o mesmo atributo novamente! Tente outro.\n");
            escolha_attr2 = 0;
        }
    } while (escolha_attr2 == 0);

    printf("\nSEGUNDO ATRIBUTO ESCOLHIDO: %s\n", obter_nome_atributo(escolha_attr2));

    // --- 5. Lógica de Comparação e Soma ---

    // Obtém os valores dos atributos escolhidos
    valor1_attr1 = obter_valor_atributo(&carta1, escolha_attr1);
    valor2_attr1 = obter_valor_atributo(&carta2, escolha_attr1);
    
    valor1_attr2 = obter_valor_atributo(&carta1, escolha_attr2);
    valor2_attr2 = obter_valor_atributo(&carta2, escolha_attr2);
    
    // Calcula a Soma dos Atributos
    soma_carta1 = valor1_attr1 + valor1_attr2;
    soma_carta2 = valor2_attr1 + valor2_attr2;

    // Variáveis para a exibição dos resultados individuais
    int v_attr1 = comparar_atributo_individual(valor1_attr1, valor2_attr1, escolha_attr1);
    int v_attr2 = comparar_atributo_individual(valor1_attr2, valor2_attr2, escolha_attr2);
    
    // Lógica da Comparação Final (Soma dos Atributos)
    if (soma_carta1 > soma_carta2) {
        vencedor_final = 1;
    } else if (soma_carta2 > soma_carta1) {
        vencedor_final = 2;
    } else {
        vencedor_final = 0; // Empate
    }

    // --- 6. Exibição Clara do Resultado ---
    printf("\n======================================\n");
    printf("           RESULTADO FINAL           \n");
    printf("======================================\n");
    printf("Pais 1: %s (Cod: %s) | Pais 2: %s (Cod: %s)\n", carta1.cidade, carta1.codigo, carta2.cidade, carta2.codigo);
    printf("--------------------------------------\n");

    // Exibição do 1º Atributo com Operador Ternário
    printf("Atributo 1: %s %s\n", 
           obter_nome_atributo(escolha_attr1), 
           (escolha_attr1 == 5) ? "(MENOR VENCE)" : "(MAIOR VENCE)");
    printf("  %s: %.2f | %s: %.2f => Vencedor: %s\n", 
           carta1.cidade, valor1_attr1, 
           carta2.cidade, valor2_attr1,
           (v_attr1 == 1) ? carta1.cidade : (v_attr1 == 2 ? carta2.cidade : "Empate"));
    printf("--------------------------------------\n");

    // Exibição do 2º Atributo com Operador Ternário
    printf("Atributo 2: %s %s\n", 
           obter_nome_atributo(escolha_attr2), 
           (escolha_attr2 == 5) ? "(MENOR VENCE)" : "(MAIOR VENCE)");
    printf("  %s: %.2f | %s: %.2f => Vencedor: %s\n", 
           carta1.cidade, valor1_attr2, 
           carta2.cidade, valor2_attr2,
           (v_attr2 == 1) ? carta1.cidade : (v_attr2 == 2 ? carta2.cidade : "Empate"));
    printf("--------------------------------------\n");

    // Exibição da Soma dos Atributos
    printf("Soma Total: \n");
    printf("  %s: %.2f \n", carta1.cidade, soma_carta1);
    printf("  %s: %.2f \n", carta2.cidade, soma_carta2);
    printf("--------------------------------------\n");
    
    // Exibição do Resultado Final (Com Operador Ternário no final)
    printf("VENCEDOR GERAL: %s\n", 
           (vencedor_final == 1) ? carta1.cidade : (vencedor_final == 2 ? carta2.cidade : "EMPATE!"));
    printf("======================================\n");

    return 0;
}
