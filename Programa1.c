#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void tarefa_cpu_bound(long limite) {
    printf("Iniciando tarefa CPU-bound (Buscando numeros primos ate %ld)...\n", limite);
    
    // Inicia a medição do tempo de CPU
    clock_t inicio = clock();
    long total_primos = 0;
    
    // Laço intensivo: A CPU vai executar bilhões de instruções matemáticas aqui
    for (long num = 2; num < limite; num++) {
        bool eh_primo = true;
        for (long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                eh_primo = false;
                break;
            }
        }
        if (eh_primo) {
            total_primos++;
        }
    }
    
    // Finaliza a medição do tempo de CPU
    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Concluido em %.4f segundos de tempo de CPU.\n", tempo_gasto);
    printf("Total de numeros primos encontrados: %ld\n", total_primos);
}

int main() {
    // Como o C é extremamente rápido, usamos 10 milhões para ocupar a CPU
    tarefa_cpu_bound(10000000);
    return 0;
}
