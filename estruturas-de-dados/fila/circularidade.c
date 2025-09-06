#include <stdio.h>

int main() {
    int MAX = 5;  // tamanho do "círculo"
    int i, posicao;

    printf("Exemplo de circularidade com %%\n");
    printf("MAX = %d\n\n", MAX);

    for (i = 0; i < 15; i++) {
        posicao = i % MAX;  // fórmula do circular, resto da divisão inteira de i por MAX
        printf("i = %2d -> posicao = %d  (pois %d = %d*%d + %d)\n",
               i, posicao, i, i/MAX, MAX, posicao);
    }

    return 0;
}