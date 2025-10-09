#include <stdio.h>

#define CASAS_T 5
#define CASAS_B 5
#define CASAS_R 8

#define CASAS_CAV_V 2
#define CASAS_CAV_H 1

int main() {
    
    printf("Movimento da TORRE:\n");
    
    for (int i = 1; i <= CASAS_T; i++) {
        printf("Direita\n");
    }
    
    printf("\n");
    
    
    printf("Movimento do BISPO:\n");
    
    int contador_b = 1;
    
    while (contador_b <= CASAS_B) {
        printf("Cima, Direita\n");
        contador_b = contador_b + 1;
    }
    
    printf("\n");
    
    
    printf("Movimento da RAINHA:\n");
    
    int contador_r = 0;
    
    do {
        printf("Esquerda\n");
        contador_r++;
    } while (contador_r < CASAS_R);
    
    printf("\n");
    
    
    printf("Movimento do CAVALO:\n");
    
    printf("\n--- Simulação do Cavalo com Loops Aninhados ---\n");
    
    for (int i = 0; i < CASAS_CAV_V; i++) {
        printf("Baixo\n");
        
        if (i == CASAS_CAV_V - 1) {
            int contador_h = 0;
            while (contador_h < CASAS_CAV_H) {
                printf("Esquerda\n");
                contador_h++;
            }
        }
    }
    
    printf("\nFIM DA SIMULACAO\n");
    
    return 0;
}
