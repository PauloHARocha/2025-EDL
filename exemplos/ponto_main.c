#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    float d;
    Ponto *p, *q;

    // Criação
    p = ponto_cria(10, 21);
    q = ponto_cria(7, 25);

    // Mostrando os dois pontos usando ponto_acessa
    float x, y;
    if (ponto_acessa(p, &x, &y))
        printf("Ponto P: (%.2f, %.2f)\n", x, y);
    if (ponto_acessa(q, &x, &y))
        printf("Ponto Q: (%.2f, %.2f)\n", x, y);

    // Distância inicial
    d = ponto_distancia(p, q);
    printf("Distancia inicial entre P e Q: %.2f\n", d);

    // Alterando valores com ponto_atribui 
    if (!ponto_atribui(p, 12.0f, 30.0f))
        printf("Falha ao atribuir valores a P\n");
    if (!ponto_atribui(q, 5.0f, 18.0f))
        printf("Falha ao atribuir valores a Q\n");

    // Mostrar novamente após alteração
    if (ponto_acessa(p, &x, &y))
        printf("Ponto P (novo): (%.2f, %.2f)\n", x, y);
    if (ponto_acessa(q, &x, &y))
        printf("Ponto Q (novo): (%.2f, %.2f)\n", x, y);

    // Distância após alteração
    d = ponto_distancia(p, q);
    printf("Distancia apos alterar P e Q: %.2f\n", d);

    // Liberação
    ponto_libera(p);
    ponto_libera(q);
    return 0;
}