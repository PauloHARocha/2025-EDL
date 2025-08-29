#include "natural.h"
#include <stdlib.h>
#include <stdio.h>

// Implementação real (oculta do usuário)
struct natural {
    int valor;
};

Natural* natural_criar(int valor) {
    Natural* n = malloc(sizeof(Natural));
    if (n != NULL) {
        if (valor < 0) {
            n->valor = 0;
        } else {
            n->valor = valor;
        }
    }
    return n;
}

int natural_acessa(const Natural* n) {
    return n->valor;
}

void natural_incrementar(Natural* n) {
    n->valor++;
}

void natural_destruir(Natural* n) {
    free(n);
}

void natural_atribui(Natural* n, int valor){
    if(valor >= 0){
        n->valor = valor;
    }
}