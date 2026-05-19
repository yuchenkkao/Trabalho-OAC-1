#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matriz(long tamanho) {
    
    clock_t inicio = clock();


    printf("Alocando memoria RAM\n");
    int *matriz = (int *)malloc(tamanho * tamanho * sizeof(int));
    int *transposta = (int *)malloc(tamanho * tamanho * sizeof(int));

    if (matriz == NULL || transposta == NULL) {
        printf("Erro: Memoria RAM insuficiente para a alocacao.\n");
        return;
    }

    printf("Preenchendo a matriz original\n");
    for (long i = 0; i < tamanho * tamanho; i++) {
        matriz[i] = i % 100;
    }

    printf("Transpondo a matriz na memoria.\n");
    for (long i = 0; i < tamanho; i++) {
        for (long j = 0; j < tamanho; j++) {
    
            transposta[i * tamanho + j] = matriz[j * tamanho + i];
        }
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Concluido em %.4f segundos de tempo de CPU.\n", tempo_gasto);
    

    free(matriz);
    free(transposta);
    printf("Memoria liberada.\n");
}

int main() {

    matriz(15000);
    return 0;
}
