#include <stdio.h>

// UNION:
// Uma union é parecida com struct, mas TODOS os campos
// compartilham o MESMO espaço de memória.
// Isso significa que só UM valor faz sentido de cada vez.
// Exemplo: um número que pode ser usado como inteiro ou float.
// É útil para economizar memória em casos específicos.

union Numero {
    int i;     // ocupa os mesmos bytes que o float
    float f;   // sobrescreve o valor de i
};

int main() {
    union Numero n;

    n.i = 10;         // ocupa o espaço da union
    printf("Inteiro: %d\n", n.i);

    n.f = 3.14;       // sobrescreve a memória
    printf("Float: %.2f\n", n.f);

    return 0;
}