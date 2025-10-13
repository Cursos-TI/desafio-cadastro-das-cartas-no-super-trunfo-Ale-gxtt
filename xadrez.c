#include <stdio.h>

#define CASAS_T 5
#define CASAS_B 5
#define CASAS_R 8

#define PASSOS_CAV_V 2
#define PASSOS_CAV_H 1

void mover_torre_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Direita\n");
    mover_torre_recursivo(casas_restantes - 1);
}

void mover_bispo_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Cima, Direita\n");
    mover_bispo_recursivo(casas_restantes - 1);
}

void mover_rainha_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return;
    }
    printf("Esquerda\n");
    mover_rainha_recursivo(casas_restantes - 1);
}

void mover_bispo_loops_aninhados(int casas_max) {
    for (int v = 1; v <= casas_max; v++) {
        printf("Cima\n");
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }
}


int main() {
    
    printf("--- Movimento da TORRE (Recursividade - Direita) ---\n");
    mover_torre_recursivo(CASAS_T);
    printf("\n");
    
    printf("--- Movimento da RAINHA (Recursividade - Esquerda) ---\n");
    mover_rainha_recursivo(CASAS_R);
    printf("\n");
    
    printf("--- Movimento do BISPO (Recursividade - Cima e Direita) ---\n");
    mover_bispo_recursivo(CASAS_B);
    printf("\n");
    
    printf("--- Movimento do BISPO (Loops Aninhados - Cima e Direita) ---\n");
    mover_bispo_loops_aninhados(CASAS_B);
    printf("\n");
    
    printf("--- Movimento do CAVALO (Loops Aninhados Complexos - 2 Cima, 1 Direita) ---\n");
    
    for (int v = 1; v <= PASSOS_CAV_V; v++) {
        
        printf("Cima\n");

        if (v < PASSOS_CAV_V) {
            continue;
        }

        for (int h = 1; h <= PASSOS_CAV_H; h++) {
            
            printf("Direita\n");

            break; 
        }
    }
    
    printf("\nFIM DA SIMULACAO\n");
    
    return 0;
}
