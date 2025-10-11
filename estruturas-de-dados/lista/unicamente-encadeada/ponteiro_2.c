#include <stdio.h>
#include <stdlib.h>

void troca_ender(int **a, int *b){
    // agora a é um ponteiro para ponteiro
    *a = b;  // altera o conteúdo de x (que está no main)
    printf("x endereco (Dentro): %p\n", a);
    printf("x (Dentro): %p\n", *a);
}

int main(){
    int **x, *w, y = 5, z = 6;

    w = &y;   // w aponta para y
    x = &w;   // x aponta para w (ou seja, ponteiro para ponteiro)

    printf("Endereco y: %p\n", &y);
    printf("Endereco z: %p\n", &z);
    printf("Endereco w: %p\n", &w);
    printf("x endereco (Antes): %p\n", x);
    printf("*x (Antes): %p\n", *x);
    printf("**x (Antes): %d\n", **x);


    troca_ender(x, &z); // agora sim muda de verdade

    printf("x endereco (Depois): %p\n", x); // mudou para apontar para z
    printf("x (Depois): %d\n", **x); // mudou para apontar para z
    **x = 10;

    printf("x (Depois): %d\n", **x); // mudou para apontar para z
    return 0;
}