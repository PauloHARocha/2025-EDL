#include <stdio.h>

int main() {
    // STRINGS EM C:
    // Uma string é um vetor de char terminado pelo caractere '\0' (NULL).
    // Existem várias formas de inicializar/atribuir valores a uma string.

    char nome[50];   // string criada como vetor de 50 caracteres

    // Entrada pelo teclado
    printf("Digite seu nome: ");
    gets(nome);   // lê do teclado (Deprecated)
    // fgets(nome, 50, stdin);   // novo uso
    printf("Você digitou: ");
    puts(nome);   // imprime a string

    // Atribuição direta com ""
    char linguagem1[] = "C";  
    // Aqui o compilador coloca automaticamente o '\0' no final

    // Atribuição com lista de caracteres {}
    char linguagem2[] = {'J', 'a', 'v', 'a', '\0'};  
    // Precisa colocar o '\0' manualmente!

    // Mostrando os dois
    printf("\nExemplo de strings atribuídas diretamente:\n");
    printf("linguagem1 = %s\n", linguagem1);
    printf("linguagem2 = %s\n", linguagem2);

    return 0;
}