#include <stdio.h>

/*
 * printf → usado para IMPRIMIR valores na tela.
 * scanf  → usado para LER valores do teclado.
 *
 * IMPORTANTE:
 * - printf recebe o valor da variável (ex.: peso, altura).
 * - scanf PRECISA saber ONDE guardar o valor → por isso usamos &variavel
 *   (endereço de memória da variável).
 */

int main() {
    int idade;
    float peso;

    // Exemplo com printf → imprimindo texto e variáveis
    printf("Exemplo de printf:\n");
    idade = 25;
    peso = 70.5;
    printf("Idade = %d anos, Peso = %.1f kg\n\n", idade, peso);

    // Exemplo com scanf → lendo valores do usuário
    printf("Digite sua idade: ");
    scanf("%d", &idade);   // precisa de &idade (endereço) para salvar o valor

    printf("Digite seu peso: ");
    scanf("%f", &peso);    // precisa de &peso (endereço) para salvar o valor

    printf("\nVocê tem %d anos e pesa %.2f kg.\n", idade, peso);

    return 0;
}