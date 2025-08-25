#include <stdlib.h>
#include <math.h>
#include "ponto.h" //inclui os prototipos

struct ponto{//definicao do tipo de dados
    float x;
    float y;
};

Ponto* ponto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void ponto_libera(Ponto* p){
    free(p);
}

int ponto_acessa(Ponto* p, float* x, float* y){
    if(p == NULL) return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

int ponto_atribui(Ponto* p, float x, float y){
    if(p == NULL) return 0;
    p->x = x;
    p->y = y;
    return 1;
}

// Fórmula da distância euclidiana no plano:
// d = √((x1 - x2)² + (y1 - y2)²)
float ponto_distancia(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL) return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}