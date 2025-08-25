#include<stdio.h>

/*
 * Funções em C:
 * - Servem para organizar o código em blocos reutilizáveis.
 * - Uma função pode receber valores (parâmetros) e devolver um resultado (return).
 *
 * IMPORTANTE:
 * - Os parâmetros são variáveis locais que recebem os valores enviados.
 * - O return devolve o resultado da função para quem a chamou.
 */

// Função que recebe dois inteiros (a e b) e devolve a soma
int soma(int a, int b){
    int c = a + b;   // variável local c armazena o resultado da soma
    return c;        // devolve o valor de c
}

int main(){
    int x = 2;       // variável x recebe 2
    int y = 3;       // variável y recebe 3
    int z = soma(x, y);  // chama a função soma(x, y) → retorna 5 e guarda em z

    // imprime o resultado da soma
    printf("Soma = %d\n", z);

    return 0;        // indica que o programa terminou sem erros
}