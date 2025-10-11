#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento *ant;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct descritor {
    Elem *inicio;
    Elem *final;
    int qtd;
};
typedef struct descritor Lista;

Lista* cria_lista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li){
        li->inicio = NULL;
        li->final  = NULL;
        li->qtd    = 0;
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

int lista_vazia(Lista *li){
    return (li == NULL || li->qtd == 0);
}

int tamanho_lista(Lista *li){
    if(li == NULL) 
        return -1;
    return li->qtd; // O(1)
}

int insere_inicio(Lista *li, int x){
    if(li == NULL) 
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) 
        return 0;

    no->dado = x;
    no->prox = li->inicio;
    no->ant  = NULL;

    if(li->inicio != NULL)
        li->inicio->ant = no;
    else
        li->final = no;

    li->inicio = no;
    li->qtd++;
    return 1;
}

int insere_final(Lista *li, int x){
    if(li == NULL) 
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) 
        return 0;

    no->dado = x;
    no->prox = NULL;
    no->ant = li->final;

    if(li->final != NULL)
        li->final->prox = no;
    else
        li->inicio = no;

    li->final = no;
    li->qtd++;
    return 1;
}

int remove_inicio(Lista *li){
    if(li == NULL || li->inicio == NULL) 
        return 0;

    Elem *no = li->inicio;
    li->inicio = no->prox;

    if(li->inicio != NULL)
        li->inicio->ant = NULL;
    else
        li->final = NULL; // ficou vazia

    free(no);
    li->qtd--;
    return 1;
}

int remove_final(Lista *li){
    if(li == NULL || li->final == NULL) 
        return 0;

    Elem *no = li->final;
    li->final = no->ant;

    if(li->final != NULL)
        li->final->prox = NULL;
    else
        li->inicio = NULL; // ficou vazia

    free(no);
    li->qtd--;
    return 1;
}

int main(){
    Lista *li = cria_lista();

    insere_inicio(li, 20);
    insere_inicio(li, 10);
    insere_final (li, 30);
    insere_final (li, 40);

    printf("Tamanho: = %d\n", tamanho_lista(li));

    remove_inicio(li);   
    remove_final (li);   
    printf("Tamanho: = %d\n", tamanho_lista(li));

    libera_lista(li);
    return 0;
}