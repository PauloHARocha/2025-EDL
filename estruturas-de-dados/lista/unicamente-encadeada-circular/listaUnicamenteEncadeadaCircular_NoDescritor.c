#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *prox;
} Elem;

typedef struct descritor {
    Elem *final;  // aponta pro último nó
    int qtd;      // opcional
} Lista;

Lista* cria_lista() {
    Lista *li = malloc(sizeof(Lista));
    if (li != NULL) {
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

int lista_vazia(Lista *li) {
    return (li == NULL || li->final == NULL);
}

int tamanho_lista(Lista* li){
    if(li == NULL) return -1;
    return li->qtd;             
}

int insere_inicio(Lista *li, int x) {
    if (li == NULL) 
        return 0;

    Elem *no = malloc(sizeof(Elem));
    if (no == NULL) 
        return 0;

    no->dado = x;

    // Caso 1: lista vazia
    if (li->final == NULL) {
        no->prox = no;        // aponta para si mesmo
        li->final = no;
    }
    // Caso 2: há elementos (insere antes do primeiro)
    else {
        no->prox = li->final->prox;  // novo aponta para o antigo início
        li->final->prox = no;        // último aponta para o novo início
    }

    li->qtd++;  
    return 1;
}

int insere_final(Lista *li, int x) {
    if (li == NULL) 
        return 0;
    Elem *no = malloc(sizeof(Elem));
    if (no == NULL) 
        return 0;

    no->dado = x;
    if (li->final == NULL) {  // lista vazia
        no->prox = no;        // aponta pra ele mesmo
    } else {
        no->prox = li->final->prox;  // novo nó aponta pro início
        li->final->prox = no;        // último aponta pro novo
    }
    li->final = no;                 // atualiza o final
    li->qtd++;
    return 1;
}

int remove_inicio(Lista *li) {
    if (lista_vazia(li)) 
        return 0;
    Elem *no_inicio = li->final->prox;   // primeiro nó

    if (no_inicio == li->final) {        // só 1 nó
        li->final = NULL;
    } else {
        li->final->prox = no_inicio->prox;  // pula o primeiro
    }
    free(no_inicio);
    li->qtd--;
    return 1;
}

int remove_final(Lista *li){
    if (lista_vazia(li))
        return 0;  

    Elem *no_final = li->final;
    Elem *no_inicio = no_final->prox;

    // Caso 1: apenas 1 nó
    if (no_final == no_inicio){
        li->final = NULL;
    }
    // Caso 2: mais de um nó
    else {
        Elem *aux = no_inicio;
        while (aux->prox != no_final)  // percorre até o penúltimo
            aux = aux->prox;

        aux->prox = no_inicio;          // novo último aponta pro início
        li->final = aux;             // atualiza descritor
    }

    free(no_final);                  // único free
    li->qtd--;                     // único decremento
    return 1;
}

void libera_lista(Lista *li){
    if(li == NULL) 
        return;

    if(li->final == NULL){  // lista vazia
        free(li);
        return;
    }

    Elem *no_inicio = li->final->prox;
    Elem *no_aux = no_inicio;

    while(no_aux->prox != no_inicio){
        Elem *no_prox = no_aux->prox;
        free(no_aux);
        no_aux = no_prox;
    }

    free(no_aux);  // último nó
    free(li);
}

int main() {
    Lista *li = cria_lista();
    insere_final(li, 10);
    insere_final(li, 20);
    insere_final(li, 30);

    printf("Tamanho: %d\n", tamanho_lista(li)); 

    remove_inicio(li);

    libera_lista(li);
    return 0;
}