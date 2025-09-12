#include <stdio.h>
#include <stdlib.h>

void troca_ender(int *a, int *b){
    // aqui a e b são ponteiros para int
    a = b;  // apenas troca a cópia do ponteiro (não afeta o chamador)
    printf("x (Dentro): %p\n", a);
}

int main(){
    int *x, y = 5, z = 6;
    x = &y;  // x aponta para y

    printf("Endereco y: %p\n", &y);
    printf("Endereco z: %p\n", &z);
    printf("x (Antes): %p\n", x);

    troca_ender(x, &z); // tenta mudar x dentro da função

    printf("x (Depois): %p\n", x); // x não mudou
    return 0;
}