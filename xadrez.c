#include <stdio.h>

#define CASAS_T 5
#define CASAS_B 5
#define CASAS_R 8

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
    
    printf("\nFIM DA SIMULACAO\n");
    
    return 0;
}
