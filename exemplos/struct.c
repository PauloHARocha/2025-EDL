#include <stdio.h>

// STRUCT:
// Agrupa variáveis de tipos diferentes sob um mesmo nome.
struct Pessoa {
    char nome[50];  // inicializado na declaração (sem cópia depois)
    int  idade;
    char sexo;      // exemplo de campo char simples
};

int main() {
    // Criação e inicialização direta
    struct Pessoa p1 = {"Maria", 20, 'F'};

    printf("Inicial -> Nome: %s, Idade: %d, Sexo: %c\n", p1.nome, p1.idade, p1.sexo);

    // Alterando valores com operador '.' (struct direta)
    p1.idade = 25;
    p1.sexo  = 'F';   // apenas para ilustrar alteração de char

    printf("Com '.'   -> Idade: %d, Sexo: %c\n", p1.idade, p1.sexo);

    // Usando ponteiro para struct
    struct Pessoa *p2 = &p1;

    // Alterando com '->' (ponteiro)
    p2->idade = 30;
    p2->sexo  = 'F';

    printf("Com '->'  -> Idade: %d, Sexo: %c\n", p2->idade, p2->sexo);

    // Equivalência entre '->' e '(*ptr).campo'
    p2->idade      = 35;
    (*p2).idade    = 40; // ⇐ equivalente a p2->idade = 40

    p2->sexo       = 'F';
    (*p2).sexo     = 'F'; // ⇐ equivalente a p2->sexo = 'F'

    printf("Equivalência -> Idade: %d, Sexo: %c\n", p2->idade, p2->sexo);

    return 0;
}