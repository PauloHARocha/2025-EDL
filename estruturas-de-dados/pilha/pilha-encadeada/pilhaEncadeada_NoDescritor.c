#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;                 
    struct elemento *prox;
} Elem;

typedef struct descritor {
    Elem *topo;
    int qtd;
} Pilha;


Pilha* cria_Pilha(){
    Pilha *pi = malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL; 
        pi->qtd  = 0;
    }
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem *no = pi->topo;
        while(no != NULL){
            Elem *prox = no->prox;
            free(no);
            no = prox;
        }
        free(pi);         
    }
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) 
        return 1;
    return 0;
}


int tamanho_Pilha(Pilha* pi){
    if(pi == NULL) 
        return 0; 
    return pi->qtd;
}

// peek
int acessa_topo_Pilha(Pilha* pi, int *x){ 
    if(pi == NULL || pi->topo == NULL) 
        return 0;
    *x = pi->topo->dado;
    return 1;
}

// push
int insere_Pilha(Pilha* pi, int x){ 
    if(pi == NULL) 
        return 0;

    Elem *no = malloc(sizeof(Elem));
    if(no == NULL) 
        return 0;

    no->dado = x;
    no->prox = pi->topo;   
    pi->topo = no; 
    pi->qtd++;
    return 1;
}

// pop
int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) 
        return 0;

    Elem *no = pi->topo;            
    pi->topo = no->prox;           
    free(no);
    pi->qtd--;
    return 1;
}

int main(){
    Pilha *pi = cria_Pilha();
    insere_Pilha(pi, 10);
    insere_Pilha(pi, 20);
    insere_Pilha(pi, 30);

    printf("tamanho = %d\n", tamanho_Pilha(pi));  // 3
    int t;
    if(acessa_topo_Pilha(pi, &t)) 
        printf("topo = %d\n", t); // 30

    remove_Pilha(pi);
    acessa_topo_Pilha(pi, &t);
    printf("topo = %d, tamanho = %d\n", t, tamanho_Pilha(pi)); // 20, 2

    printf("vazia? %s\n", Pilha_vazia(pi) ? "sim" : "nao");

    libera_Pilha(pi);
    return 0;
}