#include <stdio.h>

int main() {
    // VETORES:
    // Um vetor em C é uma coleção de elementos do MESMO tipo,
    // armazenados em posições CONTÍGUAS na memória.
    // O índice começa em 0 e o tamanho é FIXO (não muda em tempo de execução).

    int vetor[5];   // declara um vetor de 5 inteiros
    int soma = 0;

    // Lendo valores para o vetor
    printf("Digite 5 numeros inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);   // usa &vetor[i] para armazenar no índice correto
    }

    printf("\nValores armazenados no vetor:\n");
    for (int i = 0; i < 5; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
        soma += vetor[i];   // acumula a soma dos elementos
    }

    // Calculando a média
    float media = soma / 5.0;

    printf("\nSoma dos elementos = %d\n", soma);
    printf("Média dos elementos = %.2f\n", media);

    return 0;
}