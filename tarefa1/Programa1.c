#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void encontrar_primos(long limite) {
    
    clock_t inicio = clock();
    long total_primos = 0;
    

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
    

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Concluido em %.4f segundos de tempo de CPU.\n", tempo_gasto);
    printf("Total de numeros primos encontrados: %ld\n", total_primos);
}

int main() {

    encontrar_primos(10000000);
    return 0;
}
