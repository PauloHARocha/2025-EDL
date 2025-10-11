#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct descritor {
    Elem *inicio;   // ponteiro para o primeiro nó
    int qtd;        // quantidade de nós
};
typedef struct descritor Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->qtd = 0;            // inicia contador
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem *no = li->inicio;
        while(no != NULL){
            Elem *prox = no->prox;
            free(no);
            no = prox;
        }
        free(li);
    }
}

int lista_vazia(Lista* li){
    return (li == NULL || li->inicio == NULL);
}

int tamanho_lista(Lista* li){ // (ALTERADO) agora O(1)
    if(li == NULL) return -1;
    return li->qtd;             
}

int insere_inicio(Lista* li, int dado){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dado = dado;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;                  
    return 1;
}

int insere_final(Lista* li, int dado){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dado = dado;
    no->prox = NULL;

    if(li->inicio == NULL){     // lista vazia
        li->inicio = no;
        li->qtd++;             
        return 1;
    }

    Elem *aux = li->inicio;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = no;
    li->qtd++;                  
    return 1;
}

int remove_inicio(Lista* li){
    if(li == NULL || li->inicio == NULL) return 0;
    Elem *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    li->qtd--;                  
    return 1;
}

int remove_final(Lista* li){
    if(li == NULL || li->inicio == NULL) return 0;

    Elem *no = li->inicio, *ant = NULL;

    if(no->prox == NULL){       // só 1 nó
        li->inicio = NULL;
        free(no);
        li->qtd--;              
        return 1;
    }

    while(no->prox != NULL){
        ant = no;
        no  = no->prox;
    }
    ant->prox = NULL;
    free(no);
    li->qtd--;                 
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

    printf("Tamanho: %d\n", tamanho_lista(li));   // O(1) agora

    remove_inicio(li);
    remove_final(li);

    printf("Lista %s\n", lista_vazia(li) ? "vazia" : "NAO vazia");

    libera_lista(li);
    return 0;
}