#include <stdio.h>
#include "natural.h"

int main() {
    Natural* n = natural_criar(5);

    printf("Valor inicial: %u\n", natural_acessa(n));

    natural_incrementar(n);
    natural_incrementar(n);

    printf("Valor depois de incrementar: %u\n", natural_acessa(n));

    natural_atribui(n, 0);

    printf("Valor depois de atribuir: %u\n", natural_acessa(n));

    natural_destruir(n);
    return 0;
}