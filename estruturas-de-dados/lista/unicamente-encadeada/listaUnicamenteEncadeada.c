#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento *prox;
};
typedef struct elemento Elem;   // apelido para o nó
typedef Elem* Lista;            // Lista é um ponteiro para nó

Lista* cria_lista(){
    Lista* li = malloc(sizeof(Lista)); // aloca espaço para 1 ponteiro
    if(li != NULL) 
        *li = NULL;                  // lista começa vazia
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while(*li != NULL){
            no = *li;
            *li = no->prox;
            free(no);
        }
        free(li);
    }
}

// retorna 1 se vazia, 0 caso contrário
int lista_vazia(Lista* li){
    if(li == NULL || *li == NULL) 
        return 1;   // lista vazia
    return 0;
}

// conta nós
int tamanho_lista(Lista* li){
    if(li == NULL) 
        return -1;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int insere_inicio(Lista* li, int dado){
    if(li == NULL) 
        return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) 
        return 0;
    no->dado = dado;
    no->prox = *li;
    *li = no;
    return 1;
}

// insere no final (O(n) sem ponteiro para cauda)
int insere_final(Lista* li, int dado){
    if(li == NULL) 
        return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) 
        return 0;
    no->dado = dado;
    no->prox = NULL;

    if(*li == NULL){            // lista vazia
        *li = no;
        return 1;
    }
    Elem* aux = *li;
    while(aux->prox != NULL)    // caminha até o último
        aux = aux->prox;
    aux->prox = no;
    return 1;
}

int remove_inicio(Lista* li){
    if(li == NULL || *li == NULL) 
        return 0; // vazia
    Elem* no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

// remove no final (O(n) sem cauda)
int remove_final(Lista* li){
    if(li == NULL || *li == NULL) 
        return 0; // vazia

    Elem *ant, *no = *li;

    // caso especial: só 1 nó
    if(no->prox == NULL){
        free(no);
        *li = NULL;
        return 1;
    }

    // caminha até o último, guardando o anterior
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    ant->prox = NULL;
    free(no);
    return 1;
}

int main(){
    Lista* li = cria_lista();
    if(li == NULL){
        printf("Falha ao criar lista.\n");
        return 1;
    }

    insere_inicio(li, 10);
    insere_inicio(li, 20);
    insere_final(li, 30);
    insere_final(li, 40);

    printf("Tamanho: %d\n", tamanho_lista(li));

    remove_inicio(li);
    remove_final(li); 

    int vazia = lista_vazia(li);
    printf("Lista %s\n", vazia ? "vazia" : "NAO vazia");

    libera_lista(li);
    return 0;
}